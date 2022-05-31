#include "Scoreboard.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ratio>

Scoreboard::Scoreboard()
{
	scoreList = new DoubleLinkedList<Score>();
	scoreCount = 0;
}

Scoreboard::~Scoreboard()
{
	delete scoreList;
}

void Scoreboard::addScore(Score* score)
{
	scoreList->addItem(score);
	scoreCount++;
}

void Scoreboard::addScore(int correct, int total, double time, int type, std::string name)
{
	Score* toAdd = new Score(correct, total, time, type, name);
	scoreList->addItem(toAdd);
	scoreCount++;
}

void Scoreboard::clearScoreboard()
{
	while (scoreList->getCount() > 0)
	{
		scoreList->removeItem();
	}
	scoreCount = 0;
}

void Scoreboard::print()
{
	std::cout << "           Name";
	std::cout << "|  Correct";
	std::cout << "|    Total";
	std::cout << "|    Time (sec)";
	std::cout << "|          Type";
	std::cout << "|         Score";
	std::cout << "|               Date and Time\n";
	for (int i = 0; i < 110; i++)
	{
		std::cout << "-";
	}

	scoreList->movePointerToHead();
	for (int i = 0; i < scoreList->getCount(); i++)
	{
		std::cout << std::endl;
		scoreList->getItem()->print();
		scoreList->pointerNext();
	}
}

void Scoreboard::serialize()
{
	std::ofstream scoreboardOutput("scoreboard_data");
	
	// First Line will be the number of scores in the scoreboard
	scoreboardOutput << scoreCount << "\n";

	scoreList->movePointerToEnd();
	for (int i = 0; i < scoreList->getCount(); i++)
	{
		// Serialize by writing to file seperated by new lines
		Score* toSerialize = scoreList->getItem();
		scoreboardOutput << toSerialize->name.c_str() << "\n";
		scoreboardOutput << toSerialize->correct << "\n" << toSerialize->total << "\n";
		scoreboardOutput << toSerialize->time << "\n";
		scoreboardOutput << toSerialize->type << "\n";
		scoreboardOutput << toSerialize->score << "\n";
		
		// Serialize the date time by converting it into integer values of time since epoch.
		scoreboardOutput << std::chrono::system_clock::to_time_t(toSerialize->dateTime) << "\n";

		scoreList->pointerPrev();

	}
}

void Scoreboard::deserialize()
{
	clearScoreboard();

	std::ifstream scoreboardInput("scoreboard_data");

	if (scoreboardInput.is_open())
	{
		// Retreives the number of scores in the scoreboard_data
		int serializeScoreCount;
		scoreboardInput >> serializeScoreCount;
		for (int i = 0; i < serializeScoreCount; i++)
		{
			Score* toAdd = new Score();
			scoreboardInput >> toAdd->name;
			scoreboardInput >> toAdd->correct;
			scoreboardInput >> toAdd->total;
			scoreboardInput >> toAdd->time;
			scoreboardInput >> toAdd->type;
			scoreboardInput >> toAdd->score;

			std::time_t serializeDateTime;
			if (scoreboardInput >> serializeDateTime)
			{
				auto dateTime = std::chrono::system_clock::from_time_t(serializeDateTime);
				toAdd->dateTime = dateTime;
			}

			addScore(toAdd);
		}
	}
}

void Scoreboard::exportScoreboard()
{
	std::ofstream scoreboardOutput("scoreboard.txt");
	scoreboardOutput << "           Name";
	scoreboardOutput << "|  Correct";
	scoreboardOutput << "|    Total";
	scoreboardOutput << "|    Time (sec)";
	scoreboardOutput << "|          Type";
	scoreboardOutput << "|         Score";
	scoreboardOutput << "|               Date and Time";

	scoreboardOutput << "\n";
	for (int i = 0; i < 110; i++)
	{
		scoreboardOutput << "-";
	}

	scoreList->movePointerToHead();
	for (int i = 0; i < scoreList->getCount(); i++)
	{
		scoreboardOutput << std::endl;

		Score* toSerialize = scoreList->getItem();
		scoreboardOutput << std::setw(15) << toSerialize->name.c_str();
		scoreboardOutput << std::setw(10) << toSerialize->correct;
		scoreboardOutput << std::setw(10) << toSerialize->total;
		scoreboardOutput << std::setw(15) << toSerialize->time;
		switch (toSerialize->type) {
		case 0:
			scoreboardOutput << std::setw(15) << "Addition";
			break;
		case 1:
			scoreboardOutput << std::setw(15) << "Subtraction";
			break;
		case 2:
			scoreboardOutput << std::setw(15) << "Multiplication";
			break;
		case 3:
			scoreboardOutput << std::setw(15) << "Division";
			break;
		default:
			scoreboardOutput << std::setw(15) << "Unknown";
		}
		scoreboardOutput << std::setw(15) << toSerialize->score;
		std::time_t tt = std::chrono::system_clock::to_time_t(toSerialize->dateTime);
		char timeString[30];
		ctime_s(timeString, sizeof(timeString), &tt);
		scoreboardOutput << std::setw(30) << timeString;

		scoreList->pointerNext();
	}
}

void Scoreboard::setScoreList(DoubleLinkedList<Score>* newScoreList)
{
	scoreList = newScoreList;
}

void Scoreboard::setScoreCount(int newCount)
{
	scoreCount = newCount;
}

DoubleLinkedList<Score>* Scoreboard::getScoreList()
{
	return scoreList;
}

int Scoreboard::getScoreCount()
{
	return scoreCount;
}