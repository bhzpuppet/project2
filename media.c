#include "media.h"
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
SDL_Surface* obstacle_1_1 = NULL;
SDL_Surface* obstacle_1_2 = NULL;
SDL_Surface* obstacle_1_3 = NULL;
SDL_Surface* obstacle_1_4 = NULL;
SDL_Surface* obstacle_2_1 = NULL;
SDL_Surface* obstacle_2_2 = NULL;
SDL_Surface* obstacle_2_3 = NULL;
SDL_Surface* obstacle_2_4 = NULL;
SDL_Surface* player = NULL;
SDL_Surface* change_1 = NULL;
SDL_Surface* change_2 = NULL;
SDL_Surface* change_3 = NULL;
SDL_Surface* change_4 = NULL;
SDL_Surface* background = NULL; 
SDL_Surface* black_start = NULL; 
SDL_Surface* red_start = NULL; 

//render
SDL_Renderer* rend = NULL;

//Texture
SDL_Texture* obstacle_1_1_texture = NULL;
SDL_Texture* obstacle_1_2_texture = NULL;
SDL_Texture* obstacle_1_3_texture = NULL;
SDL_Texture* obstacle_1_4_texture = NULL;
SDL_Texture* obstacle_2_1_texture = NULL;
SDL_Texture* obstacle_2_2_texture = NULL;
SDL_Texture* obstacle_2_3_texture = NULL;
SDL_Texture* obstacle_2_4_texture = NULL;
SDL_Texture* player_texture = NULL;
SDL_Texture* background_texture = NULL;
SDL_Texture* change_1_texture = NULL;
SDL_Texture* change_2_texture = NULL;
SDL_Texture* change_3_texture = NULL;
SDL_Texture* change_4_texture = NULL;
SDL_Texture* black_start_texture = NULL;
SDL_Texture* red_start_texture = NULL;

//REct
SDL_Rect rect_obstacle_1_1, rect_obstacle_1_2, rect_obstacle_1_3, rect_obstacle_1_4;
SDL_Rect rect_obstacle_2_1, rect_obstacle_2_2, rect_obstacle_2_3, rect_obstacle_2_4;
SDL_Rect rect_player, rect_background, rect_black_start, rect_red_start;
SDL_Rect rect_change_1, rect_change_2, rect_change_3, rect_change_4;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        Window = SDL_CreateWindow( "GAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( Window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            ScreenSurface = SDL_GetWindowSurface( Window );
        }
    }

    return success;
}

bool loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load splash image
    player = SDL_LoadBMP("images/player.bmp"); 
    obstacle_1_1 = SDL_LoadBMP( "images/1.bmp" );
    obstacle_1_2 = SDL_LoadBMP( "images/2.bmp" );
    obstacle_1_3 = SDL_LoadBMP( "images/3.bmp" );
    obstacle_1_4 = SDL_LoadBMP( "images/4.bmp" );
    obstacle_2_1 = SDL_LoadBMP( "images/1.bmp" );
    obstacle_2_2 = SDL_LoadBMP( "images/2.bmp" );
    obstacle_2_3 = SDL_LoadBMP( "images/3.bmp" );
    obstacle_2_4 = SDL_LoadBMP( "images/4.bmp" );
    change_1 = SDL_LoadBMP( "images/1.bmp" );
    change_2 = SDL_LoadBMP( "images/2.bmp" );
    change_3 = SDL_LoadBMP( "images/3.bmp" );
    change_4 = SDL_LoadBMP( "images/4.bmp" );
    background = SDL_LoadBMP( "images/white.bmp" );
    black_start = SDL_LoadBMP( "images/black_start.bmp" );
    red_start = SDL_LoadBMP( "images/red_start.bmp" );
    if( player == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/player.bmp", SDL_GetError() );
        success = false;
    }
    if(  change_1== NULL || obstacle_1_1==NULL || obstacle_2_1==NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/1.bmp", SDL_GetError() );
        success = false;
    }
    if(  change_2== NULL || obstacle_1_2==NULL || obstacle_2_2==NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/2.bmp", SDL_GetError() );
        success = false;
    }
    if(  change_3== NULL || obstacle_1_3==NULL || obstacle_2_3==NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/3.bmp", SDL_GetError() );
        success = false;
    }
    if(  change_4== NULL || obstacle_1_4==NULL || obstacle_2_4==NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/4.bmp", SDL_GetError() );
        success = false;
    }
    if(  background== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/white.bmp", SDL_GetError() );
        success = false;
    }
    if(  black_start== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/black_start.bmp", SDL_GetError() );
        success = false;
    }
    if(  red_start== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/red_start.bmp", SDL_GetError() );
        success = false;
    }
    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( obstacle_1_1 );
	SDL_FreeSurface( obstacle_1_2 );
	SDL_FreeSurface( obstacle_1_3 );
	SDL_FreeSurface( obstacle_1_4 );
    SDL_FreeSurface( obstacle_2_1 );
	SDL_FreeSurface( obstacle_2_2 );
	SDL_FreeSurface( obstacle_2_3 );
	SDL_FreeSurface( obstacle_2_4 );
    SDL_FreeSurface( player );
	SDL_FreeSurface( background );
	SDL_FreeSurface( black_start );
	SDL_FreeSurface( red_start );
	obstacle_1_1 = NULL;
	obstacle_1_2 = NULL;
	obstacle_1_3 = NULL;
	obstacle_1_4 = NULL;
	obstacle_2_1 = NULL;
	obstacle_2_2 = NULL;
	obstacle_2_3 = NULL;
	obstacle_2_4 = NULL;
	player = NULL;
	background = NULL;
	black_start = NULL;
	red_start = NULL;
    //Destroy window
    SDL_DestroyWindow( Window );
    Window = NULL;
	//Destroy texture
	SDL_DestroyTexture(obstacle_1_1_texture);
	SDL_DestroyTexture(obstacle_1_2_texture);
	SDL_DestroyTexture(obstacle_1_3_texture);
	SDL_DestroyTexture(obstacle_1_4_texture);
	SDL_DestroyTexture(obstacle_2_1_texture);
	SDL_DestroyTexture(obstacle_2_2_texture);
	SDL_DestroyTexture(obstacle_2_3_texture);
	SDL_DestroyTexture(obstacle_2_4_texture);
	SDL_DestroyTexture(player_texture);
	SDL_DestroyTexture(background_texture);
	SDL_DestroyTexture(black_start_texture);
	SDL_DestroyTexture(red_start_texture);
	obstacle_1_1_texture = NULL;
	obstacle_1_2_texture = NULL;
	obstacle_1_3_texture = NULL;
	obstacle_1_4_texture = NULL;
	obstacle_2_1_texture = NULL;
	obstacle_2_2_texture = NULL;
	obstacle_2_3_texture = NULL;
	obstacle_2_4_texture = NULL;
	player_texture = NULL;
	background_texture = NULL;
	black_start_texture = NULL;
	red_start_texture = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}

