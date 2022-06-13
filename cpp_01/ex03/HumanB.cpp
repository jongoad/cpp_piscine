#include "HumanB.hpp"

HumanB::HumanB(std::string const &name):
	name(name)
{
}

HumanB::~HumanB() {

}

void HumanB::setWeapon(Weapon const &weapon) {
	this->weapon = &weapon;
}

void HumanB::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}