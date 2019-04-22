#include "game.h"
#include "media.h"
#include "record.h"
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

extern time_t start,end;

int main( int argc, char* args[] )
{
	get_new();
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
    // xisnhi
    print_time (start,end);
    readfile(); 
    compare();
	writefile();
	show_record();
    return 0;
}


