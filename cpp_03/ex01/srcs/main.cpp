#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {

	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|   Testing Claptrap Protocol    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');

	ClapTrap Bob("Bob");
	ScavTrap Jim("Jim");

	std::cout << std::endl;
	std::cout << RED"-----Testing Stat Allocation-----" CLEAR << std::string(2, '\n');
	std::cout << Bob.getName() << " is a ClapTrap. Here are his stats:" << std::endl;
	std::cout << "Attack Damage: " << Bob.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << Bob.getEnergyPoints() << std::endl;
	std::cout << "Hitpoints: " << Bob.getHitPoints() << std::endl << std::endl;

	std::cout << Jim.getName() << " is a ScavTrap. Here are his stats:" << std::endl;
	std::cout << "Attack Damage: " << Jim.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << Jim.getEnergyPoints() << std::endl;
	std::cout << "Hit Points: " << Jim.getHitPoints() << std::endl << std::endl;



	std::cout << std::endl;
	std::cout << RED"-----Testing ClapTrap Actions-----" CLEAR << std::string(2, '\n');
	Jim.attack("Bob");
	Bob.takeDamage(Jim.getAttackDamage());
	Jim.guardGate();
	Jim.guardGate();
	std::cout << std::endl;

	std::cout << RED"-----Destroying Objects-----" CLEAR << std::string(2, '\n');
}