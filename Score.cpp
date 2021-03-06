#include "Score.h"
#include <iostream>
#include <iomanip>

Score::Score(int correct, int total, double time, int type, std::string name) {
	this->correct = correct;
	this->total = total;
	this->time = time;
	this->type = type;
	this->name = name;

	rate = correct / time;
	switch (type) {
	case 0: // Addition Score
		score = ((double)correct / (double)total) * (rate / 0.2);
		break;
	case 1: // Subtraction Score
		score = ((double)correct / (double)total) * (rate / 0.2) * 1.5;
		break;
	case 2: // Multiplication Score
		score = ((double)correct / (double)total) * (rate / 0.2) * 2;
		break;
	case 3: // Division Score
		score = ((double)correct / (double)total) * (rate / 0.2) * 2.5;
		break;
	default:
		score = -1;
	}
	dateTime = std::chrono::system_clock::now();
}

Score::Score()
{
	this->correct = 0;
	this->total = 0;
	this->time = 0;
	this->type = 0;
	this->rate = 0;
	this->score = 0;
}

void Score::print()
{
	std::cout << std::setw(15) << name.c_str();
	std::cout << std::setw(10) << correct;
	std::cout << std::setw(10) << total;
	std::cout << std::setw(15) << time;
	switch (type) {
	case 0:
		std::cout << std::setw(15) << "Addition";
		break;
	case 1:
		std::cout << std::setw(15) << "Subtraction";
		break;
	case 2:
		std::cout << std::setw(15) << "Multiplication";
		break;
	case 3:
		std::cout << std::setw(15) << "Division";
		break;
	default:
		std::cout << std::setw(15) << "Unknown";
	}
	std::cout << std::setw(15) << score;
	std::time_t tt = std::chrono::system_clock::to_time_t(dateTime);
	char timeString[30];
	ctime_s(timeString, sizeof(timeString), &tt);
	std::cout << std::setw(30) << timeString;
}
