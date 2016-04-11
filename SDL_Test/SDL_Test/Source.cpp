#include <SDL.h>
#include <SDL_ttf.h>

#include <iostream>

//setup
bool InitEverything();
bool InitSDL();
bool CreateWindow();
bool CreateRenderer();
void SetupRenderer();

//setup TTF
bool SetupTTF(const std::string &fontName);
SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
void CreatTextTextures();

//update
void Render();
void RunGame();

//initializing variables for text rendering

TTF_Font* font;
SDL_Color textColor = { 255,255,255,255 };
SDL_Color backgroundColor = { 0,0,0,255 };

SDL_Texture* solidTexture;
SDL_Texture* blendedTexture;
SDL_Texture* shadedTexture;

SDL_Rect solidRect;
SDL_Rect blendedRect;
SDL_Rect shadedRect;

SDL_Rect windowRect = { 900, 300, 400, 600 };
SDL_Window* window;
SDL_Renderer* renderer;

int main(int argc, char* args[])
{
	if(!InitEverything())
	{
		return -1;
	}
	RunGame();
	TTF_CloseFont(font);
}

void RunGame()
{
	Render();
	std::cout << "Press any key to exit\n";
	std::cin.ignore();
}
void Render()
{
	//clear
	SDL_RenderClear(renderer);
	
	//render or text-objects
	SDL_RenderCopy(renderer, solidTexture, nullptr, &solidRect);
	SDL_RenderCopy(renderer, blendedTexture, nullptr, &blendedRect);
	SDL_RenderCopy(renderer, shadedTexture, nullptr, &shadedRect);

	//render the changes
	SDL_RenderPresent(renderer);
}

//Initialization
bool SetupTTF(const std::string &fontName)
{
	//error msg just like SDL2
	if(TTF_Init() == -1)
	{
		std::cout << "Failed to initialize TTF:" << SDL_GetError() << std::endl;
		return false;
	}

	//load font
	font = TTF_OpenFont(fontName.c_str(), 90);

	//check for Error
	if(font == nullptr)
	{
		std::cout << "Failed to initialize TTF:" << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void CreateTextTextures()
{
	SDL_Surface* solid = TTF_RenderText_Solid(font, "solid", textColor);
	solidTexture = SurfaceToTexture(solid);

	SDL_QueryTexture(solidTexture, NULL, NULL, &solidRect.w, &solidRect.h);
	solidRect.x = 0;
	solidRect.y = 0;

	SDL_Surface* blended = TTF_RenderText_Blended(font, "blended", textColor);
	blendedTexture = SurfaceToTexture(blended);

	SDL_QueryTexture(blendedTexture, NULL, NULL, &blendedRect.w, &blendedRect.h);
	blendedRect.x = 0;
	blendedRect.y = solidRect.y + solidRect.h + 20;

	SDL_Surface* shaded = TTF_RenderText_Shaded(font, "shaded", textColor, backgroundColor);
	shadedTexture = SurfaceToTexture(shaded);

	SDL_QueryTexture(shadedTexture, NULL, NULL, &shadedRect.w, &shadedRect.h);
	shadedRect.x = 0;
	shadedRect.y = blendedRect.y + blendedRect.h + 20;
}

SDL_Texture* SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;
	text = SDL_CreateTextureFromSurface(renderer, surf);
	SDL_FreeSurface(surf);
	return text; 
}

bool InitEverything()
{
	if(!InitSDL())
	{
		return false;
	}
	if(!CreateWindow())
	{
		return false;
	}
	if(!CreateRenderer())
	{
		return false;
	}
	SetupRenderer();
	if(!SetupTTF("sketchy.ttf"))
	{
		return false;
	}
	CreateTextTextures();
	return true;
}

bool InitSDL()
{
	if(SDL_Init(SDL_INIT_EVERYTHING)== -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return false;
	}

	return true;
}

bool CreateWindow()
{
	window = SDL_CreateWindow("Server", windowRect.x, windowRect.y, windowRect.w, windowRect.h, 0);

	if(window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError();
		return false;
	}

	return true;
}

bool CreateRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == nullptr)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError();
		return false;
	}

	return true;
}

void SetupRenderer()
{
	SDL_RenderSetLogicalSize(renderer, windowRect.w, windowRect.h);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
}