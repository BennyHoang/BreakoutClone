#pragma once

#include <SDL.h>
/*
	This object handles collissions betweeen squares
*/

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
	bool hasCollided(SDL_Rect* a, SDL_Rect* b);
};

