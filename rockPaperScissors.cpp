#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

std::string userInput() {
	std::cout << "Enter your move (rock, paper, scissors): "; // Possible to refactor userInput /w selectDifficulty together into 1 function 
	std::string input;
	std::cin >> input;
	return input;

}

int selectDifficulty() {
	std::cout << "Choose a difficulty (1= easy, 2= medium, 3= hard): "; // refactor to only accept either 1,2,3 and reject all other possible values
	int difficulty{};
	std::cin >> difficulty;

	return (difficulty == 1 || difficulty == 2 || difficulty == 3 ) ? difficulty: 0;
}


int random(int low, int high) {
	return rand()%(high-low+1)+low;
}

void opponentActions(const bool didPlayerWin, const std::string playerChoice) { // nested if could be improved via design choice
	if (didPlayerWin) {
		if (playerChoice.compare("rock") == 0) {
			std::cout << "Opponent has selected scissors \n";
		} else if (playerChoice.compare("paper") == 0) {
			std::cout << "Opponent has selected rock \n";
		} else {
			std::cout << "Opponent has selected paper \n";
		}
	} else {
		if (playerChoice.compare("rock") == 0) {
			std::cout << "Opponent has selected paper \n";
		} else if (playerChoice.compare("paper") == 0) {
			std::cout << "Opponent has selected scissors \n";
		} else {
			std::cout << "Opponent has selected rock \n";
		}
	}
}

void gameAlgorithm(const int difficulty, const std::string playerChoice) {
	int playerRoll {0};
	int opponentRoll {0};
	switch(difficulty) {
		case 1:
			playerRoll = random(90,100);
			opponentRoll = random(1,100);
			break;
		case 2:
			playerRoll = random(1,100);
			opponentRoll = random(1,100);
			break;
		case 3:
			playerRoll = random(1,100);
			opponentRoll = random(90,100);
			break;
	}

	if (playerRoll > opponentRoll){
		opponentActions(1, playerChoice);
	} else {
		opponentActions(0, playerChoice);
	}
}

int main() {

	srand(time(NULL)); // unclear purpose of usage
	std::cout << "Let's play Rock-Paper-Scissors! \n";
	const int difficulty{selectDifficulty()};

	if (difficulty) {
		std::string playerChoice{userInput()};
		gameAlgorithm(difficulty, playerChoice);
	} else {
		std::cout << "Invalid difficulty selected \n";
	}
	return 0;
}
