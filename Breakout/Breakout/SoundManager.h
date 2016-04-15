#pragma once

#include <SDL.h>
#include <SDL_mixer.h>

class SoundManager {
private:
	// Background song
	Mix_Music *bgm = Mix_LoadMUS("backgroundMusic.mp3");

	// Sound effects
	Mix_Chunk *seOne = Mix_LoadWAV("explo01.wav");
	Mix_Chunk *seTwo = Mix_LoadWAV("explo02.wav");
	Mix_Chunk *seThree = Mix_LoadWAV("explo03.wav");

public:
};