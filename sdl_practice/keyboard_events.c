#include <SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Keyboard Events", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 640, SDL_WINDOW_SHOWN);

    SDL_Surface *window_surface = SDL_GetWindowSurface(window),
                *current_image_surface = NULL,
                *dragonite_surface = SDL_LoadBMP("assets/images/dragonite.bmp"),
                *image_1_surface = IMG_Load
}