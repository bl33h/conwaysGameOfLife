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

// Update the board for the next generation
void newBoard() {
    std::vector<std::vector<bool>> newBoard(BOARD_WIDTH, std::vector<bool>(BOARD_HEIGHT, false));
    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            int liveNeighbors = liveNeighbors(x, y);

            // Conway's Game of Life rules
            if (board[x][y]) {
                if (liveNeighbors < 2 || liveNeighbors > 3)
                    newBoard[x][y] = false;
                else
                    newBoard[x][y] = true;
            } else {
                if (liveNeighbors == 3)
                    newBoard[x][y] = true;
                else
                    newBoard[x][y] = false;
            }
        }
    }

    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            board[x][y] = newBoard[x][y];
        }
    }
}

void initializeBoard() {
    for (int i = 0; i < 1000; ++i) {
        int pattern = rand() % 11;
        int startX = rand() % (BOARD_WIDTH - 10);
        int startY = rand() % (BOARD_HEIGHT - 10);
        startX = std::max(startX, 0);
        startY = std::max(startY, 0);
        startX = std::min(startX, static_cast<int>(BOARD_WIDTH) - 1);
        startY = std::min(startY, static_cast<int>(BOARD_HEIGHT) - 1);

        if (pattern == 0) {
            // Heavy-weight Spaceship
            board[startX][startY + 1] = true;
            board[startX + 1][startY] = true;
            board[startX + 1][startY + 1] = true;
            board[startX + 1][startY + 2] = true;
            board[startX + 2][startY] = true;
            board[startX + 2][startY + 2] = true;
            board[startX + 3][startY] = true;
            board[startX + 3][startY + 1] = true;

        } else if (pattern == 1) {
            // Block
            board[startX][startY] = true;
            board[startX][startY + 1] = true;
            board[startX + 1][startY] = true;
            board[startX + 1][startY + 1] = true;

        } else if (pattern == 2) {
            // Bee-hive
            board[startX + 1][startY] = true;
            board[startX + 2][startY] = true;
            board[startX][startY + 1] = true;
            board[startX + 3][startY + 1] = true;
            board[startX + 1][startY + 2] = true;
            board[startX + 2][startY + 2] = true;

        } else if (pattern == 3) {
            // Loaf
            board[startX + 1][startY] = true;
            board[startX + 2][startY] = true;
            board[startX][startY + 1] = true;
            board[startX + 3][startY + 1] = true;
            board[startX + 1][startY + 2] = true;
            board[startX + 3][startY + 2] = true;
            board[startX + 2][startY + 3] = true;

        } else if (pattern == 4) {
            // Boat
            board[startX][startY] = true;
            board[startX + 1][startY] = true;
            board[startX][startY + 1] = true;
            board[startX + 2][startY + 1] = true;
            board[startX + 1][startY + 2] = true;

        } else if (pattern == 5) {
            // Light-weight Spaceship
            board[startX][startY + 1] = true;
            board[startX + 1][startY] = true;
            board[startX + 2][startY] = true;
            board[startX + 3][startY] = true;
            board[startX + 3][startY + 1] = true;
            board[startX + 3][startY + 2] = true;
            board[startX + 2][startY + 3] = true;
            board[startX][startY + 3] = true;

        } else if (pattern == 6) {
            // Penta-decathlon
            int offset = 1;
            for (int i = 0; i < 7; ++i) {
                board[startX][startY + offset] = true;
                board[startX + 1][startY + offset] = true;
                board[startX + 2][startY + offset] = true;
                offset++;
            }

        } else if (pattern == 7) {
            // Toad
            board[startX + 1][startY] = true;
            board[startX + 2][startY] = true;
            board[startX + 3][startY] = true;
            board[startX][startY + 1] = true;
            board[startX + 1][startY + 1] = true;
            board[startX + 2][startY + 1] = true;

        } else if (pattern == 8) {
            // Beacon
            board[startX][startY] = true;
            board[startX + 1][startY] = true;
            board[startX][startY + 1] = true;
            board[startX + 3][startY + 2] = true;
            board[startX + 2][startY + 3] = true;
            board[startX + 3][startY + 3] = true;

        } else if (pattern == 9) {
            int offset = 3;
            for (int i = 0; i < 3; ++i) {
                board[startX + i][startY + offset] = true;
                board[startX + i + 4][startY + offset] = true;
                board[startX + i + 9][startY + offset] = true;
                board[startX + i][startY + offset + 5] = true;
                board[startX + i + 4][startY + offset + 5] = true;
                board[startX + i + 9][startY + offset + 5] = true;
                offset--;
            }
            offset = 3;
            for (int i = 0; i < 3; ++i) {
                board[startX + offset][startY + i] = true;
                board[startX + offset][startY + i + 4] = true;
                board[startX + offset][startY + i + 9] = true;
                board[startX + offset + 5][startY + i] = true;
                board[startX + offset + 5][startY + i + 4] = true;
                board[startX + offset + 5][startY + i + 9] = true;
                offset--;
            }
        
        } else if (pattern == 10) {
            // Glider
            board[startX + 1][startY] = true;
            board[startX + 2][startY + 1] = true;
            board[startX][startY + 2] = true;
            board[startX + 1][startY + 2] = true;
            board[startX + 2][startY + 2] = true;
        }
    }
}

void render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, 255);
    SDL_RenderClear(renderer);
    frameCount++;
    if (frameCount >= framesPerColorChange) {
        frameCount = 0;
        useCellColor1 = !useCellColor1;
    }

    for (int x = 0; x < BOARD_WIDTH; ++x) {
        for (int y = 0; y < BOARD_HEIGHT; ++y) {
            if (board[x][y]) {
                Color aliveColor = useCellColor1 ? cellColor : cellColor2;
                SDL_SetRenderDrawColor(renderer, aliveColor.r, aliveColor.g, aliveColor.b, 255);
                SDL_Rect rect{x * (SCREEN_WIDTH / BOARD_WIDTH), y * (SCREEN_HEIGHT / BOARD_HEIGHT),
                              SCREEN_WIDTH / BOARD_WIDTH, SCREEN_HEIGHT / BOARD_HEIGHT};
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    newBoard();
    SDL_RenderPresent(renderer);
}

int main() {
    srand(time(NULL));
    initializeBoard();

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Conway's Game of Life", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED
    );
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        render(renderer);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}