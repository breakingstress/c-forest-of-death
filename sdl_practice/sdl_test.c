#include <SDL.h>
#include <stdio.h>

// can't run with no args
int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        // call SDL_GetError whenever you get an error
        // for a more detailed error message
        printf("Video Initialise Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    // if window returns NULL
    if (!window) {
        fprintf(stderr, "Window Creation Error: %s\n", SDL_GetError());
        return 1;
    }


    SDL_UpdateWindowSurface(window); /* Updates window surface */
    SDL_Delay(2000);

    SDL_DestroyWindow(window); /* Frees the memory being used by the window struct*/
    SDL_Quit(); /* Uninitialises what's been initialised */

    return 0;
}