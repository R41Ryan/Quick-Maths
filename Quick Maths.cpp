#include <iostream>

// Clears the input buffer.
void clear() {
    while (getchar() != '\n');
}

/*
* Prompts the user to input the min and max absolute boundaries for the operands.
*/
void promptBoundaries(int& min, int& max) {
    bool valid = false;
    while (!valid) {
        std::cout << "\nPlease enter the maximum value for operand\n";
        std::cin >> max;
        clear();
        std::cout << "\nPlease enter the minimum value for operand\n";
        std::cin >> min;
        clear();

        if (max < 0 || min < 0) {
            std::cout << "\nYou cannot have negative values for the absolute max and/or min operands\n\n";
        }
        else if (max == 0) {
            std::cout << "\nThe maximum value cannot be 0.\n\n";
        }
        else if (max < min) {
            std::cout << "\nThe maximum value cannot be less then the minimum values.\n\n";
        }
        else {
            valid = true;
        }
    }
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
        std::cout << "Correct!\n";
        return true;
    }
    else {
        std::cout << "Incorrect! Answer was " << answer << std::endl;
        return false;
    }
}

int main()
{
    bool quit = false;
    while (!quit) {
        int max, min;
        promptBoundaries(min, max);
        testIntAddition(min, max);
    }
}