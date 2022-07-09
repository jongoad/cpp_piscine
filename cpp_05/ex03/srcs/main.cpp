#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

#include <unistd.h>

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|  Testing Bureaucrat Protocols  |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	Bureaucrat	Jim("Jim", 2);
	Intern		Nobody;
	Form*		formA;
	Form*		formB;
	Form*		formC;
	Form*		formD;
	
	std::cout << std::endl;
	std::cout << RED"-----Testing Intern-----" CLEAR << std::string(2, '\n');

	try {
		formA = Nobody.makeForm("shrubbery creation", "garden");
		formB = Nobody.makeForm("presidential pardon", "Doug");
		formC = Nobody.makeForm("robotomy request", "Bender");
		formD = Nobody.makeForm("fake form", "fake form");
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Jim.executeForm(*formA);
		Jim.executeForm(*formB);
		Jim.executeForm(*formC);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << RED"-----Destroying Objects-----" CLEAR << std::string(2, '\n');
}
