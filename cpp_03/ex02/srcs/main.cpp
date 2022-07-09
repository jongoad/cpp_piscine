#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"

int	main(void) {

ClapTrap Bob("Bob");
ScavTrap Jim("Jim");
FragTrap Jeff("Jeff");

std::cout << std::endl;
std::cout << Bob.getName() << " is a ClapTrap. Here are his stats:" << std::endl;
std::cout << "Attack Damage: " << Bob.getAttackDamage() << std::endl;
std::cout << "Energy Points: " << Bob.getEnergyPoints() << std::endl;
std::cout << "Hitpoints: " << Bob.getHitPoints() << std::endl << std::endl;
Bob.attack("Jim");
std::cout << std::endl;

std::cout << Jim.getName() << " is a ScavTrap. Here are his stats:" << std::endl;
std::cout << "Attack Damage: " << Jim.getAttackDamage() << std::endl;
std::cout << "Energy Points: " << Jim.getEnergyPoints() << std::endl;
std::cout << "Hit Points: " << Jim.getHitPoints() << std::endl << std::endl;
Jim.attack("Bob");
Jim.guardGate();
Jim.guardGate();
std::cout << std::endl;

std::cout << std::endl;
std::cout << Jeff.getName() << " is a FragTrap. Here are his stats:" << std::endl;
std::cout << "Attack Damage: " << Jeff.getAttackDamage() << std::endl;
std::cout << "Energy Points: " << Jeff.getEnergyPoints() << std::endl;
std::cout << "Hitpoints: " << Jeff.getHitPoints() << std::endl << std::endl;
Jeff.attack("Jim");
Jeff.highFivesGuys();
std::cout << std::endl;
}