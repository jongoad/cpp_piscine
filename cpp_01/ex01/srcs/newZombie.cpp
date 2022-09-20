#include "../includes/Zombie.hpp"

Zombie *newZombie(std::string name) {
	Zombie *Output = new Zombie(name);
	std::cout << Output->getName() << " has been allocated on the heap" << std::endl;
	return (Output);
}