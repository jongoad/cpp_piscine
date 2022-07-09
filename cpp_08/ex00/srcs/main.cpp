#include <iostream>
#include <string>
#include <vector>
#include "../includes/easyfind.hpp"
#include "../includes/easyfind.tpp"

int	main(void) {
	std::vector<int> test1 (1, 2);
	std::vector<int> test2 (1, 3);

	try {
		std::vector<int>::iterator it = easyfind(test1, 2);
		if (it != test1.end())
			std::cout << "Element Found" << std::endl;
		std::vector<int>::iterator it2 = easyfind(test2, 2);
		if (it2 != test2.end())
			std::cout << "Element Found" << std::endl;
	}
	catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}