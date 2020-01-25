#include "Game.h"

Game* game = nullptr;

int main(int argc, char* args[])
{
	game = new Game();
	game->init("MyGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);  // true or false for fullscreen

	// THE GAME LOOP
	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}