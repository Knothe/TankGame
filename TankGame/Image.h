#pragma once
#include "SDL.h"
#include <iostream>

class Image
{
private:
	SDL_Texture *image;
	std::string name;
	int h;
	int w;

public:
	void LoadImage(std::string name);
	SDL_Texture *GetTexture();
	int GetWdith();
	int GetHeight();

};

