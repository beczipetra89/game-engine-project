#pragma once
//Class to return an SDL textures, Every time when need to load a texture, use this class
#include "Game.h"

class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
};