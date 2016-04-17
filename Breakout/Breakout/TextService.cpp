#include "TextService.h"


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
	if (textSurface == NULL)
	{
		printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		mTexture = SDL_CreateTextureFromSurface(mRenderer, textSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
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
	if (mTexture != NULL)
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


//Renders text to screen by position.
void TextService::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	if (clip != NULL)
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