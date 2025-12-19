#!/bin/bash

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TESTER_EXECUTABLE="$SCRIPT_DIR/../dotnet-tester/bin/Debug/net10.0/dotnet-tester"

if [ ! -f "$TESTER_EXECUTABLE" ]; then
    echo "Error: Tester executable not found at $TESTER_EXECUTABLE"
    echo "Please build the dotnet-tester project first."
    exit 1
fi

if [ $# -lt 1 ]; then
    echo "Usage: tester.sh <path-to-cpp-file> [options]"
    echo "Options:"
    echo "  -n, --runs <count>      Number of runs (default: 1)"
    echo "  -t, --threads <count>   Number of threads (default: 1)"
    echo "  -v, --verbose           Show input and output for each run"
    exit 1
fi

"$TESTER_EXECUTABLE" "$@"
