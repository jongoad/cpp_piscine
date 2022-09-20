#include "../includes/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	if (N < 0) {
		std::cout << "Invalid integer input for Horde allocation" << std::endl;
		return (nullptr);
	}
	Zombie *Horde = new Zombie[N];
	for(int i = 0; i < N; i++)
		Horde[i].setName(name + static_cast<char>('0' + i));
	return (Horde);
}