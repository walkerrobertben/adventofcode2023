#!/bin/bash
COMPILER=clang++
OUTPUT=aoc
FILES="main.cpp"

for FILE in solutions/*/*.cpp; do
    FILES="$FILES $FILE"
done

echo "$COMPILER -o $OUTPUT $FILES"
$COMPILER -o $OUTPUT $FILES
