#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int main() {
    srand(time(0)); // seed random number generator
    int numberToGuess = rand() % 100 + 1; // random number between 1 and 100
    int userGuess = 0;
    int attempts = 0;

    cout << "=== Number Guessing Game ===" << endl;
    cout << "I have selected a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    while (userGuess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        if (userGuess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        }
        else if (userGuess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    }

    return 0;
}