#include "Menu.h"



Menu::Menu()
{
}

void Menu::init(SDL_Renderer * gRender, SDL_Window * gWindow, TTF_Font * font)
{
	m_font = font;
	m_renderer = gRender;
	m_window = gWindow;
	gTextTextureHeader.init(m_font, m_window, m_renderer);
	gTextTextureFooter.init(m_font, m_window, m_renderer);
}

void Menu::update()
{
	SDL_Color textColor = { 5, 255, 5, 255 };
	//gText.loadFromRenderedText(std::to_string(score), textColor);
	gTextTextureHeader.loadFromRenderedText(textHeader, textColor);
	gTextTextureHeader.render((1024 - gTextTextureHeader.getWidth()) / 2, (768 - gTextTextureHeader.getHeight()) / 2 - (gTextTextureFooter.getHeight() + 00)) ;
	
	gTextTextureFooter.loadFromRenderedText(textFooter, textColor);
	gTextTextureFooter.render((1024 - gTextTextureFooter.getWidth()) / 2, (768 - gTextTextureFooter.getHeight()) / 2 - (gTextTextureFooter.getHeight() - 60));
}


Menu::~Menu()
{
}
