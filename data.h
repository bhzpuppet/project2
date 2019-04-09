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
SDL_Surface* obstacle_1 = NULL;
SDL_Surface* obstacle_2 = NULL;
SDL_Surface* player = NULL;

SDL_Renderer* rend = NULL;


SDL_Texture*  obstacle_1_texture = NULL;
SDL_Texture*  obstacle_2_texture = NULL;
SDL_Texture* player_texture = NULL;

//新加的方块;
SDL_Rect rect_obstacle_1, rect_obstacle_2, rect_player;

#endif
