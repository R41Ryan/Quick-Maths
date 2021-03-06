#pragma once
#include <string>
#include <chrono>

struct Score {
	int correct;
	int total;
	double time;
	int type; // 0 = addition, 1 = subtraction, 2 = multiplicaiton, 3 = division
	std::string name;
	double rate;
	double score;
	std::chrono::time_point<std::chrono::system_clock> dateTime;

	/*
	* Correct = # of correct answers
	* Total = # of total questions
	* Time = Total time of arithmetic game
	* Type = type of arithmetic (0 = addition, 1 = subtraction, 2 = multiplication, 3 = division)
	*/
	Score(int correct, int total, double time, int type, std::string name = NULL);
	Score();
	void print();
};