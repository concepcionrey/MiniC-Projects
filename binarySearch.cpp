#include <iostream>


// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearchRecursive(int *array, int target, int min, int max) {
    if (array == nullptr || min > max) {
        return -1;
    }
    int middleOf{((max+min)/2)};
    if(array[middleOf] == target) {
        return middleOf;
    } else if(array[middleOf] < target) {
        return binarySearchRecursive(array,target,middleOf+1,max);
    } else {
        return binarySearchRecursive(array,target,min,middleOf-1);
    }
}

int binarySearchIterative(int *array, int target, int min, int max) {
    if (array == nullptr || min > max) {
        return -1;
    } else {
        while(min <= max) {
             int middleOf{((max+min)/2)};
             if (array[middleOf] == target) {
                return middleOf;
             } else if(array[middleOf] < target) {
                min = middleOf+1;
             } else {
                max = middleOf-1;
             }
        }
        return -1;
    }
}
 
int main()
{
    int array[] = { 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };
 
    // We're going to test a bunch of values to see if they produce the expected results
    const int numTestValues = 9;
    // Here are the test values
    int testValues[numTestValues] = { 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues] = { -1, 0, 3, -1, -1, 8, -1, 13, -1 };
 
    // Loop through all of the test values
    for (int count=0; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index = binarySearchIterative(array, testValues[count], 0, 14);
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
             std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
             std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }
 
    return 0;
}
