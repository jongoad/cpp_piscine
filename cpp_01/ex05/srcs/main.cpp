#include "../includes/Harl.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void)
{
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|      Testing Harl Protocol     |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	Harl complainer;
	std::cout << std::endl;

	std::cout << RED"-----Testing Debug Level: debug-----" CLEAR << std::string(2, '\n');
	complainer.complain("debug");
	std::cout << std::endl;
	
	std::cout << RED"-----Testing Debug Level: info-----" CLEAR << std::string(2, '\n');
	complainer.complain("info");
	std::cout << std::endl;

	std::cout << RED"-----Testing Debug Level: warning-----" CLEAR << std::string(2, '\n');
	complainer.complain("warning");
	std::cout << std::endl;

	std::cout << RED"-----Testing Debug Level: error-----" CLEAR << std::string(2, '\n');
	complainer.complain("error");
	std::cout << std::endl;

	std::cout << RED"-----Testing Debug Level: invalid code-----" CLEAR << std::string(2, '\n');
	complainer.complain("something");
	std::cout << std::endl;

	std::cout << RED"-----Deleting Objects-----" CLEAR << std::string(2, '\n');
}



