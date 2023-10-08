#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
 
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    
    int randomNumber = std::rand() % 100 + 1;

    int guess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I've picked a random number between 1 and 100. Try to guess it." << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << attempts << " attempts." << std::endl;
        }
    } while (guess != randomNumber);

    return 0;
}
