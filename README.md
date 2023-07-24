# conwaysGameOfLife
A

<p align="center">
  <br>
  <img src="https://i.imgur.com/RBVSbre.mp4g" alt="pic" width="500">
  <br>
</p>
<p align="center" >
  <a href="#Files">Files</a> •
  <a href="#Features">Features</a> •
  <a href="#how-to-use">How To Use</a> 
</p>

## Files

- configure.sh:
- build.sh:
- run.sh:
- clean.sh:
- src: the file that implements de solution.
  - colors.h: defines the Color struct and related functions for manipulating colors.
  - framebuffer.h: contains the framebuffer and related functions for drawing and filling polygons.
  - point.h: defines the vert struct representing a vertex in a polygon.
  - main.cpp: 
- CMakeLists.txt: the CMake configuration.

## Features


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
