#ifndef Game_h
#define Game_h
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>

class Game {		 //Class for updating in SDL and everything else

public:
	Game(); //Constructor, construct the game object
	~Game(); //Deconstructor

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	bool running() { return isRunning; } //function to let the main function know that the game should be still running
	void render();
	void clean();

	static SDL_Renderer *renderer;

private:
	
	// ask the Game class whether it´s true then handle all the events and update render
	bool isRunning;
	int count = 0;
	SDL_Window* window;
};

#endif /*Game_h*/#pragma once
