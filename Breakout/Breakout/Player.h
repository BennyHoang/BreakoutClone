#pragma once
class Player
{
public:
	Player();
	void updateScore(int score);
	int getScore();
	int getLives();
	void updateLives();
	bool isAlive();
	void newLives();
	~Player();
private:
	int m_lives = 5;
	int m_score = 0;
	bool m_alive = true;
};

