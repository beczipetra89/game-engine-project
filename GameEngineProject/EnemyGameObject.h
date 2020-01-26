#pragma once
// EnemyGameObject
#include "Game.h"

class EnemyGameObject {
public:
	EnemyGameObject(const char* texturesheet, int x, int y);
	~EnemyGameObject();

	void Update(); //so each object´s can have its own update function
	void Render();


private:
	int xpos;
	int ypos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
}; 
