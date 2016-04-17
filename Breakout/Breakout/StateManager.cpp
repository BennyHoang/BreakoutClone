#include "StateManager.h"



StateManager::StateManager()
{
}

bool StateManager::getInGame()
{
	return m_in_game;
}

bool StateManager::getInMenu()
{
	return m_in_menu;
}

bool StateManager::getFirstLevel()
{
	return m_first_level;
}

bool StateManager::getLoadNewLevel()
{
	return m_load_new_level;
}

bool StateManager::getGameOver()
{
	return m_game_over;
}

bool StateManager::canShoot()
{
	bool returnValue = m_can_shoot;
	m_can_shoot = false;
	return returnValue;
}

void StateManager::setCanShoot()
{
	m_can_shoot = true;
}

void StateManager::setGameOver(bool game_over)
{
	m_game_over = game_over;
}

void StateManager::setInMenu(bool in_menu)
{
	m_in_menu = in_menu;
}

void StateManager::setFirstLevel(bool first_level)
{
	m_first_level = first_level;
}

void StateManager::setLoadNewLevel(bool new_level)
{
	m_load_new_level = new_level;
}

void StateManager::setInGame(bool in_game)
{
	m_in_game = in_game;
}


StateManager::~StateManager()
{
}
