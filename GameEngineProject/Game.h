#ifndef Game_h
#define Game_h
#include "SDL.h"
#include <stdio.h>
#include <iostream>

class Game {		 //Class for updating in SDL and everything else

public:
	Game(); //Constructor, construct the game object
	~Game(); //Deconstructor

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();

	//function to let the main function know that the game should be still running
	bool running() { return isRunning; }

private:
	int count = 0;
	// ask the Game class whether it´s true then handle all the events and update render
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};

#endif /*Game_h*/#pragma once
