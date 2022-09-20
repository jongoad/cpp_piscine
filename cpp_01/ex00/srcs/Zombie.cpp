#include "../includes/Zombie.hpp"

/* Constructors & Destructor */
Zombie::Zombie(const std::string name) : name(name) {
	std::cout << this->name << " has been created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->getName() << " has been destroyed" << std::endl;
}

/* Setters & Getters */
std::string const& Zombie::getName() const {
	return (this->name);
}

/* Public Member Functions */
void	Zombie::announce() {
	std::cout << this->getName() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}