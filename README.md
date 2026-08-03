# Testbench Environment

This folder provides a reproducible Docker environment for student RTL work, local testbenching, and optional MCP-assisted verification.

The default image stays aligned with the class autograder stack for Verilator and Icarus Verilog parity. A separate optional `synth` build stage exists for OpenROAD / ORFS flows when you want physical-design experiments.

## What students should do

Students should not clone the image itself. They should either:

1. build the image locally from this Dockerfile, or
2. pull a published tag if you choose to push one to a registry later.

In both cases, the important step is to mount their project workspace into the container and work there.

## Build the image

Build the default, autograder-aligned image:

```bash
docker build --target final -t comparch-testbench:latest -f testbenchenvironment/Dockerfile testbenchenvironment
```

If you want the optional OpenROAD / ORFS synthesis image:

```bash
docker build --target synth -t comparch-testbench-synth:latest -f testbenchenvironment/Dockerfile testbenchenvironment
```

## Run the container

Mount the student workspace into `/workspace`:

```bash
docker run --rm -it \
  -v "$PWD:/workspace" \
  -w /workspace \
  comparch-testbench:latest \
  bash
```

For synthesis-oriented work, swap the image name:

```bash
docker run --rm -it \
  -v "$PWD:/workspace" \
  -w /workspace \
  comparch-testbench-synth:latest \
  bash
```

## Suggested student workflow

From inside the container, students should:

1. keep their RTL in a `submission/` or `rtl/` directory,
2. put new self-checking testbenches in `testbenches/`,
3. run Verilator or Icarus locally,
4. inspect failing traces with waveform dumps and logs,
5. iterate until the tests pass.

For the `Binarytesting` layout, the existing Makefile already supports a simple loop:

```bash
make help
make list-testbenches
make tb TB=ALU_tb
make test
```

That makes it easy to add a new `testbenches/<name>.v` file and run it without changing the grading infrastructure.

## Using MCP for verification support

The container includes a small MCP server helper at `/opt/lab/mcp_server.py`.

Run it directly inside the container:

```bash
python3 /opt/lab/mcp_server.py
```

It exposes tools for:

- checking what EDA tools are installed,
- listing files in the mounted workspace,
- running `make` targets,
- running OpenROAD scripts in the synthesis image,
- collecting metrics from reports and logs.

The main idea is to let the model help with specification review, debug, and validation, not to hardcode answers into the image.

## Example MCP client setup

For a local MCP client, point the command at the containerized server. The exact config format depends on the client, but the core command is:

```bash
docker run --rm -i \
  -v "$PWD:/workspace" \
  -w /workspace \
  comparch-testbench:latest \
  python3 /opt/lab/mcp_server.py
```

If you want the model to inspect the workspace, run make targets, or summarize report metrics, use the MCP tools instead of embedding solutions in the testbench.

## Keeping it honest

To avoid hardcoding answers:

- keep hidden grading tests private,
- make public testbenches only assert the intended interface and behavior,
- use waveform/debug tools to diagnose failures,
- use the MCP server as an assistant for review and verification, not as a source of fixed outputs.

A good student testbench should check behavior from the spec, not depend on internal implementation details.

## Notes

The default image is intentionally close to the grading environment so students can reproduce Verilator behavior locally.
The `synth` stage is for optional OpenROAD / ORFS experiments and is not required for ordinary RTL debugging.
