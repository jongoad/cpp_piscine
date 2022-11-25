#include <iostream>
#include <string>
#include <vector>
#include "../includes/easyfind.hpp"
#include "../includes/easyfind.tpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {

	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|        Easyfind Tester         |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::vector<int> test1 (1, 2);
	std::vector<int> test2 (1, 3);

	std::cout << RED"------ Testing Integer Vector -----" CLEAR << std::endl;

	try {
	std::cout << "Vector one contains: 1, 2\nSearching for 2." << std::string(2, '\n');
		std::vector<int>::iterator it = easyfind(test1, 2);
		if (it != test1.end())
			std::cout << "Element Found" << std::endl;
	std::cout << std::endl;
	std::cout << "Vector two contains: 1, 3\nSearching for 2." << std::string(2, '\n');
		std::vector<int>::iterator it2 = easyfind(test2, 2);
		if (it2 != test2.end())
			std::cout << "Element Found" << std::endl;
	}
	catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}