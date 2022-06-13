#include <string>
#include <iostream>
#include "Harl.hpp"

int	main(int argc, char **argv)
{

	//Handle input error
	if (argc != 2) {
		std::cout << "Missing or invalid arguments." << std::endl;
		exit(EXIT_FAILURE);
	}
	Harl complainer;
	complainer.complain(argv[1]);
}
