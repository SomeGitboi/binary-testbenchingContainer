from __future__ import annotations

import os
import re
import shutil
import subprocess
from pathlib import Path
from typing import Any

from mcp.server.fastmcp import FastMCP

mcp = FastMCP("hardware-testbench")
WORKSPACE_ROOT = Path(os.environ.get("WORKSPACE_ROOT", "/workspace")).resolve()
TEXT_FILE_SUFFIXES = {".log", ".rpt", ".report", ".txt", ".json", ".tcl", ".sv", ".v", ".vh"}


def _resolve_path(path: str | os.PathLike[str]) -> Path:
    candidate = Path(path)
    if not candidate.is_absolute():
        candidate = WORKSPACE_ROOT / candidate
    return candidate.resolve()


def _run_command(command: list[str], cwd: Path | None = None, timeout: int = 3600) -> dict[str, Any]:
    workdir = cwd or WORKSPACE_ROOT
    completed = subprocess.run(
        command,
        cwd=workdir,
        capture_output=True,
        text=True,
        timeout=timeout,
        check=False,
    )
    return {
        "command": command,
        "cwd": str(workdir),
        "returncode": completed.returncode,
        "stdout": completed.stdout,
        "stderr": completed.stderr,
    }


def _available_tools() -> dict[str, str | None]:
    executables = ["openroad", "yosys", "verilator", "iverilog", "make", "python3", "gtkwave"]
    return {name: shutil.which(name) for name in executables}


def _parse_metrics_text(text: str) -> dict[str, Any]:
    metrics: dict[str, Any] = {}

    patterns = {
        "cycle_count": [r"cycle count\s*[:=]\s*([0-9]+)", r"cycles\s*[:=]\s*([0-9]+)"],
        "ipc": [r"ipc\s*[:=]\s*([0-9]*\.?[0-9]+)"],
        "frequency_mhz": [r"frequency\s*[:=]\s*([0-9]*\.?[0-9]+)\s*mhz", r"fmax\s*[:=]\s*([0-9]*\.?[0-9]+)\s*mhz"],
        "area_mm2": [r"area\s*[:=]\s*([0-9]*\.?[0-9]+)\s*mm\^?2", r"area\s*[:=]\s*([0-9]*\.?[0-9]+)\s*um\^?2"],
        "power_mw": [r"power\s*[:=]\s*([0-9]*\.?[0-9]+)\s*mw"],
    }

    for key, regexes in patterns.items():
        for pattern in regexes:
            match = re.search(pattern, text, flags=re.IGNORECASE)
            if not match:
                continue
            value = float(match.group(1)) if "." in match.group(1) else int(match.group(1))
            if key == "area_mm2" and "um" in pattern:
                value = float(value) / 1_000_000.0
            metrics[key] = value
            break

    return metrics


def _scan_metrics(root: Path) -> dict[str, Any]:
    discovered: dict[str, Any] = {"metrics": {}, "sources": []}
    for path in root.rglob("*"):
        if not path.is_file():
            continue
        if path.suffix.lower() not in TEXT_FILE_SUFFIXES:
            continue
        try:
            text = path.read_text(errors="ignore")
        except OSError:
            continue
        metrics = _parse_metrics_text(text)
        if metrics:
            discovered["sources"].append(str(path.relative_to(root)))
            discovered["metrics"].update(metrics)
    return discovered


@mcp.tool()
def environment_status() -> dict[str, Any]:
    """Report the installed EDA tools and the default workspace location."""

    return {
        "workspace_root": str(WORKSPACE_ROOT),
        "tools": _available_tools(),
    }


@mcp.tool()
def list_workspace_files(path: str = ".", max_depth: int = 2) -> dict[str, Any]:
    """List files under the workspace so an LLM can inspect the design tree."""

    root = _resolve_path(path)
    items: list[str] = []
    if not root.exists():
        return {"path": str(root), "exists": False, "items": items}

    for entry in sorted(root.rglob("*")):
        if not entry.is_file():
            continue
        try:
            relative = entry.relative_to(root)
        except ValueError:
            continue
        if len(relative.parts) <= max_depth + 1:
            items.append(str(relative))
    return {"path": str(root), "exists": True, "items": items}


@mcp.tool()
def run_make(target: str = "help", path: str = ".", timeout: int = 3600) -> dict[str, Any]:
    """Run make inside the workspace and capture stdout/stderr for debugging."""

    root = _resolve_path(path)
    return _run_command(["make", target], cwd=root, timeout=timeout)


@mcp.tool()
def run_openroad(script: str, path: str = ".", timeout: int = 3600) -> dict[str, Any]:
    """Execute an OpenROAD Tcl script from the workspace."""

    if shutil.which("openroad") is None:
        return {
            "command": ["openroad", "-exit", script],
            "cwd": str(_resolve_path(path)),
            "returncode": 127,
            "stdout": "",
            "stderr": "openroad is not installed in this image; build the synth target for physical-design runs.",
        }

    root = _resolve_path(path)
    script_path = _resolve_path(script)
    return _run_command(["openroad", "-exit", str(script_path)], cwd=root, timeout=timeout)


@mcp.tool()
def collect_metrics(path: str = ".") -> dict[str, Any]:
    """Search reports for cycle count, IPC, frequency, area, and power values."""

    root = _resolve_path(path)
    if not root.exists():
        return {"path": str(root), "exists": False, "metrics": {}, "sources": []}
    result = _scan_metrics(root)
    result["path"] = str(root)
    result["exists"] = True
    return result


if __name__ == "__main__":
    mcp.run()
