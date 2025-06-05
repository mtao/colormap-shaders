#!/bin/bash

SHADERS="metal:metal
glsl:frag"

NCPUs=$( lscpu -J | jq '.lscpu[] | select( .field == "CPU(s):" ) | .data' -r )
#NCPUs=$(sysctl -n hw.ncpu)
(
	cd "$(dirname "$0")/../src"
	for SHADER in $SHADERS; do
		TYPE=$(echo $SHADER | cut -d: -f1)
		EXT=$(echo $SHADER | cut -d: -f2)
		mkdir -p "../shaders/$TYPE"
		find . -name '*\.txt' | xargs -I{} -L 1 -P ${NCPUs} bash -c "../tool/transcode/${TYPE}.sh {} ../shaders/$TYPE/\$(basename {} | cut -d. -f1).${EXT}"
	done
)
