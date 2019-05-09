#pragma once
#include <string>
#include "SDL.h"

class Platform
{
private:
	int width;
	int height;
	SDL_Window *window;
	SDL_Renderer *renderer;


public:
	Platform(std::string name);

	void RenderClear();
	/*void RenderImage(Image *image, int x, int y);
	void RenderImage(Image *image, intx, int y, double angle);*/
	void RenderPresent();

	~Platform();
};

