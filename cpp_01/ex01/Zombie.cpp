#include "Zombie.h"

Zombie::Zombie() {

}

Zombie::Zombie(std::string name) {
	this->name = name;
}

Zombie::~Zombie() {
	std::cout << this->GetName() << std::endl;
}

Zombie	*newZombie(std::string name) {
	Zombie *Output = new Zombie(name);
	return (Output);
}

Zombie	*zombieHorde(int N, std::string name) {
	Zombie *Horde = new Zombie[N];
	for(int i = 0; i < N; i++) {   
		Horde[i] = *newZombie(name);
		Horde->Announce();
	}
	return (Horde);
}

void	Zombie::Announce() {
	std::cout << this->GetName() << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

/* Return name of current zombie */
std::string Zombie::GetName() {
	return (this->name);
}
