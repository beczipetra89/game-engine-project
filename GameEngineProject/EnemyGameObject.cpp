#include "EnemyGameObject.h"
#include "TextureManager.h"
#include "SDL.h"

EnemyGameObject::EnemyGameObject(const char* texturesheet, int x, int y)
{
	//When making a copy of the EnemyGameObject, need to assign a renderer and texture
	//Creating an object

	objTexture = TextureManager::LoadTexture(texturesheet);

	//Set initial position
	xpos = x;
	initialYpos = y;
	ypos = y;
	horizontialSpeed = 2;
	verticalSpeed = 1;
	verticalDirection = -1; // initially we vertical movement is upwards

}

EnemyGameObject::~EnemyGameObject()
{
}

void EnemyGameObject::Update()
{
	
	xpos = xpos-1 * horizontialSpeed;
	if (ypos < initialYpos - 20) {
		// reached upper limit, fly downwards instead
		verticalDirection = 1;
	} else if (ypos > initialYpos + 20) {
		verticalDirection = -1;
	}
	ypos = ypos + verticalSpeed * verticalDirection;

	//SDL_Rect scrRect, destRect; source rectangle: which part of texture to render, detination: where to draw on screen

	srcRect.h = 32;  //player png size and pos
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void EnemyGameObject::Render()
{
SDL:SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
