#include <SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);

    SDL_Window *window = SDL_CreateWindow("Close Button", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    bool running = true;
    SDL_Event event;

    /* Game Loop */
    while (running) {
        /* Event Loop */
        while (SDL_PollEvent(&event)) {
            /* SDL_QUIT is an enum for the quit event */
            if (event.type == SDL_QUIT) running = false;
        }
    }

    SDL_DestroyWindow(window);
    window = NULL;
    SDL_Quit();

    return 0;
}