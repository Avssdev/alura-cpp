#include <iostream>

using namespace std;

int main()
{
    cout << "**************************************" << endl;
    cout << "* Welcome to the GUESS THE NUMBER GAME! *" << endl;
    cout << "**************************************" << endl;

    cout << "Choose the difficulty level: " << endl;
    cout << "Easy (E), Medium (M), Hard (H) " << endl;

    char difficultyLevel;
    cin >> difficultyLevel;

    int attemptsNumber;

    switch (difficultyLevel)
    {
        case 'E':
            attemptsNumber = 15;
            break;
        case 'M':
            attemptsNumber = 10;
            break;
        case 'H':
            attemptsNumber = 5;
            break;
        default:
            attemptsNumber = 5;
            break;
    }

    const int SECRET_NUMBER = 42;

    bool isGuessed = false;
    int attempts = 0;
    
    double score = 1000.0;

    while (!isGuessed && attempts < attemptsNumber)
    {
        int picked_number;
        attempts++;

        cout << "Guess the number" << endl;
        cin >> picked_number;
        cout << "You picked the number: " << picked_number << endl;
        cout << "Attempt: " << attempts << endl;

        isGuessed = picked_number == SECRET_NUMBER;

        bool isGreaterThan = picked_number > SECRET_NUMBER;

        double pointsToLose = abs(picked_number - SECRET_NUMBER) / 2.0;
        score = score - pointsToLose;

        if (isGuessed)
        {
            cout << "Congratulations! You won!!" << endl;
        }
        else if (isGreaterThan)
        {
            cout << "Your chose was greater than the secret number!" << endl;
        }
        else
        {
            cout << "Your chose was less than the secret number!" << endl;
        }
    }

    if (!isGuessed) {
        cout << "You lost! Try again." << endl;
    } else {
        cout << "You won in " << attempts << " tries." << endl;
        cout.precision(2);
        cout << fixed << "Your score was " << score << "!" << endl;
    }
}
