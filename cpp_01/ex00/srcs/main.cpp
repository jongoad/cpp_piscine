#include "../includes/Zombie.hpp"
#include "../includes/Zombie.h"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void)
{
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|     Testing Zombie Creation    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	Zombie	First("Bob");
	Zombie	*Second = newZombie("Jerry");

	std::cout << std::endl;
	std::cout << RED"-----Testing Announce Function-----" CLEAR << std::string(2, '\n');
	First.announce();
	Second->announce();

	std::cout << std::endl;
	std::cout << RED"-----Testing randomChump Function-----" CLEAR << std::string(2, '\n');
	randomChump("Gus");

	std::cout << std::endl;
	std::cout << RED"-----Deleting Objects----" CLEAR << std::string(2, '\n');
	delete(Second);
}