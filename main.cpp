using namespace std;
#include "MathTutor.h"

#include <vector>
#include <tuple>

int main() {
    // variables
    vector<tuple<int, string, int, int, bool>> questionList; // stores vector of every tuple of level, question, answer, attempts, and whether user got it correct
    tuple<string, int> otherData; // tuple storing username and max attempts
    tuple<string, int> questionTuple; // tuple storing question and answer
    string userName = "";
    int currentLevel = 1;
    int levelIncrement = 10;
    int levelChangeAttemps = 3;
    int maxAttempts = 3;
    int currentAttempt = 1;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    bool isCorrect = true;
    

    displayIntro();
    getUserName(userName);
    maxAttemptsPrompt(maxAttempts);

    otherData = make_tuple(userName, maxAttempts); 

    while (true) {
        questionTuple = generateQuestion(currentLevel, levelIncrement);
        isCorrect = getAnswer(get<0>(questionTuple), get<1>(questionTuple), currentAttempt, maxAttempts);

        if (isCorrect) {
            totalCorrect += 1;
        } else {
            totalIncorrect += 1;
        }

        questionList.push_back(make_tuple(currentLevel, get<0>(questionTuple), get<1>(questionTuple), currentAttempt, isCorrect));

        levelChange(totalCorrect, totalIncorrect, levelChangeAttemps, currentLevel);

        if (!playAgain()) {
            break;
        }
    }

    summary(questionList, currentAttempt, totalCorrect, totalIncorrect);

    cout<< "Thank you for choosing our Silly Simple Math Tutor!" << endl;
    cout<< "Have a great day " << userName << endl;
    
    return 0;
}
