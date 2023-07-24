# conwaysGameOfLife
This program simulates the Game of Life on a virtual 2D grid. The simulation uses a framebuffer to represent the grid, and each cell in the grid can be in one of two states: alive or dead. The simulation follows the rules of the Game of Life:

- Any live cell with fewer than two live neighbors dies (underpopulation).
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies (overpopulation).
Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

The simulation is initialized with a random pattern of cells, and then it updates the grid following the Game of Life rules. The grid is displayed in a window using the SDL library.

<p align="center">
  <br>
  <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExdWlmYW54aHViNXB0ajVlc3N6cGtrdW1yYXc0ODAyMnd0NXg5YXAyeSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/VFxDVW36CMiM3G1ctB/giphy.gif" alt="pic" width="500">
  <br>
</p>

<p align="center" >
  <a href="#Files">Files</a> •
  <a href="#Features">Features</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

## Files

- configure.sh: A shell script to set up the project dependencies and environment.
- build.sh: A shell script to build the project using CMake.
- run.sh: A shell script to execute the compiled graphics application.
- clean.sh: A shell script to clean up build artifacts and generated files.
- : A directory containing the source code files for the graphics application.
  - colors.h: Header file that defines the Color struct and functions for manipulating colors in the application.
  - framebuffer.h: Header file containing the framebuffer and functions for drawing and filling polygons.
  - point.h: Header file defining the Vertex struct, representing a vertex in a polygon.
  - main.cpp: The main C++ source file that implements the graphics application.
- CMakeLists.txt: The CMake configuration file that manages the build process.

## Features
The main features of the graphics application include:

- Framebuffer: The application uses a framebuffer, defined in framebuffer.h, to represent a virtual screen. The framebuffer allows manipulation and display of colors on the screen.
- Color Manipulation: The colors.h file defines the Color struct, representing an RGB color. It provides functionality to create colors, perform arithmetic operations (addition and multiplication), and clamp color values within a specified range.
- Polygon Drawing: The application can draw and fill polygons on the virtual screen using the framebuffer.h functions.
- Shell Scripts: The project includes convenient shell scripts (configure.sh, build.sh, run.sh, and clean.sh) to set up the environment, build the project, run the application, and clean up build artifacts, respectively.

These features enable the creation and rendering of graphical elements using a framebuffer approach, making it suitable for various computer graphics applications and projects.

## How To Use
To clone and run this application, you'll need [wsl](https://learn.microsoft.com/en-us/windows/wsl/install) and the following tools installed on it: [Git](https://git-scm.com), [C++ compiler](https://www.fdi.ucm.es/profesor/luis/fp/devtools/mingw.html), [CMake](https://cmake.org/download/), [Make](https://linuxhint.com/install-make-ubuntu/) and [SDL2](https://www.oreilly.com/library/view/rust-programming-by/9781788390637/386c15eb-41b2-41b4-bd65-154a750a58d8.xhtml). From your command line:

```bash
# Clone this repository
$ git clone https://github.com/bl33h/conwaysGameOfLife

# Give execution permissions
$ chmod +x configure.sh
$ chmod +x build.sh
$ chmod +x run.sh

# Run the app
$ ./run.sh
```
