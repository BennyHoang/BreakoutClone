#pragma once


#include "SDL.h"
#include "SDL_ttf.h"

class TextService
{
public:
	TextService();
	~TextService();
	bool init();
private:
	TTF_Font* m_font;
	SDL_Surface* m_message;
	SDL_Texture* m_text;
	SDL_Rect m_textRect;
	SDL_Color m_textcolor;

};