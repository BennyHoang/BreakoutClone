#include "TextService.h"



/*
void TextService::init(SDL_Window* window, SDL_Renderer* gRenderer, int textRectW, int textRectH, int color_r, int color_g, int color_b, int color_alpha)
{
	m_window = window;
	m_gRenderer = gRenderer;
	
	setSize(textRectW, textRectH);
	setTextColor(color_r, color_g, color_b, color_alpha);

}

bool TextService::initControll()
{
	if (!loadFont())	
	{
		return false;
	}
	CreateTextures();
	return true;
}

bool TextService::loadFont()
{
	if (TTF_Init() == -1)
	{
		std::cout << " Failed to load font : " << SDL_GetError() << std::endl;
		return false;
	}

	m_font = TTF_OpenFont("Sketchy.ttf", 20);
	if(m_font == NULL)
	{
		std::cout << " Failed to load font : " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}
/*
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

*/
/*

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
*/
TextService::TextService()
{
	mTexture = NULL;
	mFont = NULL;
	mWindow = NULL;
	mRenderer = NULL;
	mWidth = 0;
	mHeight = 0;
}

void TextService::init(TTF_Font* gFont, SDL_Window* window, SDL_Renderer* gRenderer)
{
	mFont = gFont;
	mWindow = window;
	mRenderer = gRenderer;
}

TextService::~TextService()
{
	free();
}
bool TextService::loadFromRenderedText(std::string textureText, SDL_Color textColor)
{
	free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, textureText.c_str(), textColor);
	if(textSurface == NULL)
	{
		printf("Unable to create texture from rendered text1! SDL Error: %s\n", SDL_GetError());
	}else
	{
		mTexture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
		if(mTexture == NULL)
		{
			printf("Unable to create texture from rendered text2! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			mWidth = textSurface->w;
			mHeight = textSurface->h;
		}

		SDL_FreeSurface(textSurface);
	}

	return mTexture != NULL;
}



void TextService::free()
{
	if(mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
}

void TextService::setColor(Uint8 r, Uint8 g, Uint8 b)
{
	SDL_SetTextureColorMod(mTexture, r, g, b);
}



void TextService::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(mTexture, blending);
}


void TextService::setAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(mTexture, alpha);
}



void TextService::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if(clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(mRenderer, mTexture, clip, &renderQuad, angle, center, flip);

}

int TextService::getWidth()
{
	return mWidth;
}

int TextService::getHeight()
{
	return mHeight;
}


