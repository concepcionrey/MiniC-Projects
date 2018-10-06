#include <iostream>
#include "myConstants.h"

int enterHeight() {
	std::cout << "Enter the initial height of the tower (metres): ";
	int height{};
	std::cin >> height;
	return height;
}

void computeHeight(const int x) {
	for (int i{}; i<5; i++) {
		double currHeight{(myConstants::gravity*(i*i))/2};
		double res{x-currHeight};
		std::cout << "At " << i << " seconds, the ball is at height: " << res
		<< " meters" << "\n";
	}
}

int main(){
	const int u1{enterHeight()};
	computeHeight(u1);
	return 0;
}