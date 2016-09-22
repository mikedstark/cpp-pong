#include "SDL2/SDL.h"

#include <iostream>
using namespace std;

// Program doesn't display anything on mac 
// because nothing is being drawn...

void delaySecs( int sec ){
	int ms = sec * 1000;
 	SDL_Delay( ms );
	return;
}

int main( int argc, char *argv[] ){
	
	SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window;
    window = SDL_CreateWindow( "Pong",
        					  	SDL_WINDOWPOS_CENTERED,	// x position
        						SDL_WINDOWPOS_CENTERED,  	// y position
       							640,     					// width
        						480,                        // height
        						SDL_WINDOW_RESIZABLE	);

	if( window == NULL ){
		cout << "Error initializing window" << endl;
		//<< SDL_GetError() << endl;
	}

	delaySecs(5);

	SDL_DestroyWindow( window );
	SDL_Quit();

	return 0;
}