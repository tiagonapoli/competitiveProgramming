#!/bin/bash

set -euo pipefail

if [ ! -f "./sha.out" ]; then
	touch ./sha.out
fi

if [ -f $1 ]; then
	SHA=$(shasum $1)
	PRESHA=$(cat sha.out)
	if [ "$SHA" != "$PRESHA" ]; then
		echo "=== Files differ from before, compiling ==="
		echo "g++ $1"
		g++ $1
		echo "$(shasum $1)" > sha.out
	fi
	echo "=== Execute ==="
	./a.out
else 
	echo "File doesn't exist"
fi

