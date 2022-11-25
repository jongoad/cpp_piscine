#include "../includes/HumanA.hpp"

/* Constructors & Destructor */
HumanA::HumanA(std::string const &name, Weapon& weapon): weapon(weapon), name(name) {
}

HumanA::~HumanA() {
}

/* Public Member Functions */
void HumanA::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std:: endl;
}
