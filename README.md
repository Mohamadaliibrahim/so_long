Here's a `README.md` template for your `so_long` project at 42 School. You can customize it further based on your specific implementation details.

---

# so_long

`so_long` is a project at 42 School where you create a small 2D game using the MinilibX library. The player can move around a map, collect items, and reach the exit.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Controls](#controls)
- [Game Objectives](#game-objectives)
- [Map Requirements](#map-requirements)
- [Project Structure](#project-structure)
- [Norminette Compliance](#norminette-compliance)
- [Resources](#resources)

## Installation

### Prerequisites

- You need to have the `MinilibX` library installed. If it's not installed, you can download and set it up as follows:

```bash
git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make
```

- Make sure to link the `mlx` library when compiling the project. The compilation flags are provided in the Makefile.

### Clone the Repository

```bash
git clone git@github.com:Mohamadaliibrahim/so_long.git
cd so_long
```

### Compile the Game

```bash
make
```

This will compile the game and generate the `so_long` executable.

## Usage

To start the game, run the following command:

```bash
./so_long path_to_map/map_file.ber
```

Replace `path_to_map/map_file.ber` with the actual path to your map file.

## Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **up arow**: Move up
- **left arow**: Move left
- **down arow**: Move down
- **right arow**: Move right
- **ESC**: Exit the game
- **q** : Exit the game

## Game Objectives

- Collect all the collectables (`C`) on the map.
- Reach the exit (`E`) after collecting all the items.
- Avoid getting stuck or trapped in the map.

## Map Requirements

- The map must be rectangular and surrounded by walls (`1`).
- The map must contain at least one player start position (`P`), one exit (`E`), and one collectable (`C`).
- Valid characters in the map are: `1`, `0`, `C`, `P`, and `E`.

## Edge cases

- If the player is stucked by wall the map will not open!
- If the player cant reach all collectables the game will not open!
- If the player cant reach the exit door the game will not open!

## Project Structure

- **src/**: Contains the source code files.
- **includes/**: Contains the header files.
- **maps/**: Contains example map files.
- **Makefile**: Used to compile the project.
- **README.md**: This file.

## Norminette Compliance

This project adheres to the 42 School's Norminette standards. All functions have been split into smaller functions, and the code has been refactored to meet the required line limits and argument counts.


### Author

This project was developed by **mohamibr** as part of the 42 school curriculum.
