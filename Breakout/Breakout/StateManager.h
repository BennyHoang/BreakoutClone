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
	void setGameOver(bool game_over);
	void setInMenu(bool in_menu);
	void setFirstLevel(bool first_level);
	void setLoadNewLevel(bool new_level);
	void setInGame(bool in_game);
	~StateManager();
private:
	bool m_in_game;
	bool m_in_menu;
	bool m_first_level;
	bool m_load_new_level;
	bool m_game_over;
};

