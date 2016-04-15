#pragma once

#include <SDL.h>

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	bool hasCollided(SDL_Rect* a, SDL_Rect* b);
};

