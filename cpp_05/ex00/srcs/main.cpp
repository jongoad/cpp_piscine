#include "../includes/Bureaucrat.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|  Testing Bureaucrat Protocols  |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	Bureaucrat Jim("Jim", 2);
	Bureaucrat Billy("Billy", 149);
	try {
		Bureaucrat Zane("Zane", -500);

	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat Jane("Jane", 500);

	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Bureaucrat Lane("Lane", 0);

	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << RED"-----Testing Exceptions-----" CLEAR << std::string(2, '\n');
	try {
		
		std::cout << Jim << std::endl;
		std::cout << Billy << std::endl;
		Jim.increaseGrade();
		Billy.decreaseGrade();
		std::cout << Jim << std::endl;
		std::cout << Billy << std::endl;
		Jim.increaseGrade();
		Billy.decreaseGrade();
		std::cout << Jim << std::endl;
		std::cout << Billy << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Billy.decreaseGrade();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << RED"-----Destroying Objects-----" CLEAR << std::string(2, '\n');
}
