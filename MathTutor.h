#ifndef MATHTUTOR_H
#define MATHTUTOR_H

#include <string> // needed to use string
#include <tuple> // store variabke types
#include <iostream> // for cout and cin, and plus left and right alignment
#include <ctime>  // seed the random
#include <algorithm> // allows us to use the max function
#include <vector> // needed to use vectors
#include <iomanip>  // need for setw

// Function declarations (prototypes)

void displayIntro();
void getUserName(std::string& username);
void maxAttemptsPrompt(int& maxAttempts);
std::tuple<std::string, int> generateQuestion(const int& currentLevel, const int& levelRangeIncrement);
bool getAnswer(const std::string question, const int answer, int& currentAttempt, const int& maxAttempts);
void levelChange(const int& totalCorrect, const int& totalIncorrect, const int& levelChangeAttempts, int& currentLevel);
bool playAgain();
void summary(const std::vector<std::tuple<int, std::string, int, int, bool>>& questionList, int totalAttempts, const int& totalCorrect, const int& totalIncorrect);

#endif // MATHTUTOR_H