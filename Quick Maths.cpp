#include <iostream>
#include <chrono>

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
* Gets the current time in milliseconds
*/
uint64_t timeMilli() {
    uint64_t timeSinceEpochMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
        ).count();
    return timeSinceEpochMilliseconds;
}

/*
* Provides a random integer addition question for the user to input and returns either true or false, depending on whether they got it right.
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
        std::cout << "Correct!\n\n";
        return true;
    }
    else {
        std::cout << "Incorrect! Answer was " << answer << std::endl << std::endl;
        return false;
    }
}

/*
* Provides a series of arithmetic questions while keeping score and the rate at which you answer the questions.
* It then prints the resulting total score percentage and overall rate of answering.
* 
* @parameter type is an integer to indicate what kind of arithmetic questions are to be asked.
* (0 = addition, 1 = subtraction, 2 = multiplication, 4 = division)
* 
* @parameter num is the number of questions to be quizzed.
*/
void arithmeticGame(int min, int max, int type, int num) {
    int score = 0;
    double rate = 0;

    uint64_t t1, t2;
    t1 = timeMilli();
    for (int i = 0; i < num; i++) {
        if (testIntAddition(min, max))
            score += 1;
    }
    t2 = timeMilli();
    double seconds = difftime(t2, t1) / 1000.0;
    rate = score / seconds;
    std::cout << "Score: " << score << "/" << num
        << " = " << (float)score/(float)num
        << ", Rate = " << rate << "\n\n";
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
            arithmeticGame(min, max, 0, 1);
            break;
        }
    }
}