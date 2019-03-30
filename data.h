#ifndef _DATA_H_
#define _DATA_H_

#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



//The window we'll be rendering to
SDL_Window* Window = NULL;

//The surface contained by the window
SDL_Surface* ScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* box = NULL;
SDL_Surface* box1 = NULL;
SDL_Surface* circle = NULL;

SDL_Renderer* rend = NULL;


SDL_Texture*  box_texture = NULL;
SDL_Texture*  box1_texture = NULL;
SDL_Texture* circle_texture = NULL;

#endif
