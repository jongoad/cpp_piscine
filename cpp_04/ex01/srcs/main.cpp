#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Brain.hpp"


#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {

	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|     Testing Correct Animals    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	const Animal* Doge = new Dog();
	const Animal* Kitty = new Cat();
	

	std::cout << std::endl;
	std::cout << RED"Animal (Doge) is: " CLEAR << Doge->getType()<< std::endl;
	std::cout << RED"Animal (Kitty) is: " CLEAR << Kitty->getType()<< std::endl;
	std::cout << std::endl;

	std::cout << RED"-----Testing Brain-----" CLEAR << std::string(2, '\n');
	std::cout << RED"Animal (Doge) idea: " CLEAR << ((Dog *)Doge)->getBrain()->getIdea(5) << std::endl;
	std::cout << RED"Animal (Kitty) idea: " CLEAR << ((Cat *)Kitty)->getBrain()->getIdea(33) << std::endl;
	std::cout << std::endl;

	std::cout << RED"-----Testing Deep Copy-----" CLEAR << std::string(2, '\n');
	Cat* Kat = new Cat();
	Cat* Katty = new Cat(*Kat);
	Cat* Kattier = new Cat();
	*Kattier = *Kat;

	std::cout << RED"Animal (Kat) idea: " CLEAR << Kat->getBrain()->getIdea(5) << std::endl;
	std::cout << RED"Animal (Katty) idea: " CLEAR << Katty->getBrain()->getIdea(5) << std::endl;
	std::cout << RED"Animal (Kattier) idea: " CLEAR << Kattier->getBrain()->getIdea(5) << std::endl;
	std::cout << std::endl;

	Kat->getBrain()->setIdea(5, "NEW IDEA");

	std::cout << RED"Animal (Kat) idea: " CLEAR << Kat->getBrain()->getIdea(5) << std::endl;
	std::cout << RED"Animal (Katty) idea: " CLEAR << Katty->getBrain()->getIdea(5) << std::endl;
	std::cout << RED"Animal (Kattier) idea: " CLEAR << Kattier->getBrain()->getIdea(5) << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << RED"-----Deleting Objects-----" CLEAR << std::string(2, '\n');
	delete Doge; delete Kitty; delete Kat; delete Katty; delete Kattier;
	std::cout << std::endl;

	return 0;
}
