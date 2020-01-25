#include "Game.h"

Game* game = nullptr;

int main(int argc, char* args[])
{

	//FRAMERATE

	const int FPS = 60;						//closest refresh rate to our monitor
	const int frameDelay = 1000 / FPS;		///how long a frame is ment to take 
	
	Uint32 frameStart;				//Game time, how long is been running
	int frameTime;

	game = new Game();
	game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);  // true or false for fullscreen

	// THE GAME LOOP
	while (game->running()) {

		//CONTROL FRAMERATE HERE: get currenttimeMillis() when we first start the frame
		frameStart = SDL_GetTicks();  //returns how many miliseconds it´s been since we first initialized SDL

		game->handleEvents();
		game->update();
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