#include <iostream>
#include <cmath>


int binarySeparatorChecker(int binarySeparatorCounter) {
	if (!binarySeparatorCounter) {
				std::cout << " ";
				binarySeparatorCounter= 4;
			}

	return binarySeparatorCounter;
}

void binaryConverter(int x) {
	int powStarter{7}; // the current 2^n power (assuming only 8 bits need to be printed, hence n = 7)
	int binarySeparatorCounter{4}; // counts down when 4 bits have been written

	while(powStarter != -1) {
		if (x >= pow(2,powStarter)) {
			std::cout << "1";
			x -= pow(2,powStarter);
			/*
			--powStarter;
			--binarySeparatorCounter;
			binarySeparatorCounter = binarySeparatorChecker(binarySeparatorCounter);
			*/
		} else {
			std::cout << "0";
		}
			--powStarter;
			--binarySeparatorCounter;
			binarySeparatorCounter = binarySeparatorChecker(binarySeparatorCounter);
	}
	std::cout << "\n";
}

int enterValue(){
	std::cout << "Enter a number to be converted to binary(must be between 0-255): ";
	int userInput{0};
	std::cin >> userInput;

	return (userInput >= 0 && userInput <= 255) ? userInput: -1;
}

int main() {
	int userInput{enterValue()};

	if (userInput > -1) { 
	binaryConverter(userInput);
	} else {
		std::cout << "Incorrect value entered \n";
	} 
	
	return 0;
}