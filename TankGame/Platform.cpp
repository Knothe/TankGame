#include "Platform.h"
#include "SDL.h"
#include <iostream>

SDL_Renderer *Platform::renderer;

Platform::Platform(std::string name)
{
	width = 864; //27 
	//16 x 54
	height = 640; //20
	//16 x 40
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_INIT";
		return;
	}

	window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) 
	{
		std::cout << "CreateWindow";
		SDL_Quit();
		return;
	}


	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		std::cout << "CreateRenderer";
		SDL_Quit();
		return;
	}

}

void PollEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{

	}
}

void Platform::DrawRect(int x, int y, int w, int h)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	//SDL_RenderFillRect(renderer, &rect);
	//SDL_RenderDrawRect(renderer, &rect);
}

void Platform::RenderClear()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}


void Platform::RenderPresent()
{
	SDL_RenderPresent(renderer);
}

void Platform::RenderImage(Image *image, int x, int y)
{
	RenderTexture(image, x, y, 0);
}

void Platform::RenderImage(Image *image, int x, int y, double angle) 
{
	RenderTexture(image, x, y, angle);
}

void Platform::RenderImage(Image *image, Vector vector, double angle)
{
	RenderTexture(image, vector, angle);
}

void Platform::RenderImage(Image *image, Vector vector)
{
	RenderTexture(image, vector, 0);
}

void Platform::RenderTexture(Image *image, int x, int y, double angle)
{
	SDL_Rect srcrect;
	srcrect.x = x;
	srcrect.y = y;
	srcrect.w = image->GetWidth();
	srcrect.h = image->GetHeight();
	SDL_RenderCopyEx(renderer, image->GetTexture(), NULL, &srcrect
		, angle, NULL, SDL_FLIP_NONE);
}

void Platform::RenderTexture(Image *image, Vector vector, double angle)
{
	SDL_Rect srcrect;
	srcrect.x = vector.GetX();
	srcrect.y = vector.GetY();
	srcrect.w = image->GetWidth();
	srcrect.h = image->GetHeight();
	SDL_RenderCopyEx(renderer, image->GetTexture(), NULL, &srcrect
		, angle, NULL, SDL_FLIP_NONE);
}

Platform::~Platform()
{
}

void Platform::CheckEvent(GameState *obj, bool (GameState::*f)(std::vector<int> *, std::vector<int>*))
{
	SDL_Event e;
	std::vector<int> keysDown;
	std::vector<int> keysUp;

	while (SDL_PollEvent(&e)) //El & sirve para obtener la dirección de memoria
	{
		switch (e.type)
		{
		case SDL_KEYDOWN:
			if (e.key.keysym.sym == SDLK_LEFT)
			{
				keysDown.push_back(SDLK_LEFT);
			}
			if (e.key.keysym.sym == SDLK_RIGHT)
			{
				keysDown.push_back(SDLK_RIGHT);
			}
			if (e.key.keysym.sym == SDLK_UP)
			{
				keysDown.push_back(SDLK_UP);
			}
			if (e.key.keysym.sym == SDLK_DOWN)
			{
				keysDown.push_back(SDLK_DOWN);
			}
			if (e.key.keysym.sym == SDLK_RCTRL)
			{
				keysDown.push_back(SDLK_RCTRL);
			}
			if (e.key.keysym.sym == SDLK_a)
			{
				keysDown.push_back(SDLK_a);
			}
			if (e.key.keysym.sym == SDLK_d)
			{
				keysDown.push_back(SDLK_d);
			}
			if (e.key.keysym.sym == SDLK_w)
			{
				keysDown.push_back(SDLK_w);
			}
			if (e.key.keysym.sym == SDLK_s)
			{
				keysDown.push_back(SDLK_s);
			}
			if (e.key.keysym.sym == SDLK_SPACE)
			{
				keysDown.push_back(SDLK_SPACE);
			}
			if (e.key.keysym.sym == 13)
			{
				keysDown.push_back(13);
			}
			if (e.key.keysym.sym == SDLK_ESCAPE)
			{
				keysDown.push_back(SDLK_ESCAPE);
			}
			
			break;
		case SDL_KEYUP:
			if (e.key.keysym.sym == SDLK_LEFT)
			{
				keysUp.push_back(SDLK_LEFT);
			}
			if (e.key.keysym.sym == SDLK_RIGHT)
			{
				keysUp.push_back(SDLK_RIGHT);
			}
			if (e.key.keysym.sym == SDLK_UP)
			{
				keysUp.push_back(SDLK_UP);
			}
			if (e.key.keysym.sym == SDLK_DOWN)
			{
				keysUp.push_back(SDLK_DOWN);
			}
			if (e.key.keysym.sym == SDLK_a)
			{
				keysUp.push_back(SDLK_a);
			}
			if (e.key.keysym.sym == SDLK_d)
			{
				keysUp.push_back(SDLK_d);
			}
			if (e.key.keysym.sym == SDLK_w)
			{
				keysUp.push_back(SDLK_w);
			}
			if (e.key.keysym.sym == SDLK_s)
			{
				keysUp.push_back(SDLK_s);
			}
			break;
		}
	}

	(obj->*f)(&keysDown, &keysUp);
}

