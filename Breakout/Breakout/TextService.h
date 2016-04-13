#pragma once


#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>

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
	/*
public:
	void init(SDL_Window* window, SDL_Renderer* gRenderer, int textRectW, int textRectH, int color_r, int color_g, int color_b, int color_alpha);
	bool initControll();
	bool loadFont();
	bool CreateRenderer();
	void setTextColor(Uint8 r, Uint8 g, Uint8 b, Uint8 opacity);
	void setSize(int w, int h);
	void Render();;
	void CreateTextures();
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
private:
	TTF_Font* m_font = NULL;
	SDL_Texture* m_texture = NULL;
	SDL_Rect m_textRect;
	SDL_Color m_textColor;

	SDL_Window* m_window = NULL;
	SDL_Renderer* m_gRenderer = NULL;
*/

};