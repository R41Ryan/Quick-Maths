#pragma once

#include "DoubleLinkedList.h"
#include "Score.h"

class Scoreboard {
	DoubleLinkedList<Score>* scoreList;
	int scoreCount;

public:
	Scoreboard();
	~Scoreboard();

	// Adds a new score
	void addScore(Score* score);

	// Adds a new score
	void addScore(int correct, int total, double time, int type, std::string name = NULL);

	// Clear scoreboard
	void clearScoreboard();

	// Prints the contents of the scoreboard onto the output stream
	void print();

	// Serializes the scoreboard onto a file.
	void serialize();

	// Deserializes the scoreboard from an existing file
	void deserialize();

	// Export the scoreboard as a readable text file.
	void exportScoreboard();

	void setScoreList(DoubleLinkedList<Score>* newScoreList);
	void setScoreCount(int newScore);
	DoubleLinkedList<Score>* getScoreList();
	int getScoreCount();
};