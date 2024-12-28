#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

void clearInputBuffer() {
    std::cin.clear(); // Clear the fail state
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    int wins = 0;
    int losses = 0;
    char playAgain;

    do {
        int numberToGuess = rand() % 100 + 1; // Random number between 1 and 100
        int guess;
        int attempts = 0;
        const int maxAttempts = 7; // Limit on the number of guesses
        bool hasGuessedCorrectly = false;

        std::cout << "Welcome to the Number Guessing Game!\n"
                  << "Guess a number between 1 and 100. You have " << maxAttempts << " attempts.\n";

        while (attempts < maxAttempts) {
            std::cout << "Enter your guess: ";
            std::cin >> guess;

            // Input validation
            if (std::cin.fail() || guess < 1 || guess > 100) {
                clearInputBuffer(); // Clear invalid input
                std::cout << "Invalid input! Please enter a number between 1 and 100.\n";
                continue;
            }

            attempts++;
            if (guess == numberToGuess) {
                hasGuessedCorrectly = true;
                break; // Exit loop if guessed correctly
            } else if (guess < numberToGuess) {
                std::cout << "Too low! Try again.\n";
            } else {
                std::cout << "Too high! Try again.\n";
            }
        }

        if (hasGuessedCorrectly) {
            std::cout << "Congratulations! You guessed the number " << numberToGuess << " in " << attempts << " attempts.\n";
            wins++;
        } else {
            std::cout << "Sorry, you've used all your attempts. The number was " << numberToGuess << ".\n";
            losses++;
        }

        std::cout << "Current Score - Wins: " << wins << ", Losses: " << losses << "\n";
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;
        clearInputBuffer(); // Clear input buffer before next round

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing! Final Score - Wins: " << wins << ", Losses: " << losses << "\n";
    return 0;
}
