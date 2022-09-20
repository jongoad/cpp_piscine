#include "../includes/ClapTrap.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {

	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|   Testing Claptrap Protocol    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');

	ClapTrap Bob("Bob");
	ClapTrap Jim(Bob);
	ClapTrap Jeff;
	ClapTrap Tim("Tim");

	std::cout << std::endl;	
	std::cout << RED"-----Testing Operator Overload-----" CLEAR << std::string(2, '\n');
	Jeff = Jim;
	std::cout << "Jeff's name is now " << Jeff.getName() << std::endl << std::endl;

	std::cout << std::endl;
	std::cout << RED"-----Testing Stat Allocation-----" CLEAR << std::string(2, '\n');
	std::cout << Bob.getName() << " is a ClapTrap. Here are his stats:" << std::endl;
	std::cout << "Attack Damage: " << Bob.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << Bob.getEnergyPoints() << std::endl;
	std::cout << "Hitpoints: " << Bob.getHitPoints() << std::endl << std::endl;



	std::cout << std::endl;
	std::cout << RED"-----Testing ClapTrap Actions-----" CLEAR << std::string(2, '\n');
	Bob.attack("Tim");
	Tim.takeDamage(Bob.getAttackDamage());
	Tim.beRepaired(Bob.getAttackDamage());
	std::cout << std::endl;

	std::cout << RED"-----Destroying Objects-----" CLEAR << std::string(2, '\n');
}



	