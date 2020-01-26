#include "GameObject.h"
#include "TextureManager.h"
#include "SDL.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y)
{
	//When making a copy of the GameObject, need to assign a renderer and texture
	//Creating an object

	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);

	//Set initial position
	xpos = x;
	ypos = y;
}

void GameObject::Update()
{
	xpos++;
	ypos++;

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

void GameObject::Render() 
{
	SDL:SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}


