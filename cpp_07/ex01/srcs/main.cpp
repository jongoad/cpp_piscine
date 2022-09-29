#include "../includes/Iter.hpp"
#include <iostream>
#include <string>

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int main(void) {
	int arr1[5] = {1, 2, 3, 4, 5};
	std::string arr2[5] = {"this", "is", "a", "string", "array"};
	const float arr3[5] = {1.23, 2.34 , 3.45, 4.56, 5.67};

	std::cout << RED"------ Testing int array -----" CLEAR << std::endl;
	::iter(arr1, 5, print);

	std::cout << std::endl;
	std::cout << RED"------ Testing string array -----" CLEAR << std::endl;
	::iter(arr2, 5, print);

	std::cout << std::endl;
	std::cout << RED"------ Testing const float array -----" CLEAR << std::endl;
	::iter(arr3, 5, print);
}