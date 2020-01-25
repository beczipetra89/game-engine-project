#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {//Constructor

}
Game::~Game() {//Deconstructor

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0; //if we want fullscreen, just set this flag value
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Main loop

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)  // Initialilze SDL subsystems, ==0 if it´s successful
	{
		std::cout << "Subsystems Initialized....." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);  // CREATE A WINDOW
		if (window)
		{
			std::cout << "Window created!" << std::endl;  //make sure the window is created properly
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 60, 0, 122, 255);  //window background color (r,g,b,alpha)
			std::cout << "Renderer created" << std::endl;  //make sure the renderer is created properly
		}

		isRunning = true;  //if initializer is set correctrly, then isRunning set to true, else false
	}
	else {
		isRunning = false;
	}
}

//Initialize SDL

//Handle all the events
void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event); //address because don´t know what event
	// Run a switch statement to find out the type of event
	switch (event.type) {
	case SDL_QUIT:     //when click X on the window, this generates this event SDL_QUIT and stop the game from running on its next loop
		isRunning = false;
		break;
	default:
		break;
	}


}
void Game::update()
{
	count++; //every time this get´s updated, it iwll increment the counter by 1
	std::cout << count << std::endl;
}

//Render the objects to the screen
void Game::render()
{
	//Clear the renderer´s buffer
	SDL_RenderClear(renderer);
	// This is where to add things to the render------------------------
	SDL_RenderPresent(renderer);
}

// Clean up after quitting the game
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
