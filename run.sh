
mkdir debug > /dev/null 2>&1

gcc -Wextra \
        ./src/*.c \
        ./src/engine/*.c \
        ./src/stages/*.c \
        ./src/stages/content/nature/*.c \
        ./src/stages/content/humans/*.c \
        ./src/stages/content/goblins/*.c \
        ./src/stages/content/goblins/commanders/*.c \
        ./src/actions/*.c \
    -o debug/lania -lm -g &&
./debug/lania