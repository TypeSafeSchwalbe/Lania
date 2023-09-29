#!/bin/bash -e

files=$(find src -name "*.c")
flags="-Wall -Wextra -Wno-unused-parameter -Wno-unused-variable -Werror -lm -g"

mkdir debug -p
gcc $files $flags -o debug/lania

./debug/lania