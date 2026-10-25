/* starting to look a bit like pygame... */
#include <SDL.h>
#include <SDL_image.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow("Keyboard Events", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 640, SDL_WINDOW_SHOWN);

    SDL_Surface *window_surface        = SDL_GetWindowSurface(window),
                *dragonite_surface     = SDL_LoadBMP("assets/images/dragonite.bmp"),
                *image_1_surface       = IMG_LoadPNG_RW(SDL_RWFromFile("assets/images/image.png", "rb")),
                *image_2_surface       = IMG_LoadPNG_RW(SDL_RWFromFile("assets/images/2.png", "rb")),
                *current_image_surface = NULL;

    SDL_Surface *image_array[] = { dragonite_surface, image_1_surface, image_2_surface };

    int i = 0;
    current_image_surface = image_array[i];

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }

            if (event.type == SDL_KEYUP) {
                switch (event.key.keysym.sym) {
                    case SDLK_d:
                    case SDLK_RIGHT:
                        /* iterate through list forwards */
                        if (i == 2) i = 0;
                        i++;
                        current_image_surface = image_array[i];
                        break;

                    case SDLK_a:
                    case SDLK_LEFT:
                        /* iterate through list forwards */
                        if (i == 0) i = 2;
                        i--;
                        current_image_surface = image_array[i];
                        break;

                    default:
                        break;
                }
            }
        }

        SDL_BlitSurface(current_image_surface, NULL, window_surface, NULL);
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    dragonite_surface = image_1_surface = image_2_surface = NULL;
    SDL_Quit();    
}