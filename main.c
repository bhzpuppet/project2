#include "game.h"
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>


int main( int argc, char* args[] )
{
	// ����������� 
	int i;
	char name[10]={0};
	printf("input your player name:");
    scanf ("%s",&name);
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
        	going();
		}
        		
    }

    //Free resources and close SDL
    close();

    return 0;
}


