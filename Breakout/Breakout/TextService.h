#pragma once


#include "SDL.h"
#include "SDL_ttf.h"

class TextService
{
public:
	void init(TTF_Font* font, SDL_Window* window, SDL_Renderer* gRenderer, int textRectW, int textRectH, int color_r, int color_g, int color_b, int color_alpha);
	bool initControll();
	bool loadFont();
	bool CreateRenderer();
	void setTextColor(Uint8 r, Uint8 g, Uint8 b, Uint8 opacity);
	void setSize(int w, int h);
	void Render();
	void CreateTextures();
	void Close();
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
private:
	TTF_Font* m_font = NULL;
	SDL_Texture* m_texture = NULL;
	SDL_Rect m_textRect;
	SDL_Color m_textColor;

	SDL_Window* m_window = NULL;
	SDL_Renderer* m_gRenderer = NULL;

};