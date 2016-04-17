#pragma once
#include <iostream>
#include <fstream>
#include <string>

/*
	This object handles file I/O and saving score. 
*/

class ScoreManager
{
public:

	void OpenFile(std::string filename);
	void ReadFile(std::string filename);
	void SetScore(int score);
	void OutputScore(std::string score);
	std::string GetOutputScore();

private:
	int m_score;
	std::string m_output_score;
};

