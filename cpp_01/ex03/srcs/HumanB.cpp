#include "../includes/HumanB.hpp"

/* Constructors & Destructors */
HumanB::HumanB(std::string const &name) : name(name) {
}

HumanB::~HumanB() {
}

/* Setters & Getters */
void HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

/* Public Member Functions */
void HumanB::attack() const {
	std::cout << this->name << " attacks with their ";
	if (this->weapon)
		std::cout << this->weapon->getType();
	else
		std::cout << "fists";
	std::cout << std::endl;
}