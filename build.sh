#!/bin/bash
COMPILER=clang++
STD=c++11
OUTPUT=aoc
FILES="main.cpp"

for FILE in solutions/*/*.cpp; do
    FILES="$FILES $FILE"
done

echo "$COMPILER -std=$STD -o $OUTPUT $FILES"
$COMPILER -std=$STD -o $OUTPUT $FILES
