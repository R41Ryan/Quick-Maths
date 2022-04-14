#include "Options.h"
#include <fstream>

Options::Options()
{
	std::ifstream optionInput("option_data");
	if (optionInput.is_open()) {
		optionInput >> questionLength;
		optionInput >> minValue;
		optionInput >> maxValue;
		optionInput.close();
	}
	else {
		questionLength = 10;
		minValue = 1;
		maxValue = 10;
		saveOptions();
	}
}

void Options::saveOptions()
{
	std::ofstream optionOutput("option_data");
	optionOutput << questionLength << "\n";
	optionOutput << minValue << "\n";
	optionOutput << maxValue << "\n";
	optionOutput.close();
}
