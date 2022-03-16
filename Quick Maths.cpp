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
int displayMenu() {
    std::cout <<
        "\nMenu:\n" <<
        "1. Quit\n" <<
        "2. Options\n" <<
        "3. Integer Addition\n" <<
        "4. Integer Subtraction\n" <<
        "5. Integer Multiplication\n" <<
        "6. Integer Division\n";
    int userInput;
    std::cin >> userInput;
    clear();
    return userInput;
}

/*
* Displays the options menu to modify aspects of the game. Returns the integer representing what the user inputted.
*/
int displayOptions(int min, int max, int num) {
    std::cout <<
        "\nOptions:\n" <<
        "1. Back\n" <<
        "2. Change Operands min/max values (min = " << min << ", max = " << max << ")\n" <<
        "3. Change game length (" << num << " question per game)\n";
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
        std::cout << "\nPlease enter the minimum value for operand\n";
        std::cin >> min;
        clear();
        std::cout << "\nPlease enter the maximum value for operand\n";
        std::cin >> max;
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
* Prompts the user to input the number of questions to be asked during a game session.
*/
void promptGameLength(int& num) {
    bool valid = false;
    while (!valid) {
        std::cout << "\nPlease enter the maximum value for operand\n";
        std::cin >> num;
        clear();

        if (num <= 0) {
            std::cout << "\nYou must enter a positive integer.\n\n";
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
* Provides a random integer addition question for the user to answer and returns either true or false, depending on whether they got it right.
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
* Provides a random integer subtraction question for the user to answer and returns either true or false, depending on whether they got it right
* or not. min and max indicate the lowest and highest absolute values for the subtrahend and difference.
*/
bool testIntSubtraction(int min, int max) {
    srand(time(0));
    int subtrahend = rand() % max + min;
    int difference = rand() % max + min;
    int minuend = subtrahend + difference;
    int userInput;
    std::cout << minuend << " - " << subtrahend << " = ?" << std::endl;
    std::cin >> userInput;
    clear();
    if (userInput == difference) {
        std::cout << "Correct!\n\n";
        return true;
    }
    else {
        std::cout << "Incorrect! Answer was " << difference << std::endl << std::endl;
        return false;
    }
}

/*
* Provides a random integer multiplication question for the user to answer and returns either true or false, depending on whether they got it right
* or not. min and max indicate the lowest and highest absolute values for the multiplicands.
*/
bool testIntMultiplication(int min, int max) {
    srand(time(0));
    int multiplicand1 = rand() % max + min;
    int multiplicand2 = rand() % max + min;
    int product = multiplicand1 * multiplicand2;
    int userInput;
    std::cout << multiplicand1 << " X " << multiplicand2 << " = ?" << std::endl;
    std::cin >> userInput;
    clear();
    if (userInput == product) {
        std::cout << "Correct!\n\n";
        return true;
    }
    else {
        std::cout << "Incorrect! Answer was " << product << std::endl << std::endl;
        return false;
    }
}

/*
* Provides a random integer division question for the user to answer and returns either true or false, depending on whether they got it right
* or not. min and max indicate the lowest and highest absolute values for the divisor and quotient.
*/
bool testIntDivision(int min, int max) {
    srand(time(0));
    int divisor = rand() % max + min;
    int quotient = rand() % max + min;
    int dividend = divisor * quotient;
    int userInput;
    std::cout << dividend << " / " << divisor << " = ?" << std::endl;
    std::cin >> userInput;
    clear();
    if (userInput == quotient) {
        std::cout << "Correct!\n\n";
        return true;
    }
    else {
        std::cout << "Incorrect! Answer was " << quotient << std::endl << std::endl;
        return false;
    }
}

/*
* Provides a series of arithmetic questions while keeping score and the rate at which you answer the questions. 
* It then prints the resulting total score percentage and overall rate of answering.
* 
* @parameter type is an integer to indicate what kind of arithmetic questions are to be asked.
* (0 = addition, 1 = subtraction, 2 = multiplication, 3 = division)
* 
* @parameter num is the number of questions to be quizzed.
*/
void arithmeticGame(int min, int max, int type, int num) {
    int score = 0;
    double rate = 0;

    uint64_t t1, t2;
    t1 = timeMilli();
    for (int i = 0; i < num; i++) {
        switch (type) {
        case 0:
            if (testIntAddition(min, max))
                score++;
            break;
        case 1:
            if (testIntSubtraction(min, max))
                score++;
            break;
        case 2:
            if (testIntMultiplication(min, max))
                score++;
            break;
        case 3:
            if (testIntDivision(min, max))
                score++;
            break;
        default:
            std::cout << "Incorrect type inputted.\n\n";
        }
    }
    t2 = timeMilli();
    double seconds = difftime(t2, t1) / 1000.0;
    rate = score / seconds;
    std::cout << "Score: " << score << "/" << num
        << " = " << (float)score/(float)num
        << ", Rate = " << rate << " correct answers per second\n\n";
}

int main()
{
    int min = 1, max = 10, num = 10;
    bool quit = false;
    bool quit2 = false;
    while (!quit) {
        int menuOption = displayMenu();
        switch (menuOption) {
        case 1: // Chose "1. Quit"
            quit = true;
            break;
        case 2: // Chose "2. Change game options"
            quit2 = false;
            while (!quit2) {
                int optionChoice = displayOptions(min, max, num);
                switch (optionChoice) {
                case 1: // Chose "1. Quit"
                    quit2 = true;
                    break;
                case 2: // Chose "2. Change operands"
                    promptBoundaries(min, max);
                    break;
                case 3: // Chose "3. Change length"
                    promptGameLength(num);
                    break;
                default:
                    std::cout << "Invalid inputs\n\n";
                }
            }
            break;
        case 3: // Chose "3. Integer Addition"
            arithmeticGame(min, max, 0, num);
            break;
        case 4: // Chose "4. Integer Subtraction"
            arithmeticGame(min, max, 1, num);
            break;
        case 5: // Chose "5. Integer Multiplication"
            arithmeticGame(min, max, 2, num);
            break;
        case 6: // Chose "6. Integer Division"
            arithmeticGame(min, max, 3, num);
            break;
        default:
            std::cout << "Invalid input.\n\n";
        }
    }
}