#!/bin/bash -e

files=$(find src -name "*.c")
flags="-Wall -Wextra -Wno-unused-parameter -Werror -lm -g"

mkdir debug -p
gcc $files $flags -o debug/lania

./debug/lania