CC = gcc

SDL_INCLUDE       = -I"C:/mingw_dev_lib/SDL2-2.32.10/include/SDL2"
SDL_IMAGE_INCLUDE = -I"C:/mingw_dev_lib/SDL2_image-2.8.12/include/SDL2"
SDL_MIXER_INCLUDE = -I"C:/mingw_dev_lib/SDL2_mixer-2.8.2/include/SDL2"
SDL_TTF_INCLUDE   = -I"C:/mingw_dev_lib/SDL2_ttf-2.24.0/include/SDL2"
SDL_NET_INCLUDE   = -I"C:/mingw_dev_lib/SDL2_net-2.4.0/include/SDL2"

SDL_LINK       = -L"C:/mingw_dev_lib/SDL2-2.32.10/lib"
SDL_IMAGE_LINK = -L"C:/mingw_dev_lib/SDL2_image-2.8.12/lib"
SDL_MIXER_LINK = -L"C:/mingw_dev_lib/SDL2_mixer-2.8.2/lib"
SDL_TTF_LINK   = -L"C:/mingw_dev_lib/SDL2_ttf-2.24.0/lib"
SDL_NET_LINK   = -L"C:/mingw_dev_lib/SDL2_net-2.4.0/lib"

ADDITIONAL_DEPENDENCIES = -lSDL2_image -lSDL2_mixer -lmingw32 -lSDL2main -lSDL2

CFLAGS = -Wpedantic -Wextra -Wall
C_17 = -std=c17

FILE ?= sdl_test

all:
	$(CC) $(FILE).c $(SDL_INCLUDE) $(SDL_MIXER_INCLUDE) $(SDL_IMAGE_INCLUDE) $(SDL_LINK) $(SDL_MIXER_LINK) $(SDL_IMAGE_LINK) $(ADDITIONAL_DEPENDENCIES) $(C_17)
clean:
	del a.exe