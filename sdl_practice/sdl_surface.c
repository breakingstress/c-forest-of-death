/*
 * @author breakingstress
 * 
 * Following CodingMadeEasy's tutorial on Bitmaps #3, link: https://www.youtube.com/watch?v=sht1i4qZCQU
 * 
 * SDL_GetWindowSurface, SDL_LoadBMP, SDL_BlitSurface, SDL_UpdateWindowSurface, SDL_FreeSurface
 */
#include <SDL.h>
#include <stdio.h>

void exit_program(SDL_Window *);

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;

    SDL_Window *window = NULL;

    if (!(window = SDL_CreateWindow(
        "SDL Surfaces", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480,
        SDL_WINDOW_SHOWN
    ))) return 1;

    SDL_Surface *window_surface = NULL,
                *image_surface = NULL;

    window_surface = SDL_GetWindowSurface(window);
    image_surface = SDL_LoadBMP("assets/images/dragonite.bmp");

    if (!image_surface) {
        fprintf(stderr, "Error loading dragonite.bmp. %s", SDL_GetError());
        return 1;
    }

    /* blits(block image transfers) the image surf onto the win surf*/
    /* looks like you can also blit rects with the same function */
    SDL_BlitSurface(image_surface, NULL, window_surface, NULL);
    SDL_UpdateWindowSurface(window);

    SDL_Delay(2000);

    /* Frees image_surface to prevent memory leak, since it's not freed automatically
       with SDL_DestroyWindow() */
    SDL_FreeSurface(image_surface);
    image_surface = NULL;

    /* set all pointers to nullptr to prevent dangling pointers */
    exit_program(window);
    window_surface = NULL;
    window = NULL;

    return 0;
}

void exit_program(SDL_Window *window) {
    /* Frees window surface and window struct */
    SDL_DestroyWindow(window);
    /* Unitialises SDL */
    SDL_Quit();
}