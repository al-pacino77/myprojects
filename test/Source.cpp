#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Step 1: Set up a list of words
    vector<string> words = { "programming", "computer", "algorithm", "variable", "function" };

    // Step 2: Generate a random index to choose a word
    srand(time(nullptr)); // Seed the random number generator
    int randomIndex = rand() % words.size(); // Generate a random index
    string wordToGuess = words[randomIndex]; // Select the word to guess

    // Step 3: Initialize the game variables
    const int MAX_GUESSES = 6;
    int remainingGuesses = MAX_GUESSES;
    vector<char> guessedLetters;
    string currentWordState(wordToGuess.length(), '_'); // Create a string with underscores to represent the current state of the word

    // Step 4-7: Repeat steps 4-6 until the user either guesses the word or runs out of guesses
    while (remainingGuesses > 0 && currentWordState != wordToGuess) {
        // Print the current state of the game
        cout << "Word to guess: " << currentWordState << endl;
        cout << "Guessed letters: ";
        for (char letter : guessedLetters) {
            cout << letter << " ";
        }
        cout << endl;
        cout << "Remaining guesses: " << remainingGuesses << endl;

        // Step 4: Prompt the user to guess a letter
        cout << "Guess a letter: ";
        char guessedLetter;
        cin >> guessedLetter;

        // Step 5: Check if the letter is in the word
        bool isLetterInWord = false;
        for (int i = 0; i < wordToGuess.length(); i++) {
            if (wordToGuess[i] == guessedLetter) {
                currentWordState[i] = guessedLetter;
                isLetterInWord = true;
            }
        }

        // Step 6: If the letter is not in the word, decrease the number of guesses by 1
        if (!isLetterInWord) {
            remainingGuesses--;
        }

        // Add the guessed letter to the list of guessed letters
        guessedLetters.push_back(guessedLetter);
    }

    // Step 8-9: If the user guesses the word or runs out of guesses, print a message indicating the result
    if (currentWordState == wordToGuess) {
        cout << "Congratulations! You guessed the word: " << wordToGuess << endl;
    }
    else {
        cout << "Sorry, you ran out of guesses. The word was: " << wordToGuess << endl;
    }

    return 0;
}





