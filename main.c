#include <stdio.h>

#include "SDL/include/SDL.h"

int main(int argc, char** argv)
{
    printf("Hello world!\n");

    SDL_Window* window;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Chip8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_METAL);

    if (window == NULL) {
        printf("Failed to create a window %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event e;
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            if (e.type == SDL_KEYDOWN) {
                quit = 1;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                quit = 1;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}