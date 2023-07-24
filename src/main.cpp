/*---------------------------------------------------------------------------
Copyright (C), 2022-2023, Sara Echeverria (bl33h)
@author Sara Echeverria
FileName: main.cpp
@version: I
Creation: 21/07/2023
Last modification: 24/07/2023
------------------------------------------------------------------------------*/
#include "framebuffer.h"
#include <SDL2/SDL.h>
#include "colors.h"
#include <cstdlib>
#include "point.h"
#include <vector>


constexpr size_t BOARD_WIDTH = 200;
constexpr size_t BOARD_HEIGHT = 200;

int frameCount = 0;
int framesPerColorChange = 20;
bool useCellColor1 = true;

std::vector<std::vector<bool>> board(BOARD_WIDTH, std::vector<bool>(BOARD_HEIGHT, false));
Color cellColor(156, 114, 255);
Color cellColor2(0, 153, 153);
Color backgroundColor(255, 255, 255);

// Function to count the number of live neighbors for a given cell
int liveNeighbors(int x, int y) {
    int liveNeighbors = 0;

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0)
                continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < BOARD_WIDTH && ny >= 0 && ny < BOARD_HEIGHT) {
                if (board[nx][ny])
                    liveNeighbors++;
            }
        }
    }
    return liveNeighbors;
}