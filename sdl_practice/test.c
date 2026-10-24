#include <SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS )) return 1;
    if (!SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN, &window, &renderer)) return 1;

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    SDL_Surface *dragonite_surface = SDL_LoadBMP("assets/images/dragonite.bmp");

    SDL_Event event;
    while (true) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) return 1;
        }

        SDL_BlitSurface(dragonite_surface, NULL, window_surface, NULL);
        
        SDL_UpdateWindowSurface(window);
    }
}