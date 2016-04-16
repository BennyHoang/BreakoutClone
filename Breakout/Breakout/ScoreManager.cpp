#include "ScoreManager.h"


void ScoreManager::OpenFile(std::string filename, int score)
{
	std::ofstream fileOut;
	fileOut.open(filename);
	/*for (int i = 0; i < 5; i++)
	{
		fileOut << "Highscore:" << 1 * 3 << std::endl;
	}*/

	fileOut << "score: " << score <<std::endl;
	fileOut.close();
}

void ScoreManager::ReadFile(std::string filename)
{
	std::ifstream fileIn(filename);
	std::string score;
	while(!fileIn.eof())
	{
		std::getline(fileIn, score);
		std::cout << score << std::endl;
	}
}

void ScoreManager::SetScore(int score)
{
	m_score = score;
}
