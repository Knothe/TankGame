#pragma once
#include <string>
#include "SDL.h"
#include "Image.h"
#include "GameState.h"
#include "Vector.h"
#include <vector>

class GameState;

class Platform
{
private:
	int width;
	int height;
	SDL_Window *window;
	
public:
	static SDL_Renderer *renderer;

	Platform(std::string name);
	void RenderClear();
	void RenderPresent();
	void RenderImage(Image *image, int x, int y);
	void RenderImage(Image *image, int x, int y, double angle);
	void RenderImage(Image *image, Vector vector, double angle);
	void RenderImage(Image *image, Vector vector);
	void DrawRect(int x, int y, int w, int h);
	void CheckEvent(GameState *obj, bool (GameState::*f)(std::vector<int>*, std::vector<int>*));
	
	
private:
	void RenderTexture(Image *image, int x, int y, double angle);
	void RenderTexture(Image *image, Vector vector, double angle);

	~Platform();
};

