#include <iostream>
#include <algorithm>

//void bubbleSort(int array);

void bubbleSort(int length, int array[]) {
	/*
	for(int i{0};i<length-1;++i){
		for(int j{i+1}; j<length;++j) {
			if(array[j]< array[i]) {
				std::swap(array[j],array[i]);
			}
		}
	}
	*/
	int numberOfSwaps{0};
	for(int i{0}; i <length-1;++i) {
		for(int j{0};j < length-i;++j) {
			if(array[j] > array[j+1]) {
				std::swap(array[j], array[j+1]);
				++numberOfSwaps;
			}
		}
		if (!numberOfSwaps) {
			std::cout << "Early termination on iteration " << i+1 << "\n";
			break;
		}
		numberOfSwaps = 0;
	}
}

int main() {
	const int length{9};
	int array[length] {6,3,2,9,7,1,5,4,8};
	bubbleSort(length, array);
	for(auto& n: array){
		std::cout << n << " ";
	}
	return 0;
}