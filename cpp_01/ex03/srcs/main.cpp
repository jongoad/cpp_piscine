#include <iostream>

#include "../includes/HumanA.hpp"
#include "../includes/HumanB.hpp"
#include "../includes/Weapon.hpp"


#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void)
{
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|   WHY ARE HUMANS SO VIOLENT?   |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	return (0);
}