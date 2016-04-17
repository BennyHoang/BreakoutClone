#pragma once


#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include <stdio.h>
#include <string>

/*
	This object manages rendering text to screen from a true font type. 
	Can also change font if you download your preffered font
*/

class TextService
{
public:
	TextService();
	~TextService();
	void init(TTF_Font* gFont, SDL_Window* window, SDL_Renderer* gRenderer);
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
	void free();
	void setColor(Uint8 r, Uint8 g, Uint8 b);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
	int getWidth();
	int getHeight();
private:
	SDL_Texture* mTexture;
	TTF_Font* mFont;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	int mWidth;
	int mHeight;
};