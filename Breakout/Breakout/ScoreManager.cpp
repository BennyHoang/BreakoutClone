#include "ScoreManager.h"
#include <sstream>


void ScoreManager::OpenFile(std::string filename)
{
	std::ofstream fileOut;
	fileOut.open(filename, std::fstream::app);
	/*for (int i = 0; i < 5; i++)
	{
		fileOut << "Highscore:" << 1 * 3 << std::endl;
	}*/

	fileOut << "score: " << m_score <<std::endl;
	fileOut.close();
}

void ScoreManager::ReadFile(std::string filename)
{
	/*
	std::ofstream fileIn;
	fileIn.open(filename, std::fstream::in);
	std::stringstream buffer;
	buffer << fileIn.rdbuf();

	std::string contents(buffer.str());
	OutputScore(contents);
	*/



	
	std::ifstream fileIn(filename);
	std::string score;

	std::stringstream buffer;
	buffer << fileIn.rdbuf();

	std::string token;

		while(std::getline(buffer, token, '\n' ))
		{
			OutputScore(token);
		}

	
	fileIn.close();
	
}

void ScoreManager::SetScore(int score)
{
	m_score = score;
}

void ScoreManager::OutputScore(std::string score)
{
	m_output_score = score;
}
std::string ScoreManager::GetOutputScore()
{
	return m_output_score;
}

