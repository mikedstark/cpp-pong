#include "SDL2/SDL.h"

#include <iostream>
using namespace std;

#define window_width 800
#define window_height 600
#define fps 60

// Close with red button
// Capped at 60 fps

void cap_frame_rate( Uint32 starting_tick ){
	if ( ( 1000 / fps ) > SDL_GetTicks() - starting_tick ){
		SDL_Delay( 1000 / fps - ( SDL_GetTicks() - starting_tick ) );
	}
}

void update(){
	//cout << "in update" << endl;
}


void draw(){
}

int main ( int argc, char *argv[] ){
	
	SDL_Init ( SDL_INIT_EVERYTHING );
    SDL_Window *window;
    window = SDL_CreateWindow( "Pong",
        					  	SDL_WINDOWPOS_CENTERED,		// x position
        						SDL_WINDOWPOS_CENTERED,  	// y position
       							window_width,
        						window_height,
        						SDL_WINDOW_RESIZABLE	);

	if ( window == NULL ){
		cout << "Error initializing window" << endl
		<< SDL_GetError() << endl;
	}


	// Game Loop
	Uint32 starting_tick;
	SDL_Event event;
	bool gameLoop = true;
	while ( gameLoop ){
		starting_tick = SDL_GetTicks();

		while ( SDL_PollEvent( &event ) ){
			if ( event.type == SDL_QUIT ){
					gameLoop = false;
					break;
			}
		}

		update();
		draw();
		cap_frame_rate( starting_tick );

	} // END Game Loop

	SDL_DestroyWindow( window );
	SDL_Quit();

	return 0;
}