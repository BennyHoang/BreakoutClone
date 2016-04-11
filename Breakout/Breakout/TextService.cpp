#include "TextService.h"
#include <iostream>

void TextService::init(SDL_Window* window, SDL_Renderer* gRenderer, int textRectW, int textRectH, int color_r, int color_g, int color_b, int color_alpha)
{
	m_window = window;
	m_gRenderer = gRenderer;
	
	setSize(textRectW, textRectH);
	setTextColor(color_r, color_g, color_b, color_alpha);

}

bool TextService::initControll()
{
	if (TTF_Init() == -1)
	{
		return false;
	}
	if (loadFont() == false)
	{
		return false;
	}
	CreateTextures();
	return true;
}

bool TextService::loadFont()
{
	m_font = TTF_OpenFont("Sketchy.ttf", 20);
	if(m_font == NULL)
	{
		std::cout << " Failed to load font : " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

bool TextService::CreateRenderer()
{
	m_gRenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

	if (m_gRenderer == NULL)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}
	return true;
}

void TextService::setTextColor(Uint8 r, Uint8 g, Uint8 b, Uint8 opacity)
{
	m_textColor = { r,g,b,opacity };
}

void TextService::setSize(int w, int h)
{
	m_textRect.w = w;
	m_textRect.h = h;
}

void TextService::Render()
{
	SDL_RenderClear(m_gRenderer);
	SDL_RenderCopy(m_gRenderer, m_texture, nullptr, &m_textRect);
	//(m_gRenderer);
}


void TextService::CreateTextures()
{
	SDL_Surface* solid = TTF_RenderText_Solid(m_font, "Text bro", m_textColor);
	m_texture = SurfaceToTexture(solid);
	SDL_QueryTexture(m_texture, NULL, NULL, &m_textRect.w, &m_textRect.h);
	m_textRect.x = 0;
	m_textRect.y = 0;

}

SDL_Texture* TextService::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;
	text = SDL_CreateTextureFromSurface(m_gRenderer, surf);
	SDL_FreeSurface(surf);
	return text;
}
