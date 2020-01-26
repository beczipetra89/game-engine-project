//Every time when need to load a texture, use this class

#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture) 
{

	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}
