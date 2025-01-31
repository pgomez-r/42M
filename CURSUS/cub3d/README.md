# cub3d

cub3D is a 3D graphical representation of a maze from a first-person perspective, implemented using Ray-Casting principles. It is built using C and miniLibX, providing a simple yet interactive experience similar to early 3D games.

## Features

- Raycasting-based 3D rendering.
- Supports different wall textures for North, South, East, and West walls.
- Configurable floor and ceiling colors.
- Interactive controls:
  - W, A, S, D: Move through the maze.
  - Left/Right Arrow Keys: Rotate the view.
  - ESC: Exit the program.
  - Clicking the close button: Closes the window cleanly.
- Reads a .cub configuration file to define the map and textures.
- Ensures the map is valid (closed by walls, correct element formatting, etc.).

*(Bonus)*
- Wall collisions.
- A minimap system.
- Animated sprites.
- Rotate the point of view with the mouse.

## Installation

### Prerequisites

- GCC or Clang compiler
- Make
- miniLibX (must be installed on the system or built from sources)
- Math Library (-lm)

### Build

Clone the repository and compile the program:

```sh
make
```

This will generate the cub3D executable.

To clean up object files:
```sh
make clean
```

To remove binaries and object files:
```sh
make fclean
```

To recompile everything:
```sh
make re
```

### Usage

Run the program with a valid .cub map file
```
./cub3d maps/sample_map.cub
```

**Map File Format**
A .cub file consists of:

*Wall Textures*: Paths to texture files.
*Floor and Ceiling Colors*: RGB values separated by commas (124,0,212)
*The Map*: '1' for walls, '0' for empty space, "N/S/E/W" for player spawn direction

*Example of a valid .cub File*
```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100101
101001
1100N1
111111
```

**Error Handling**
If any misconfiguration is detected in the .cub file, the program will exit with an error message

### External Functions Used

Standard C functions: open, close, read, write, printf, malloc, free, perror, strerror, exit.
Math Library (-lm): All math functions.
miniLibX: Used for rendering graphics and handling user input.

### License

This project follows the 42 School project guidelines.