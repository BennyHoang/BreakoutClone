#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "TextService.h"
#include <string>

/*
	This object handles rendering of main menu screen. Also gets handle by StateManager
*/

class Menu
{
public:
	Menu();
	void init(SDL_Renderer* gRender, SDL_Window* gWindow, TTF_Font* font);
	void update();
	~Menu();
private:

	std::string textHeader = "Breakout Clone Gruppe nO. 6";
	std::string textFooter = "Press \"P\" to play";

	TTF_Font* m_font;
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	TextService gTextTextureHeader;
	TextService gTextTextureFooter;
};

