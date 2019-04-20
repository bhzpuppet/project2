#include "game.h" 
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

time_t start,end;
//Screen dimension constants
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

//The window we'll be rendering to
extern SDL_Window* Window;

//The surface contained by the window
extern SDL_Surface* ScreenSurface;

//The image we will load and show on the screen
extern SDL_Surface* obstacle_1_1;
extern SDL_Surface* obstacle_1_2;
extern SDL_Surface* obstacle_1_3;
extern SDL_Surface* obstacle_1_4;
extern SDL_Surface* obstacle_2_1;
extern SDL_Surface* obstacle_2_2;
extern SDL_Surface* obstacle_2_3;
extern SDL_Surface* obstacle_2_4;
extern SDL_Surface* player;
extern SDL_Surface* change_1;
extern SDL_Surface* change_2;
extern SDL_Surface* change_3;
extern SDL_Surface* change_4;
extern SDL_Surface* background; 
extern SDL_Surface* black_start; 
extern SDL_Surface* red_start; 
extern SDL_Surface* gameover; 

//render
extern SDL_Renderer* rend;

//Texture
extern SDL_Texture* obstacle_1_1_texture;
extern SDL_Texture* obstacle_1_2_texture;
extern SDL_Texture* obstacle_1_3_texture;
extern SDL_Texture* obstacle_1_4_texture;
extern SDL_Texture* obstacle_2_1_texture;
extern SDL_Texture* obstacle_2_2_texture;
extern SDL_Texture* obstacle_2_3_texture;
extern SDL_Texture* obstacle_2_4_texture;
extern SDL_Texture* player_texture;
extern SDL_Texture* change_1_texture;
extern SDL_Texture* change_2_texture;
extern SDL_Texture* change_3_texture;
extern SDL_Texture* change_4_texture;
extern SDL_Texture* background_texture;
extern SDL_Texture* black_start_texture;
extern SDL_Texture* red_start_texture;
extern SDL_Texture* gameover_texture;

//REct;
extern SDL_Rect rect_obstacle_1_1, rect_obstacle_1_2, rect_obstacle_1_3, rect_obstacle_1_4;
extern SDL_Rect rect_obstacle_2_1, rect_obstacle_2_2, rect_obstacle_2_3, rect_obstacle_2_4;
extern SDL_Rect rect_player, rect_background, rect_black_start, rect_red_start, rect_gameover;
extern SDL_Rect rect_change_1, rect_change_2, rect_change_3, rect_change_4;

// obstacle_1

bool moveright = true;

bool movedown = true;

// obstacle_2

bool moveright_1 = true;

bool movedown_1 = true;

// obstacle_3

bool moveright_2 = true;

bool movedown_2 = true;



int count_1 = 0, count_2 = 0, count_3 = 0;

void updatePosition()

{

	if (moveright == true)

	{

		rect_obstacle_1_1.x++;
		rect_obstacle_1_2.x++;
		rect_obstacle_1_3.x++;
		rect_obstacle_1_4.x++;

		if (rect_obstacle_1_1.x + rect_obstacle_1_1.w >= SCREEN_WIDTH)

		{

			moveright = false;

			count_1++;

		}

	}

	else

	{

		rect_obstacle_1_1.x--;
		rect_obstacle_1_2.x--;
		rect_obstacle_1_3.x--;
		rect_obstacle_1_4.x--;

		if (rect_obstacle_1_1.x <= 0)

		{

			moveright = true;

			count_1++;

		}

	}

	if (movedown == true)

	{

		rect_obstacle_1_1.y++;
		rect_obstacle_1_2.y++;
		rect_obstacle_1_3.y++;
		rect_obstacle_1_4.y++;

		if (rect_obstacle_1_1.y + rect_obstacle_1_1.h >= SCREEN_HEIGHT)

		{

			movedown = false;

			count_1++;

		}

	}

	else

	{

		rect_obstacle_1_1.y--;
		rect_obstacle_1_2.y--;
		rect_obstacle_1_3.y--;
		rect_obstacle_1_4.y--;

		if (rect_obstacle_1_1.y <= 0)

		{

			movedown = true;

			count_1++;

		}

	}

}



void updatePosition_1()

{ 

	if (moveright_1 == true)

	{

		rect_obstacle_2_1.x++;
		rect_obstacle_2_2.x++;
		rect_obstacle_2_3.x++;
		rect_obstacle_2_4.x++;

		if (rect_obstacle_2_1.x + rect_obstacle_2_1.w >= SCREEN_WIDTH)

		{

			moveright_1 = false;
			count_2++;

		}

	}

	else

	{

		rect_obstacle_2_1.x--;
		rect_obstacle_2_2.x--;
		rect_obstacle_2_3.x--;
		rect_obstacle_2_4.x--;

		if (rect_obstacle_2_1.x <= 0)

		{

			moveright_1 = true;
			count_2++;

		}

	}

	if (movedown_1 == true)

	{

		rect_obstacle_2_1.y++;
		rect_obstacle_2_2.y++;
		rect_obstacle_2_3.y++;
		rect_obstacle_2_4.y++;

		if (rect_obstacle_2_1.y + rect_obstacle_2_1.h >= SCREEN_HEIGHT)

		{

			movedown_1 = false;
			count_2++;

		}

	}

	else

	{

		rect_obstacle_2_1.y--;
		rect_obstacle_2_2.y--;
		rect_obstacle_2_3.y--;
		rect_obstacle_2_4.y--;

		if (rect_obstacle_2_1.y <= 0)

		{

			movedown_1 = true;
			count_2++;

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

			count_3++;

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

			count_3++;

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

			count_3++;

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

			count_3++;

			movedown_2 = true;

		}

	}

}

void update_square (int a)

{

	if (a == 1 && rect_player.y >= 0)

	{

		rect_player.y = rect_player.y - 10;

	}

	if (a == 2 && rect_player.y + rect_player.h <= SCREEN_HEIGHT)

	{

		rect_player.y = rect_player.y + 10;

	}

	if (a == 3 && rect_player.x >= 0)

	{

		rect_player.x = rect_player.x - 10;

	}

	if (a == 4 && rect_player.x + rect_player.w <= SCREEN_WIDTH)

	{

		rect_player.x = rect_player.x + 10;

	}

}

bool quit = false;

void check ()

{

	if (SDL_HasIntersection(&rect_obstacle_1_1, &rect_player) == true)

	{

		quit = true;

	}

	if (SDL_HasIntersection(&rect_obstacle_2_1, &rect_player) == true)

	{

		quit = true;

	}
	if (SDL_HasIntersection(&rect_change_1, &rect_player) == true)

	{

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

	rect_obstacle_1_1.x = 300;

    rect_obstacle_1_1.y = 400;

    rect_obstacle_1_1.h = 42;

    rect_obstacle_1_1.w = 42;
    
    rect_obstacle_1_2.x = 300;

    rect_obstacle_1_2.y = 400;

    rect_obstacle_1_2.h = 42;

    rect_obstacle_1_2.w = 42;
    
    rect_obstacle_1_3.x = 300;

    rect_obstacle_1_3.y = 400;

    rect_obstacle_1_3.h = 42;

    rect_obstacle_1_3.w = 42;
    
    rect_obstacle_1_4.x = 300;

    rect_obstacle_1_4.y = 400;

    rect_obstacle_1_4.h = 42;

    rect_obstacle_1_4.w = 42;

    // obstacle_2

    rect_obstacle_2_1.x = 0;

    rect_obstacle_2_1.y = 0;

    rect_obstacle_2_1.h = 42;

    rect_obstacle_2_1.w = 42;
    
    rect_obstacle_2_2.x = 0;

    rect_obstacle_2_2.y = 0;

    rect_obstacle_2_2.h = 42;

    rect_obstacle_2_2.w = 42;
    
    rect_obstacle_2_3.x = 0;

    rect_obstacle_2_3.y = 0;

    rect_obstacle_2_3.h = 42;

    rect_obstacle_2_3.w = 42;
    
    rect_obstacle_2_4.x = 0;

    rect_obstacle_2_4.y = 0;

    rect_obstacle_2_4.h = 42;

    rect_obstacle_2_4.w = 42;

    // player

    rect_player.x = 300;

    rect_player.y = 300;

    rect_player.h = 42;

    rect_player.w = 42;

     // obstacle_1

	rect_change_1.x = 100;

    rect_change_1.y = 100;

    rect_change_1.h = 42;

    rect_change_1.w = 42;

    // obstacle_1

	rect_change_2.x = 100;

    rect_change_2.y = 100;

    rect_change_2.h = 42;

    rect_change_2.w = 42;

    // obstacle_1

	rect_change_3.x = 100;

    rect_change_3.y = 100;

    rect_change_3.h = 42;

    rect_change_3.w = 42;

    // obstacle_1

	rect_change_4.x = 100;

    rect_change_4.y = 100;

    rect_change_4.h = 42;

    rect_change_4.w = 42;

}

void starting()
{
	rect_black_start.x = 0;

    rect_black_start.y = 0;

    rect_black_start.h = SCREEN_HEIGHT;

    rect_black_start.w = SCREEN_WIDTH;
    
 	rect_red_start.x = 0;

    rect_red_start.y = 0;

    rect_red_start.h = SCREEN_HEIGHT;

    rect_red_start.w = SCREEN_WIDTH;
    
	SDL_Event event_start;
	black_start_texture = SDL_CreateTextureFromSurface(rend,black_start);
	red_start_texture = SDL_CreateTextureFromSurface(rend,red_start);
	bool flag = false;
	while (flag == false)
	{
		
		while (SDL_PollEvent(&event_start))
		{
			if (event_start.type == SDL_QUIT)
			{
			flag = true;

			}
			else if( event_start.type == SDL_MOUSEBUTTONDOWN )
            {
            	SDL_RenderCopy(rend,red_start_texture,NULL,&rect_red_start);
            	SDL_RenderPresent(rend);
            	SDL_Delay(500);
                flag = true;
            }
		}
		SDL_RenderCopy(rend,black_start_texture,NULL,&rect_black_start);
		SDL_RenderPresent(rend);
	}
	
}

void over()
{
	rect_gameover.x = 0;

    rect_gameover.y = 0;

    rect_gameover.h = SCREEN_HEIGHT;

    rect_gameover.w = SCREEN_WIDTH;
    
	SDL_RenderCopy(rend,gameover_texture,NULL,&rect_gameover);
    SDL_RenderPresent(rend);
    SDL_Delay(1000);
    
} 

void going()

{

	SDL_Event event;

   	rend = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

    SDL_RenderClear(rend);

    // create texture

	obstacle_1_1_texture = SDL_CreateTextureFromSurface(rend,obstacle_1_1);
	obstacle_1_2_texture = SDL_CreateTextureFromSurface(rend,obstacle_1_2);
	obstacle_1_3_texture = SDL_CreateTextureFromSurface(rend,obstacle_1_3);
	obstacle_1_4_texture = SDL_CreateTextureFromSurface(rend,obstacle_1_4);

	obstacle_2_1_texture = SDL_CreateTextureFromSurface(rend,obstacle_2_1);
	obstacle_2_2_texture = SDL_CreateTextureFromSurface(rend,obstacle_2_2);
	obstacle_2_3_texture = SDL_CreateTextureFromSurface(rend,obstacle_2_3);
	obstacle_2_4_texture = SDL_CreateTextureFromSurface(rend,obstacle_2_4);

    player_texture = SDL_CreateTextureFromSurface(rend,player);

    background_texture = SDL_CreateTextureFromSurface(rend,background);
    
    gameover_texture = SDL_CreateTextureFromSurface(rend,gameover);

    change_1_texture = SDL_CreateTextureFromSurface(rend,change_1);

    change_2_texture = SDL_CreateTextureFromSurface(rend,change_2);

    change_3_texture = SDL_CreateTextureFromSurface(rend,change_3);

    change_4_texture = SDL_CreateTextureFromSurface(rend,change_4);

  	// set position
	setposition();
	starting();
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

		// 碰撞检测					

		check();

		// 速度控制 

		if (count_1<10){

			SDL_Delay(5);

		}

		else if (count_1<20){

			SDL_Delay(3);

		}

		else {

			SDL_Delay(1);

		}

		SDL_RenderClear(rend);

		// 生成背景 

		SDL_RenderCopy(rend,background_texture,NULL,&rect_background);
		// player
		SDL_RenderCopy(rend,player_texture,NULL,&rect_player);

		//开始第一个 

		updatePosition();
		if(count_1 % 4 == 0) {

			SDL_RenderCopy(rend,obstacle_1_1_texture,NULL,&rect_obstacle_1_1);

		}

		if(count_1 % 4 == 1) {

			SDL_RenderCopy(rend,obstacle_1_2_texture,NULL,&rect_obstacle_1_2);

		}

		if(count_1 % 4 == 2) {

			SDL_RenderCopy(rend,obstacle_1_3_texture,NULL,&rect_obstacle_1_3);

		}

		if(count_1 % 4 == 3) {

			SDL_RenderCopy(rend,obstacle_1_4_texture,NULL,&rect_obstacle_1_4);

		}

		//碰撞一定次数后开始第二个 

		if(count_1>5) 
		{
			updatePosition_1();
			if(count_2 % 4 == 0) {
				SDL_RenderCopy(rend,obstacle_2_1_texture,NULL,&rect_obstacle_2_1);
			}

			if(count_2 % 4 == 1) {
				SDL_RenderCopy(rend,obstacle_2_2_texture,NULL,&rect_obstacle_2_2);
			}

			if(count_2 % 4 == 2) {
				SDL_RenderCopy(rend,obstacle_2_3_texture,NULL,&rect_obstacle_2_3);
			}

			if(count_2 % 4 == 3) {
				SDL_RenderCopy(rend,obstacle_2_4_texture,NULL,&rect_obstacle_2_4);
			}
		}

		// 开始第三个 
		if (count_1>10)
		{
			updatePosition_2();	
			if(count_3 % 4 == 0) {
				SDL_RenderCopy(rend,change_1_texture,NULL,&rect_change_1);
			}

			if(count_3 % 4 == 1) {
				SDL_RenderCopy(rend,change_2_texture,NULL,&rect_change_2);
			}

			if(count_3 % 4 == 2) {
				SDL_RenderCopy(rend,change_3_texture,NULL,&rect_change_3);
			}
			if(count_3 % 4 == 3) {
				SDL_RenderCopy(rend,change_4_texture,NULL,&rect_change_4);
			}
		}
		SDL_RenderPresent(rend);
	}
	// 结尾时间 
	end = time(NULL);
	// game over
	over(); 

}
