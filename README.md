# Lania
*A 2d top-down turn-based strategy terminal game written from scratch in C.*

# How to play

Download the pre-built release binary for your platform.  
If you have a C compiler installed, you may instead also clone the repository and compile all the `.c`-files in the `src`-directory.  
If you also happen to use Linux, you may also just simply run `run.sh` (by running `chmod +x ./run.sh` and then `./run.sh`, or by running `bash -e run.sh`) (this will use `gcc`).  

The downloaded or compiled executable must be started in a terminal of your choice. Although slow because of the coloring, the Windows command prompt and Windows PowerShell were proven to work as well. Only 3-bit coloring (background and foreground) with ANSI escape sequences is used, meaning it is compatible with a wide range of terminals.

During execution, the game will create a file called `savegame` in the current working directory. It does what it says, storing the progress you made in the game. Delete this file to reset your progress.

# Screenshots

*(Taken on Fedora Linux in the GNOME terminal)*

![Battle of Abil](./screenshots/battle_of_abil.png)
![Endless Desert](./screenshots/endless_desert.png)
![Enchanted Lake](./screenshots/enchanted_lake.png)
![Narrow River Fords](./screenshots/narrow_river_fords.png)
![Western Oasis](./screenshots/western_oasis.png)
