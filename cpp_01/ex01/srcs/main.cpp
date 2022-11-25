#include "../includes/Zombie.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void)
{
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|     Testing Zombie Creation    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	const int	N = 5;
	Zombie		*Horde = zombieHorde(N, "Todd");

	std::cout << std::endl;
	std::cout << RED"-----Testing Announce Function-----" CLEAR << std::string(2, '\n');

	for(int i = 0; i < N; i++)
		Horde[i].announce();

	std::cout << std::endl;
	std::cout << RED"-----Deleting Objects----" CLEAR << std::string(2, '\n');
		delete [] Horde;
}