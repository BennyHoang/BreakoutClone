#pragma once
class StateManager
{
public:
	StateManager();
	bool getInGame();
	bool getInMenu();
	bool getFirstLevel();
	bool getLoadNewLevel();
	bool getGameOver();
	bool canShoot();
	void setCanShoot();
	void setGameOver(bool game_over);
	void setInMenu(bool in_menu);
	void setFirstLevel(bool first_level);
	void setLoadNewLevel(bool new_level);
	void setInGame(bool in_game);
	~StateManager();
private:
	bool m_in_game = false;
	bool m_in_menu = true;
	bool m_first_level = false;
	bool m_load_new_level = false;
	bool m_game_over = false;
	bool m_can_shoot = false;
};

