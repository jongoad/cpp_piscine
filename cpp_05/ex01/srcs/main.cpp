#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|  Testing Bureaucrat Protocols  |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	Bureaucrat	Jim("Jim", 2);
	Bureaucrat	Billy("Billy", 149);
	Form		JimPayRaise("Jim's Pay Raise Request", 20, 20);
	Form		BillyPayRaise("Billy's Pay Raise Request", 20, 20);
	
	std::cout << std::endl;
	std::cout << RED"-----Testing Forms-----" CLEAR << std::string(2, '\n');
	try {
		std::cout << Jim << std::string(2, '\n');
		std::cout << JimPayRaise << std::endl;
		
		Jim.signForm(JimPayRaise);
		std::cout << std::endl;

		std::cout << JimPayRaise << std::endl;

		std::cout << Billy << std::string(2, '\n');
		std::cout << BillyPayRaise << std::endl;
		Billy.signForm(BillyPayRaise);
		std::cout << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << RED"-----Destroying Objects-----" CLEAR << std::string(2, '\n');
}
