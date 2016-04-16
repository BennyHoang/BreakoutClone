#pragma once
#include <iostream>
#include <fstream>
#include <string>


class ScoreManager
{
public:
	void OpenFile(std::string filename);
	void ReadFile(std::string filename);
	void SetScore(int score);

private:
	int m_score;
};

