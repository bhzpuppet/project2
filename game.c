#include "game.h"
#include "data.h" 
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

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
    obstacle_1 = SDL_LoadBMP( "images/square.bmp" );
    player = SDL_LoadBMP("images/circle.bmp"); 
    obstacle_2 = SDL_LoadBMP( "images/square.bmp" );
    change_1 = SDL_LoadBMP( "images/1.bmp" );
    change_2 = SDL_LoadBMP( "images/2.bmp" );
    change_3 = SDL_LoadBMP( "images/3.bmp" );
    change_4 = SDL_LoadBMP( "images/4.bmp" );
    background = SDL_LoadBMP( "images/white.bmp" );
    if( obstacle_1 == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/square.bmp", SDL_GetError() );
        success = false;
    }
    if( player == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/square.bmp", SDL_GetError() );
        success = false;
    }
    if( obstacle_2 == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/square.bmp", SDL_GetError() );
        success = false;
    }
    if(  change_1== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/1.bmp", SDL_GetError() );
        success = false;
    }
    if(  change_2== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/2.bmp", SDL_GetError() );
        success = false;
    }
    if(  change_3== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/3.bmp", SDL_GetError() );
        success = false;
    }
    if(  change_4== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/4.bmp", SDL_GetError() );
        success = false;
    }
    if(  background== NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/white.bmp", SDL_GetError() );
        success = false;
    }
    

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( obstacle_1 );
    SDL_FreeSurface( obstacle_2 );
    SDL_FreeSurface( player );
	obstacle_1 = NULL;
	obstacle_2 = NULL;
	player = NULL;
    //Destroy window
    SDL_DestroyWindow( Window );
    Window = NULL;
	//Destroy texture
	SDL_DestroyTexture(obstacle_1_texture);
	SDL_DestroyTexture(obstacle_2_texture);
	SDL_DestroyTexture(player_texture);
    //Quit SDL subsystems
    SDL_Quit();
}


// obstacle_1
bool moveright = true;
bool movedown = true;
// obstacle_2
bool moveright_1 = true;
bool movedown_1 = true;
// obstacle_3
bool moveright_2 = true;
bool movedown_2 = true;

int count = 0, count_change = 0;
void updatePosition()
{
	if (moveright == true)
	{
		rect_obstacle_1.x++;
		if (rect_obstacle_1.x + rect_obstacle_1.w >= SCREEN_WIDTH)
		{
			moveright = false;
			count++;
		}
	}
	else
	{
		rect_obstacle_1.x--;
		if (rect_obstacle_1.x <= 0)
		{
			moveright = true;
			count++;
		}
	}
	if (movedown == true)
	{
		rect_obstacle_1.y++;
		if (rect_obstacle_1.y + rect_obstacle_1.h >= SCREEN_HEIGHT)
		{
			movedown = false;
			count++;
		}
	}
	else
	{
		rect_obstacle_1.y--;
		if (rect_obstacle_1.y <= 0)
		{
			movedown = true;
			count++;
		}
	}
}

void updatePosition_1()
{ 
	if (moveright_1 == true)
	{
		rect_obstacle_2.x++;
		if (rect_obstacle_2.x + rect_obstacle_2.w >= SCREEN_WIDTH)
		{
			moveright_1 = false;
		}
	}
	else
	{
		rect_obstacle_2.x--;
		if (rect_obstacle_2.x <= 0)
		{
			moveright_1 = true;
		}
	}
	if (movedown_1 == true)
	{
		rect_obstacle_2.y++;
		if (rect_obstacle_2.y + rect_obstacle_2.h >= SCREEN_HEIGHT)
		{
			movedown_1 = false;
		}
	}
	else
	{
		rect_obstacle_2.y--;
		if (rect_obstacle_2.y <= 0)
		{
			movedown_1 = true;
		}
	}
}

void updatePosition_2()
{ 
	if (moveright_2 == true)
	{
		rect_change_1.x++;
		rect_change_2.x++;
		rect_change_3.x++;
		rect_change_4.x++;
		if (rect_change_1.x + rect_change_1.w >= SCREEN_WIDTH)
		{
			count_change++;
			moveright_2 = false;
		}
	}
	else
	{
		rect_change_1.x--;
		rect_change_2.x--;
		rect_change_3.x--;
		rect_change_4.x--;
		if (rect_change_1.x <= 0)
		{
			count_change++;
			moveright_2 = true;
		}
	}
	if (movedown_2 == true)
	{
		rect_change_1.y++;
		rect_change_2.y++;
		rect_change_3.y++;
		rect_change_4.y++;
		if (rect_change_1.y + rect_change_1.h >= SCREEN_HEIGHT)
		{
			count_change++;
			movedown_2 = false;
		}
	}
	else
	{
		rect_change_1.y--;
		rect_change_2.y--;
		rect_change_3.y--;
		rect_change_4.y--;
		if (rect_change_1.y <= 0)
		{
			count_change++;
			movedown_2 = true;
		}
	}
}
void update_square (int a)
{
	if (a == 1)
	{
		rect_player.y = rect_player.y - 10;
	}
	if (a == 2)
	{
		rect_player.y = rect_player.y + 10;
	}
	if (a == 3)
	{
		rect_player.x = rect_player.x - 10;
	}
	if (a == 4)
	{
		rect_player.x = rect_player.x + 10;
	}
}
bool quit = false;
void check ()
{
	if (SDL_HasIntersection(&rect_obstacle_1, &rect_player) == true)
	{
		printf("aaaaaaaaaaaa!\n");
		quit = true;
	}
	if (SDL_HasIntersection(&rect_obstacle_2, &rect_player) == true)
	{
		printf("aaaaaaaaaaaa!\n");
		quit = true;
	}
}

void setposition()
{ 
	// background
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.h = SCREEN_HEIGHT;
    rect_background.w = SCREEN_WIDTH;
	 // obstacle_1
	rect_obstacle_1.x = 0;
    rect_obstacle_1.y = 0;
    rect_obstacle_1.h = obstacle_1->h;
    rect_obstacle_1.w = obstacle_1->w;
    // obstacle_2
    rect_obstacle_2.x = 600;
    rect_obstacle_2.y = 400;
    rect_obstacle_2.h = obstacle_2->h;
    rect_obstacle_2.w = obstacle_2->w;
    // player
    rect_player.x = 300;
    rect_player.y = 300;
    rect_player.h = player->h;
    rect_player.w = player->w;
     // obstacle_1
	rect_change_1.x = 100;
    rect_change_1.y = 100;
    rect_change_1.h = obstacle_1->h;
    rect_change_1.w = obstacle_1->w;
    // obstacle_1
	rect_change_2.x = 100;
    rect_change_2.y = 100;
    rect_change_2.h = obstacle_1->h;
    rect_change_2.w = obstacle_1->w;
    // obstacle_1
	rect_change_3.x = 100;
    rect_change_3.y = 100;
    rect_change_3.h = obstacle_1->h;
    rect_change_3.w = obstacle_1->w;
    // obstacle_1
	rect_change_4.x = 100;
    rect_change_4.y = 100;
    rect_change_4.h = obstacle_1->h;
    rect_change_4.w = obstacle_1->w;
  
}

void going()
{
	SDL_Event event;
   	rend = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(rend);
    // create texture
	obstacle_1_texture = SDL_CreateTextureFromSurface(rend,obstacle_1);
	obstacle_2_texture = SDL_CreateTextureFromSurface(rend,obstacle_2);
    player_texture = SDL_CreateTextureFromSurface(rend,player);
    background_texture = SDL_CreateTextureFromSurface(rend,background);
    change_1_texture = SDL_CreateTextureFromSurface(rend,change_1);
    change_2_texture = SDL_CreateTextureFromSurface(rend,change_2);
    change_3_texture = SDL_CreateTextureFromSurface(rend,change_3);
    change_4_texture = SDL_CreateTextureFromSurface(rend,change_4);
  	// set position
	setposition();
        	
	time_t start,end;
	start =time(NULL);

	
	while ( quit == false )
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
			quit = true;
			}
			 else if( event.type == SDL_KEYDOWN )
            {
                // Move based on key press
                switch( event.key.keysym.sym )
                {
                    case SDLK_UP:
                    update_square (1);
                    break;
                    case SDLK_DOWN:
                    update_square (2);
                    break;
                    case SDLK_LEFT:
                    update_square (3);
                    break;
                    case SDLK_RIGHT:
                    update_square (4);
                    break;
                }
            }
		}					
		check();
		SDL_Delay(5);
		SDL_RenderClear(rend);
		// 生成背景 
		SDL_RenderCopy(rend,background_texture,NULL,&rect_background);
		updatePosition();
		SDL_RenderCopy(rend,obstacle_1_texture,NULL,&rect_obstacle_1);
//			 碰撞一定次数后开始第二个 
		if(count>2) {
			updatePosition_1();
			SDL_RenderCopy(rend,obstacle_2_texture,NULL,&rect_obstacle_2);
		}
		updatePosition_2();
		SDL_RenderCopy(rend,player_texture,NULL,&rect_player);
		if(count_change % 4 == 0) {
			SDL_RenderCopy(rend,change_1_texture,NULL,&rect_change_1);
		}
		if(count_change % 4 == 1) {
			SDL_RenderCopy(rend,change_2_texture,NULL,&rect_change_2);
		}
		if(count_change % 4 == 2) {
			SDL_RenderCopy(rend,change_3_texture,NULL,&rect_change_3);
		}
		if(count_change % 4 == 3) {
			SDL_RenderCopy(rend,change_4_texture,NULL,&rect_change_4);
		}
		
		SDL_RenderPresent(rend);
	}
	// 结尾时间 
	end =time(NULL);
	// 显示时间 
	printf("time=%d\n",difftime(end,start));
}
