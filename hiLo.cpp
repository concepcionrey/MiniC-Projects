#include <iostream>
#include <cstdlib>
#include <ctime>

constexpr int min{1};
constexpr int max{100};
constexpr int numberOfAttempts{7};

// generate a random number between 0 to 100
int randomNumberGeneratorBetween1To100(int max, int min) {
	static double fraction{1.0 /(RAND_MAX + 1.0)};
	return 1 + static_cast<int>((max-min+1) * (std::rand()*fraction));
}

// ask the player if would like to play again
char optionToPlayAgain() {
	char playAgain{0};
	do {
		std::cout << "Do you want to play again (y/n)?";
		std::cin >> playAgain;
	}
	while (playAgain != 'y' && playAgain != 'n');
	return playAgain;
}

// check if the player gussed the correct answer
void didThePlayerWin(int playerGuess, int correctAnswer) {
	if (playerGuess == correctAnswer) {
		std::cout << "Correct! You win! \n";
	} else {
		std::cout << "Sorry you lose. The correct number was " << correctAnswer << ".\n"; 
	}
}

// case-checking for player's input
int inputAnswer(int i) {
	int playerGuess{0};
	while(true){
		std::cout << "Guess #" << i << ": ";
		std::cin >> playerGuess;
		if(std::cin.fail() || playerGuess > 100 || playerGuess < 1) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid answer, Please try again!\n";
		} else {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return playerGuess;
		}
	}
}

void gameOfHiLo() {
	char playAgain{'y'};
	int playerGuess{0};
	do {
		std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is. \n";
		int correctAnswer{randomNumberGeneratorBetween1To100(max,min)};
		for (int i{1}; i<=numberOfAttempts; ++i) {
			playerGuess = inputAnswer(i);
			if (playerGuess > correctAnswer) {
				std::cout << "Your guess is too high.\n";
			} else if(playerGuess < correctAnswer) {
				std::cout << "Your guess is too low.\n";
			} else {
				break;
			}
		}
		didThePlayerWin(playerGuess,correctAnswer);
		playAgain = optionToPlayAgain();
	}
	while(playAgain != 'n');
	std::cout << "Thank you for playing!\n";
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::rand();
	gameOfHiLo();
	return 0;
}

