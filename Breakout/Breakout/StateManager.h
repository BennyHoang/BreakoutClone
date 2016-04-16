#pragma once
class StateManager
{
public:
	StateManager();
	bool getInGame();
	bool getInMenu();
	bool getFirstLeve();
	bool getLoadNewLevel();
	bool getGameOver();
	~StateManager();
private:
	bool m_in_game;
	bool m_in_menu;
	bool m_first_level;
	bool m_load_new_level;
	bool m_game_over;
};

