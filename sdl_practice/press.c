#include <SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("");
    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("press", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Event event;
    _Bool running = 1;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = 0;

            if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    case SDLK_1:
                        printf("\r1");
                        break;
                    case SDLK_2:
                        printf("\r2");
                        break;
                    default:
                        break;
                }
            }
        }

        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}