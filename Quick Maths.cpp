#include <iostream>

// Clears the input buffer.
void clear() {
    while (getchar() != '\n');
}

/*
* This displays a menu with a list of options for the user to choose, and prompts for an input. It returns an integer representing
* what the user inputted.
*/
int displayMenu(int min, int max) {
    std::cout <<
        "Menu:\n" <<
        "1. Quit\n" <<
        "2. Change operand min/max values (min = " << min << ", max = " << max << ")\n" <<
        "3. Integer Addition\n";
    int userInput;
    std::cin >> userInput;
    clear();
    return userInput;
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
    time_t t1, t2;
    srand(time(0));
    int operand1 = rand() % max + min;
    int operand2 = rand() % max + min;
    int answer = operand1 + operand2;
    int userInput;
    std::cout << operand1 << " + " << operand2 << " = ?" << std::endl;
    time(&t1);
    std::cin >> userInput;
    clear();
    time(&t2);
    double seconds = difftime(t2, t1);
    std::cout << "Time Elapsed: " << seconds << " seconds.\n";
    if (userInput == answer) {
        std::cout << "Correct!\n\n";
        return true;
    }
    else {
        std::cout << "Incorrect! Answer was " << answer << std::endl << std::endl;
        return false;
    }
}

int main()
{
    int max = 10, min = 0;
    bool quit = false;
    while (!quit) {
        int menuOption = displayMenu(min, max);
        switch (menuOption) {
        case 1: // Chose "1. Quit"
            quit = true;
            break;
        case 2: // Chose "2. Change operang min/max values"
            promptBoundaries(min, max);
            break;
        case 3: // Chose "3. Integer Addition"
            testIntAddition(min, max);
            break;
        }
    }
}