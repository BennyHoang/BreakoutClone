#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "TextService.h"
#include <string>
//#include "Breakout.h"


class Menu
{
public:
	Menu();
	void init(SDL_Renderer* gRender, SDL_Window* gWindow, TTF_Font* font);
	void update();
	~Menu();
private:

	std::string text = "Gruppe 6";

	TTF_Font* m_font;
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	TextService gTextTexture;
};

