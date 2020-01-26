#include "Game.h"
//#include "SDL_config_windows.h"  // if I include these for DWORD it gives compiler error...
//#include <sysinfoapi.h>

Game* game = nullptr;

int main(int argc, char* args[])
{

//FRAMERATE
//V1 FPS
	const int FPS = 60;						//closest refresh rate to our monitor
	const int frameDelay = 1000 / FPS;		///how long a frame is ment to take 
	
	Uint32 frameStart;				//Game time, how long is been running
	int frameTime;

//V2 FPS
	/*
	const int TICKS_PER_SECOND = 25;
	const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
	const int MAX_FRAMESKIP = 5;

	DWORD next_game_tick = GetTickCount();
	int loops;
	float interpolation; */


	game = new Game();
	game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 900, 700, false);  // true or false for fullscreen

	// THE GAME LOOP
	while (game->running()) {

		//CONTROL FRAMERATE HERE: get currenttimeMillis() when we first start the frame
//V1 FPS
		frameStart = SDL_GetTicks();  //returns how many miliseconds it´s been since we first initialized SDL

//V2 FPS place update in a while loop 
	/*	loops = 0;
		while (GetTickCount() > next_game_tick&& loops < MAX_FRAMESKIP) {
			game->update();  // game->update();

			next_game_tick += SKIP_TICKS;
			loops++;
		}

		interpolation = float(GetTickCount() + SKIP_TICKS - next_game_tick)
			/ float(SKIP_TICKS);
		display_game(interpolation);  
		*/


		game->handleEvents();
		game->update();		//place this in while loop for V2 FPS
		game->render();

		frameTime = SDL_GetTicks() - frameStart; //returns how long it´s taken to go through handling our events/updating objects and rendering it in miliseconds
		//Now that we know how long frame has been taken, check to see if we need to delay rendering the next frame
		if(frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
		
	}

	game->clean();

	return 0;
}