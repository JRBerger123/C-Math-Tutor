using namespace std;
#include "MathTutor.h"  // Include the header file


void displayIntro() {
    cout << "   .--..--..--..--..--..--..--..--..--..--..--..--..--..--..--..--. " << endl;
    cout << "  / .. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\" << endl;
    cout << "  \\ \\/\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ \\/ /" << endl;
    cout << "   \\/ /`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'\\/ / " << endl;
    cout << "   / /\\                                                        / /\\ " << endl;
    cout << "  / /\\ \\  __  __       _   _       _____      _               / /\\ \\" << endl;
    cout << "  \\ \\/ / |  \\/  | __ _| |_| |__   |_   _|   _| |_ ___  _ __   \\ \\/ /" << endl;
    cout << "   \\/ /  | |\\/| |/ _` | __| '_ \\    | || | | | __/ _ \\| '__|   \\/ / " << endl;
    cout << "   / /\\  | |  | | (_| | |_| | | |   | || |_| | || (_) | |      / /\\ " << endl;
    cout << "  / /\\ \\ |_|  |_|\\__,_|\\__|_| |_|   |_| \\__,_|\\__\\___/|_|     / /\\ \\" << endl;
    cout << "  \\ \\/ /                                                      \\ \\/ /" << endl;
    cout << "   \\/ /                                                        \\/ / " << endl;
    cout << "   / /\\.--..--..--..--..--..--..--..--..--..--..--..--..--..--./ /\\ " << endl;
    cout << "  / /\\ \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\.. \\/\\ \\" << endl;
    cout << "  \\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `'\\ `' /" << endl;
    cout << "   `--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--'`--' " << endl;
    cout << endl << endl;


    cout << "Here are some fun math facts:" << endl;
    cout << "1. Zero is the only number that cannot be represented by Roman numerals." << endl;
    cout << "2. A 'googol' is the number 1 followed by 100 zeros." << endl;
    cout << "3. The number pi is approximately 3.14159, but it's an irrational number and has an infinite number of decimal places." << endl;
    cout << "4. There are infinitely many prime numbers." << endl;
    cout << "5. The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones." << endl << endl;

    srand(time(0)); //seeding random numbers using system time
}

void getUserName(string& username) { // funtion gets the username and pushes it back to main
    // Instead of returning a new string we just edit the original, using pass by reference 
    cout << "Please enter your name: ";
    cin >> username;
    cout << "Hello " << username << ". Thank you for choosing our Silly Simple Math Tutor!" << endl;
}

// Asks the user how many attempts that they would like to solve the equation
void maxAttemptsPrompt(int& maxAttempts){ 
    cout << "How many attempts would you like for each question? ";
    string input = "";

    while (true) {
        try {
            cin >> input;
            maxAttempts = stoi(input);// stoi converts string to interger
            if (maxAttempts < 0 && maxAttempts > 6) {
                throw "Invalid Input: Interger must be in the range 1 - 5";
            }
            break;
        } catch (string intOutOfRange) {
            cout << intOutOfRange << endl;
        } catch (const invalid_argument& e) {
            cout << "Invalid Input: input must be an integer" << endl;
        } catch (const out_of_range& e) {
            cout << "Invalid Input: input is out of range for an integer" << endl;
        }
    }
}

tuple<string, int> generateQuestion(const int& currentLevel, const int& levelRangeIncrement) {
    int num1 = rand() % (currentLevel * levelRangeIncrement) + 1; // Random number between 1 and 100
    int num2 = rand() % (currentLevel * levelRangeIncrement) + 1; // Random number between 1 and 100
    char operations[] = {'+', '-', '*', '/'};
    char operation = operations[rand() % 4];
    string question = "";
    int answer = 0;
    
    switch (operation) {
        case '+':
            question = to_string(num1) + " + " + to_string(num2);
            answer = num1 + num2;
            break;
        case '-':
            question = to_string(num1) + " - " + to_string(num2);
            answer = num1 - num2;
            break;
        case '*':
            question = to_string(num1) + " * " + to_string(num2);
            answer = num1 * num2;
            break;
        case '/':
            num1 *= num2; // ensures that there will be no remainder
            question = to_string(num1) + " / " + to_string(num2);
            answer = num1 / num2;
            break;
    }

    return make_tuple(question, answer);
}

bool getAnswer(const string question, const int answer, int& currentAttempt, const int& maxAttempts) {
    string userInput = "";
    currentAttempt = 1; 

    if (currentAttempt <= maxAttempts) {
        while (true) {
            try {
                cout << "Attempt [" << currentAttempt << "]: " << question << " = ";
                cin >> userInput;
                if (stoi(userInput) == answer) { // if the user input equals the answer 
                    return true;
                } else { // if the user get the answert wrong it will increment and carry on with the while loop
                    currentAttempt++;
                    cout << "Incorrect answer, try again" << endl;
                    continue;
                }
            } catch (const invalid_argument& e) {
                cout << "Invalid Input: input must be an integer" << endl;
            } catch (const out_of_range& e) {
                cout << "Invalid Input: input is out of range for an integer" << endl;
            }
        }
    } else {
        cout << "You have ran out of attempts";
        return false;
    }
}

void levelChange (const int &totalCorrect, const int &totalIncorrect, const int& levelChangeAttempts, int &currentLevel) {
    currentLevel = max(1, 1 + static_cast<int>(totalCorrect / levelChangeAttempts) - static_cast<int>(totalIncorrect / levelChangeAttempts));
}

bool playAgain() {
    string userInput;
    while (true) {
        try {
            cout << "Do you want to continue (y = yes | n = no)? ";
            cin >> userInput;

            //to lowercase the user's input
            for (int i = 0; i < userInput.size(); i++) {
                userInput.at(i) = tolower(userInput.at(i));
            }

            if (userInput == "y" || userInput == "yes") {
                return true;
            } else if (userInput == "n" || userInput == "no") {
                return false;
            } else {
                cout << "Invalid input, please try again..." << endl;
                cout << endl;
            }
        } catch(...) {
            cout << "Invalid input, please try again..." << endl;
            cout << endl;
        }
    }
}

void summary(const vector<tuple<int, string, int, int, bool>>& questionList, int totalAttempts, const int& totalCorrect, const int& totalIncorrect) {
    // Summary report header
    cout <<  ":::::::::::::::::::::::::::::::::::::" << endl;
    cout <<  "          Summary  Report            " << endl;
    cout <<  ":::::::::::::::::::::::::::::::::::::" << endl;
    cout <<  "Level        Question        Attempts" << endl;
    cout <<  "-------    ------------    ----------" << endl;

    
    for (int i = 0; i < questionList.size(); i++ ) {
        //pull the current row's data ouut into more readable variables
        int currentLevel = get<0>(questionList.at(i));
        string question = get<1>(questionList.at(i));
        int correctAnswer = get<2>(questionList.at(i));
        int numAttempts = get<3>(questionList.at(i));
        bool answeredCorrectly = get<4>(questionList.at(i));

        //This displays the numbers in the summary
        cout << " " << setw(2) << right << currentLevel << "     | ";
        cout << setw(3) << right << question;
        cout << " = " << setw(5) << left << correctAnswer;

        if (answeredCorrectly) {
            cout << setw(5) << right << numAttempts;
        } else {
            cout << setw(5) << right << "Incorrect";
        }

        cout << endl;
    }
    
    int combinedAttempts = totalCorrect + totalIncorrect;

    cout <<  "_____________________________________" << endl;

    cout << "Total Questions:" << setw(5) << right << totalIncorrect + totalCorrect << endl;
    cout << "Total Correct  :" << setw(5) << totalCorrect << endl;
    cout << "Total Incorrect:" << setw(5) << totalIncorrect << endl;
    cout << "Average Correct:" << setw(5) << (totalCorrect * 100)/combinedAttempts << "%" << endl;
    cout <<endl;
    cout <<  ":::::::::::::::::::::::::::::::::::::" << endl;
}
