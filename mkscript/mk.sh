#!/bin/bash

DEBUG_MODE=false
if [ ! -z "$2" ] && [ "$2" == "d" ]; then
	DEBUG_MODE=true
fi

set -euo pipefail

SHA_FILE="./sha.tmp"
DEBUG_SHA_FILE="./debug_sha.tmp"
DIFFER_MESSAGE="=== Files differ from before, compiling ==="
COMPILE_ARGS="-Wall -std=c++17"

if [ "$DEBUG_MODE" == "true" ]; then
	rm -f $SHA_FILE
	SHA_FILE=$DEBUG_SHA_FILE
	DIFFER_MESSAGE="=== Files differ from before, compiling in DEBUG MODE ==="
	COMPILE_ARGS="$COMPILE_ARGS -D DEBUG"
else 
	rm -f $DEBUG_SHA_FILE
fi



if [ ! -f "$SHA_FILE" ]; then
	touch "$SHA_FILE"
fi

if [ -f $1 ]; then
	SHA=$(shasum $1)
	PRESHA=$(cat "$SHA_FILE")
	if [ "$SHA" != "$PRESHA" ]; then
		echo $DIFFER_MESSAGE
		echo "g++ $COMPILE_ARGS $1"
		g++ $COMPILE_ARGS $1
		echo "$(shasum $1)" > "$SHA_FILE"
	fi
	echo "=== Execute ==="
	./a.out
else 
	echo "File doesn't exist"
fi

