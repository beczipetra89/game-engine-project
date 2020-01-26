#pragma once
// PlayerGameObject class to avoid messing in the main class
#include "Game.h"

class PlayerGameObject {
public:
	PlayerGameObject(const char* texturesheet, int x, int y);
	~PlayerGameObject();
	  
	void Update(); //so each object´s can have its own update function
	void Render();


private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};
