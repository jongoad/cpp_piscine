#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"

#include <unistd.h>

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|  Testing Bureaucrat Protocols  |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	Bureaucrat	Jim("Jim", 2);
	Bureaucrat	Billy("Billy", 149);
	ShrubberyCreationForm shrubbery("Garden");
	ShrubberyCreationForm shrubbery2("Street");
	PresidentialPardonForm pardon("Billy");
	PresidentialPardonForm pardon2("Billy");
	RobotomyRequestForm robotomy("Bender");
	RobotomyRequestForm robotomy2("C-3P0");

	
	std::cout << std::endl;
	std::cout << RED"-----Testing Shrubbery Form-----" CLEAR << std::string(2, '\n');
	try {
		std::cout << Jim << std::string(2, '\n');
		std::cout << shrubbery << std::string(2, '\n');
		Jim.signForm(shrubbery);
		std::cout << std::endl;
		std::cout << shrubbery << std::string(2, '\n');
		Jim.executeForm(shrubbery);
		std::cout << std::endl;

		std::cout << shrubbery2 << std::string(2, '\n');
		Billy.signForm(shrubbery2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Billy.executeForm(shrubbery2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
	Billy.executeForm(shrubbery);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << RED"-----Testing Presidential Pardon Form-----" CLEAR << std::string(2, '\n');
	try {
		std::cout << Jim << std::string(2, '\n');
		std::cout << pardon << std::string(2, '\n');
		Jim.signForm(pardon);
		std::cout << std::endl;
		std::cout << pardon << std::string(2, '\n');
		Jim.executeForm(pardon);
		std::cout << std::endl;

		std::cout << pardon2 << std::string(2, '\n');
		Billy.signForm(pardon2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Billy.executeForm(pardon2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
	Billy.executeForm(pardon);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

		std::cout << std::endl;
	std::cout << RED"-----Testing Robotomy Request Form-----" CLEAR << std::string(2, '\n');
	try {
		std::cout << Jim << std::string(2, '\n');
		std::cout << robotomy << std::string(2, '\n');
		Jim.signForm(robotomy);
		std::cout << std::endl;
		std::cout << robotomy << std::string(2, '\n');
		Jim.executeForm(robotomy);
		sleep(rand() % 3);
		Jim.executeForm(robotomy);
		sleep(rand() % 3);
		Jim.executeForm(robotomy);
		sleep(rand() % 3);
		Jim.executeForm(robotomy);
		sleep(rand() % 3);
		Jim.executeForm(robotomy);
		sleep(rand() % 3);
		Jim.executeForm(robotomy);
		std::cout << std::endl;

		std::cout << robotomy2 << std::string(2, '\n');
		Billy.signForm(robotomy2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Billy.executeForm(robotomy2);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
	Billy.executeForm(robotomy);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	
	std::cout << RED"-----Destroying Objects-----" CLEAR << std::string(2, '\n');
}
