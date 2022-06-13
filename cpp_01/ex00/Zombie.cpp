#include "Zombie.h"


Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << this->GetName() << std::endl;
}

Zombie *newZombie(std::string name) {
	Zombie *Output = new Zombie(name);
	return (Output);
}

void	Zombie::Announce() {
	std::cout << this->GetName() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Return name of current zombie */
std::string Zombie::GetName() {
	return (this->name);
}

