#include "Zombie.h"

int	main(void)
{
	int			N = 5;
	std::string	name = "Todd";
	Zombie		*Horde;
	Zombie		*p_Horde;

	Horde = zombieHorde(N, name);
	
	for(int i = 0; i < N; i++) {
		Horde->Announce();
	}
	Horde = p_Horde;
	for(int i = 0; i < N; i++) {
		delete(Horde);
	}
}