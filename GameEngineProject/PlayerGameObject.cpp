#include "PlayerGameObject.h"
#include "TextureManager.h"
#include "SDL.h"

PlayerGameObject::PlayerGameObject(const char* texturesheet, int x, int y)
{
	//When making a copy of the PlayerGameObject, need to assign a renderer and texture
	//Creating an object

	objTexture = TextureManager::LoadTexture(texturesheet);

	//Set initial position
	xpos = x;
	ypos = y;
}

PlayerGameObject::~PlayerGameObject()
{
}

void PlayerGameObject::Update()
{
	
	//xpos++;
	//ypos++;
	
	

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

void PlayerGameObject::Render() 
{
	SDL:SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}


