#include <string>
#include <iostream>
#include "../includes/Harl.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(int argc, char **argv) {
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|      Testing Harl Protocol     |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	/* Handle input error */
	if (argc != 2) {
		std::cout << "Missing or invalid arguments." << std::endl;
		exit(EXIT_FAILURE);
	}

	
	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	Harl complainer;

	std::cout << std::endl;
	std::cout << RED"-----Running Input Through Filter-----" CLEAR << std::string(2, '\n');
	std::cout << RED"Input is: " CLEAR << argv[1] << std::string(2, '\n');

	complainer.complain(argv[1]);

	std::cout << std::endl;
	std::cout << RED"-----Deleting Objects-----" CLEAR << std::string(2, '\n');
}