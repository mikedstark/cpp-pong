#include "SDL2/SDL.h"

#include <iostream>
using namespace std;

// Close with red button

void delaySecs( int sec ){
	int ms = sec * 1000;
 	SDL_Delay( ms );
	return;
}

int main ( int argc, char *argv[] ){
	
	SDL_Init ( SDL_INIT_EVERYTHING );
    SDL_Window *window;
    window = SDL_CreateWindow( "Pong",
        					  	SDL_WINDOWPOS_CENTERED,	// x position
        						SDL_WINDOWPOS_CENTERED,  	// y position
       							640,     					// width
        						480,                        // height
        						SDL_WINDOW_RESIZABLE	);

	if ( window == NULL ){
		cout << "Error initializing window" << endl
		<< SDL_GetError() << endl;
	}


	SDL_Event event;
	bool gameLoop = true;

	while ( gameLoop ){
		while ( SDL_PollEvent( &event ) ){
			if ( event.type == SDL_QUIT ){
				gameLoop = false;
				break;
			}
		}
	}

	SDL_DestroyWindow( window );
	SDL_Quit();

	return 0;
}