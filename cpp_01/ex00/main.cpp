#include "Zombie.h"

int	main(void)
{
	Zombie	First("Bob");
	Zombie	*Second = newZombie("Jerry");

	std::cout << First.GetName() << " was created on the stack with default constructor" << std::endl;
	std::cout << Second->GetName() << " was created on the heap with a special function" << std::endl;
	std::cout << "Stack Zombie says:" << std::endl;
	First.Announce();
	std::cout << "Heap Zombie says:" << std::endl;
	Second->Announce();
	delete(Second);
}