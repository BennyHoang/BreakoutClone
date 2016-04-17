#include "Player.h"



Player::Player()
{
}

void Player::updateScore(int score)
{
	m_score += score;
}

int Player::getScore()
{
	return m_score;
}

int Player::getLives()
{
	return m_lives;
}

void Player::updateLives()
{
	m_lives--;
	if (m_lives < 1) m_alive = false;
}

bool Player::isAlive()
{
	return m_alive;
}


Player::~Player()
{
}
