# Optional synthesis/physical-design target with OpenROAD flow scripts.
FROM openroad/orfs:26Q1-534-g510137693 AS synth

ENV DEBIAN_FRONTEND=noninteractive \
    PYTHONUNBUFFERED=1 \
    PYTHONDONTWRITEBYTECODE=1 \
    WORKSPACE_ROOT=/workspace \
    PYTHONPATH=/opt/lab

RUN apt-get update && apt-get install -y --no-install-recommends \
    bash \
    build-essential \
    ca-certificates \
    cmake \
    curl \
    flex \
    bison \
    git \
    gtkwave \
    iverilog \
    jq \
    make \
    ninja-build \
    pkg-config \
    python3 \
    python3-pip \
    python3-venv \
    tcl \
    verilator \
    wget \
    xxd \
    yosys \
    && rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install --no-cache-dir mcp

COPY lab/ /opt/lab/
RUN python3 -m pip install --no-cache-dir -r /opt/lab/requirements.txt

WORKDIR /workspace
RUN mkdir -p /workspace/reports /workspace/logs /workspace/submissions

EXPOSE 8080
CMD ["bash"]

# Keep the autograder base so it stays with the grading image students already debug against.
FROM gradescope/autograder-base:ubuntu-22.04 AS final

ENV DEBIAN_FRONTEND=noninteractive \
    PYTHONUNBUFFERED=1 \
    PYTHONDONTWRITEBYTECODE=1 \
    WORKSPACE_ROOT=/workspace \
    PYTHONPATH=/opt/lab

RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    verilator \
    iverilog \
    make \
    bash \
    xxd \
    wget \
    curl \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install --no-cache-dir mcp

COPY lab/ /opt/lab/
RUN python3 -m pip install --no-cache-dir -r /opt/lab/requirements.txt

WORKDIR /workspace
RUN mkdir -p /workspace/reports /workspace/logs /workspace/submissions

EXPOSE 8080
CMD ["bash"]
