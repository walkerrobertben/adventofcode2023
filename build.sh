#!/bin/bash
COMPILER=clang++
STD=c++11
OUTPUT=aoc
FILES="main.cpp"
LIB="lib"

for FILE in solutions/*/*.cpp; do
    FILES="$FILES $FILE"
done

for FILE in lib/*/*.cpp; do
    FILES="$FILES $FILE"
done

CMD="$COMPILER -std=$STD -I$LIB -o $OUTPUT $FILES"
echo $CMD
eval $CMD
