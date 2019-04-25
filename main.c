#include "game.h"
#include "media.h"
#include "record.h"
#include <stdio.h>

extern time_t start,end;

int main( int argc, char* args[] )
{
	// Get the player name and store it 
	get_new();
	// Start up SDL and create window
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
		    // Free resources and close SDL
		    close();
		    // show the time
		    print_time (start,end);
		    // Ranking and Recording
		    readfile(); 
		    // checking and sorting
		    compare();
		    // store record
			writefile();
			// show record
			show_record();
    
		}		
    }
	return 0;
}


