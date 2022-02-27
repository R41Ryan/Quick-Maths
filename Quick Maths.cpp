#include <iostream>

// Clears the input buffer.
void clear() {
    while (getchar() != '\n');
}

/*
* Prompts the user to input the min and max absolute boundaries for the operands.
*/
void promptBoundaries(int& min, int& max) {
    std::cout << "Please enter the maximum value for operand\n";
    std::cin >> max;
    clear();
    std::cout << "Please enter the minimum value for operand\n";
    std::cin >> min;
    clear();
}

/*
* Provides a random integer addition question for the user to inputand returns either true or false, depending on whether they got it right.
* min and max indicate the lowest and highest absolute values for the addends.
*/
bool testIntAddition(int min, int max) {
    srand(time(0));
    int operand1 = rand() % max + min;
    int operand2 = rand() % max + min;
    int answer = operand1 + operand2;
    int userInput;
    std::cout << operand1 << " + " << operand2 << " = ?" << std::endl;
    std::cin >> userInput;
    clear();
    if (userInput == answer) {
        std::cout << "Correct!" << std::endl;
        return true;
    }
    else {
        std::cout << "Incorrect! Answer was " << answer << std::endl;
        return false;
    }
}

int main()
{
    int max, min;
    promptBoundaries(min, max);
    testIntAddition(min, max);
}