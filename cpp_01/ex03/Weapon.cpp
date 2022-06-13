#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::Weapon(std::string const &type):
		type(type)
{
}

Weapon::~Weapon() {

}

std::string const &Weapon::getType() const {
	return (this->type);
}

void Weapon::setType(std::string const &type) {
	this->type = type;
}