#include <stdio.h>

#include "SDL/include/SDL.h"

int main(int argc, char** argv)
{
    printf("Hello world!\n");

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event e;

    float circleX = 400;
    float circleY = 600;
    float circleRadius = 50;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(800, 800, 0, &window, &renderer);

    if (window == NULL) {
        printf("Failed to create a window %s\n", SDL_GetError());
        return 1;
    }

    if (renderer == NULL) {
        printf("Failed to create renderer %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    for (float x = 0; x < 800; x++) {
        for (float y = 0; y < 800; y++) {
            float check = ((x - circleX) * (x - circleX) + (y - circleY) * (y - circleY));
            if (check >= (circleRadius * circleRadius) - 50.0f && check <= (circleRadius * circleRadius) + 50.0f) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }

    SDL_RenderPresent(renderer);
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
            if (e.type == SDL_KEYDOWN) {
                quit = 1;
            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}