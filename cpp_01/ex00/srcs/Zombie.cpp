#include "../includes/Zombie.hpp"

/* Constructors & Destructor */
Zombie::Zombie(std::string name) : name(name) {
	std::cout << this->name << " has been created" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->getName() << " has been destroyed" << std::endl;
}

/* Setters & Getters */
std::string Zombie::getName() const {
	return (this->name);
}

/* Public Member Functions */
void	Zombie::announce() const {
	std::cout << this->getName() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

/* External Functions */

Zombie *newZombie(const std::string name) {
	Zombie *Output = new Zombie(name);
	std::cout << Output->getName() << " has been allocated on the heap" << std::endl;
	return (Output);
}

void	randomChump(const std::string name) {
	Zombie chump(name);
	chump.announce();
}