#include "Menu.h"



Menu::Menu()
{
}

void Menu::init(SDL_Renderer * gRender, SDL_Window * gWindow, TTF_Font * font)
{
	m_font = font;
	m_renderer = gRender;
	m_window = gWindow;
	gTextTexture.init(m_font, m_window, m_renderer);
}

void Menu::update()
{
	SDL_Color textColor = { 255, 255, 255, 255 };
	//gText.loadFromRenderedText(std::to_string(score), textColor);
	gTextTexture.loadFromRenderedText(text, textColor);
	gTextTexture.render(1024 / 2, 768 / 2);
}


Menu::~Menu()
{
}
