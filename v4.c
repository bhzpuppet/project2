/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

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
        Window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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
    box = SDL_LoadBMP( "images/square.bmp" );
    circle = SDL_LoadBMP("images/circle.bmp"); 
    box1 = SDL_LoadBMP( "images/square.bmp" );
    if( box == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/square.bmp", SDL_GetError() );
        success = false;
    }
    if( circle == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/square.bmp", SDL_GetError() );
        success = false;
    }
    if( box1 == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", "images/square.bmp", SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Deallocate surface
    SDL_FreeSurface( box );
    SDL_FreeSurface( box1 );
    SDL_FreeSurface( circle );
	box = NULL;
	box1 = NULL;
	circle = NULL;
    //Destroy window
    SDL_DestroyWindow( Window );
    Window = NULL;
	//Destroy texture
	SDL_DestroyTexture(box_texture);
	SDL_DestroyTexture(box1_texture);
	SDL_DestroyTexture(circle_texture);
    //Quit SDL subsystems
    SDL_Quit();
}

SDL_Rect rect, rect_0, rect_1;//新加的方块;
bool moveright = true;
bool movedown = true;
// new
bool moveright_1 = true;
bool movedown_1 = true;
void updatePosition()
{
	if (moveright == true)
	{
		rect.x++;
		if (rect.x + rect.w >= 640)
		{
			moveright = false;
		}
	}
	else
	{
		rect.x--;
		if (rect.x <= 0)
		{
			moveright = true;
		}
	}
	if (movedown == true)
	{
		rect.y++;
		if (rect.y + rect.h >= 480)
		{
			movedown = false;
		}
	}
	else
	{
		rect.y--;
		if (rect.y <= 0)
		{
			movedown = true;
		}
	}
}

void updatePosition_1()
{
	if (moveright_1 == true)
	{
		rect_1.x++;
		if (rect_1.x + rect_1.w >= 640)
		{
			moveright_1 = false;
		}
	}
	else
	{
		rect_1.x--;
		if (rect_1.x <= 0)
		{
			moveright_1 = true;
		}
	}
	if (movedown_1 == true)
	{
		rect_1.y++;
		if (rect_1.y + rect_1.h >= 480)
		{
			movedown_1 = false;
		}
	}
	else
	{
		rect_1.y--;
		if (rect_1.y <= 0)
		{
			movedown_1 = true;
		}
	}
}

void update_square (int a)
{
	if (a == 1)
	{
		rect_0.y = rect_0.y - 10;
	}
	if (a == 2)
	{
		rect_0.y = rect_0.y + 10;
	}
	if (a == 3)
	{
		rect_0.x = rect_0.x - 10;
	}
	if (a == 4)
	{
		rect_0.x = rect_0.x + 10;
	}
}

void check ()
{
	if (SDL_HasIntersection(&rect, &rect_0) == true)
	{
		printf("aaaaaaaaaaaa!\n");
	}
}
int main( int argc, char* args[] )
{
    //Start up SDL and create window
    if( !init() )
    {
        printf( "Failed to initialize!\n" );
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            printf( "Failed to load media!\n" );
        }
        else
        {
        	SDL_Event event;
        	rend = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
        	SDL_RenderClear(rend);
        	// create texture
			box_texture = SDL_CreateTextureFromSurface(rend,box);
			box1_texture = SDL_CreateTextureFromSurface(rend,box1);
        	circle_texture = SDL_CreateTextureFromSurface(rend,circle);
        	// set position
			rect.x = 0;
        	rect.y = 0;
        	rect.h = box->h;
        	rect.w = box->w;
        	rect_0.x = 0;
        	rect_0.y = 0;
        	rect_0.h = box->h;
        	rect_0.w = box->w;
        	//new
        	rect_1.x = 300;
        	rect_1.y = 400;
        	rect_1.h = box->h;
        	rect_1.w = box->w;
        	bool quit = false;
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
                        //Select surfaces based on key press
                        switch( event.key.keysym.sym )
                        {
                            case SDLK_UP:
                            printf("up\n");
                            update_square (1);
                            break;
                            case SDLK_DOWN:
                            printf("down\n");
                            update_square (2);
                            break;
                            case SDLK_LEFT:
                            printf("left\n");
                            update_square (3);
                            break;
                            case SDLK_RIGHT:
                            printf("right\n");
                            update_square (4);
                            break;
                        }
                    }
				}
					updatePosition();
					updatePosition_1();
					check();
					SDL_Delay(5);
					SDL_RenderClear(rend);
					SDL_RenderCopy(rend,box_texture,NULL,&rect);
					SDL_RenderCopy(rend,box1_texture,NULL,&rect_1);
					SDL_RenderCopy(rend,circle_texture,NULL,&rect_0);
					SDL_RenderPresent(rend);
			} 
		}
        		
    }

    //Free resources and close SDL
    close();

    return 0;
}


