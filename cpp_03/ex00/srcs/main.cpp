#include "../includes/ClapTrap.hpp"

int	main(void) {

ClapTrap Bob("Bob");	/* Create with name constructor */
ClapTrap Jim(Bob);		/* Create with copy constructor */
ClapTrap Jeff;
Jeff = Jim;

std::cout << std::endl;
std::cout << "Jeff's name is now " << Jeff.getName() << std::endl << std::endl;

std::cout << std::endl;
std::cout << Bob.getName() << " is a ClapTrap. Here are his stats:" << std::endl;
std::cout << "Attack Damage: " << Bob.getAttackDamage() << std::endl;
std::cout << "Energy Points: " << Bob.getEnergyPoints() << std::endl;
std::cout << "Hitpoints: " << Bob.getHitPoints() << std::endl << std::endl;
Bob.attack("Jim");
std::cout << std::endl;
}