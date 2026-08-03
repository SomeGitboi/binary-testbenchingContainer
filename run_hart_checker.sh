#!/usr/bin/env bash
set -euo pipefail

TOOL_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT="$(cd "$TOOL_DIR/.." && pwd)"
MODE="submission"
SEED="12345"
PHASE="project3"
RTL_DIR="$TOOL_DIR/submission"
CONTRACT_FILE="$TOOL_DIR/singlehartstudent.v"
OBJ_DIR="$TOOL_DIR/obj_dir"
OUTPUT_BIN=""
STRIP_OUTPUT=0

usage() {
  cat <<EOF
Usage: $0 [--mode submission|reference|file] [--base-dir DIR] [--rtl-dir DIR] [--rtl-file FILE] [--contract-file FILE] [--output-bin FILE] [--strip] [--phase project3] [--seed N]

Modes:
  submission  Build every .v file in ./submission next to this script. This is the student-DUT path.
  reference   Build the private reference single-cycle hart.
  file        Build one complete standalone hart implementation. Do not use this for the empty contract shell.

Contract:
  singlehartstudent.v is treated as the public interface/template. It is not compiled as the DUT
  unless you explicitly pass it with --rtl-file, and an empty shell will fail because it has no CPU.

Student location:
  --base-dir DIR sets the student package root and uses DIR/submission/*.v.
  --rtl-dir DIR directly points at the flat directory containing submitted .v files.

Project 3 adapter rules:
  single-cycle hart, RESET_ADDR=0, retire every cycle, combinational imem/dmem reads,
  synchronous masked dmem writes, RV32I architectural comparison.
EOF
}

RTL_FILE=""
while [[ $# -gt 0 ]]; do
  case "$1" in
    --mode)
      MODE="$2"
      shift 2
      ;;
    --rtl-dir)
      RTL_DIR="$2"
      shift 2
      ;;
    --base-dir)
      RTL_DIR="$2/submission"
      CONTRACT_FILE="$2/singlehartstudent.v"
      OBJ_DIR="$2/obj_dir"
      shift 2
      ;;
    --rtl-file)
      RTL_FILE="$2"
      MODE="file"
      shift 2
      ;;
    --output-bin)
      OUTPUT_BIN="$2"
      shift 2
      ;;
    --strip)
      STRIP_OUTPUT=1
      shift
      ;;
    --contract-file)
      CONTRACT_FILE="$2"
      shift 2
      ;;
    --phase)
      PHASE="$2"
      shift 2
      ;;
    --seed)
      SEED="$2"
      shift 2
      ;;
    -h|--help)
      usage
      exit 0
      ;;
    *)
      SEED="$1"
      shift
      ;;
  esac
done

if [[ "$PHASE" != "project3" ]]; then
  echo "Unsupported phase adapter: $PHASE" >&2
  exit 2
fi

RTL_FILES=()
case "$MODE" in
  submission)
    if [[ ! -d "$RTL_DIR" ]]; then
      echo "Submission RTL directory not found: $RTL_DIR" >&2
      exit 2
    fi
    while IFS= read -r file; do
      RTL_FILES+=("$file")
    done < <(find "$RTL_DIR" -maxdepth 1 -type f -name '*.v' | sort)
    ;;
  reference)
    RTL_FILES=(
      "$ROOT/552-grading-server/reference/single_cycle/hart.v"
      "$ROOT/552-grading-server/reference/single_cycle/rf.v"
      "$ROOT/552-grading-server/reference/single_cycle/decode.v"
      "$ROOT/552-grading-server/reference/single_cycle/alu.v"
    )
    ;;
  file)
    if [[ -z "$RTL_FILE" || ! -f "$RTL_FILE" ]]; then
      echo "RTL file not found: ${RTL_FILE:-<empty>}" >&2
      exit 2
    fi
    if [[ "$(realpath "$RTL_FILE")" == "$(realpath "$CONTRACT_FILE")" ]]; then
      echo "Refusing to run the contract shell as the DUT: $RTL_FILE" >&2
      echo "Use --mode submission so the checker builds Binarytesting/submission/*.v instead." >&2
      exit 2
    fi
    RTL_FILES=("$RTL_FILE")
    ;;
  *)
    echo "Unsupported mode: $MODE" >&2
    usage >&2
    exit 2
    ;;
esac

if [[ ${#RTL_FILES[@]} -eq 0 ]]; then
  echo "No Verilog files found for mode '$MODE'." >&2
  exit 2
fi

echo "Phase adapter: $PHASE"
echo "RTL mode: $MODE"
echo "Contract file: $CONTRACT_FILE (not compiled as DUT)"
printf '  %s\n' "${RTL_FILES[@]}"

verilator --cc \
  --exe \
  --build \
  --top-module hart \
  -Wno-WIDTHEXPAND \
  -Wno-WIDTHTRUNC \
  -Mdir "$OBJ_DIR" \
  "${RTL_FILES[@]}" \
  "$ROOT/Binarytesting/script.cpp"

"$OBJ_DIR/Vhart" "$SEED"

if [[ -n "$OUTPUT_BIN" ]]; then
  cp "$OBJ_DIR/Vhart" "$OUTPUT_BIN"
  chmod +x "$OUTPUT_BIN"
  if [[ "$STRIP_OUTPUT" -eq 1 ]]; then
    strip "$OUTPUT_BIN"
  fi
  echo "Wrote checker binary: $OUTPUT_BIN"
fi
