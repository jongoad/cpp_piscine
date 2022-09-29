#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"


#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void) {
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|     Testing Correct Animals    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	const Animal* Base = new Animal();
	const Animal* Doge = new Dog();
	const Animal* Kitty = new Cat();

	std::cout << std::endl;
	std::cout << RED"Animal (Base) is: " CLEAR << Base->getType()<< std::endl;
	std::cout << RED"Animal (Doge) is: " CLEAR << Doge->getType()<< std::endl;
	std::cout << RED"Animal (Kitty) is: " CLEAR << Kitty->getType()<< std::endl;
	std::cout << std::endl;

	std::cout << RED"-----Testing Animal Sounds-----" CLEAR << std::string(2, '\n');
	std::cout << RED"Animal (Base) noise: " CLEAR; Base->makeSound();
	std::cout << RED"Animal (Doge) noise: " CLEAR; Doge->makeSound();
	std::cout << RED"Animal (Kitty) noise: " CLEAR; Kitty->makeSound();
	std::cout << std::endl;

	std::cout << RED"-----Deleting Objects-----" CLEAR << std::string(2, '\n');
	delete Base; delete Doge; delete Kitty;
	std::cout << std::endl;



	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|      Testing Wrong Animals     |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Objects-----" CLEAR << std::string(2, '\n');
	const WrongAnimal* WrongBase = new WrongAnimal();
	const WrongAnimal* WrongKitty = new WrongCat();

	std::cout << std::endl;
	std::cout << RED"Animal (WrongBase) is: " CLEAR << WrongBase->getType()<< std::endl;
	std::cout << RED"Animal (WrongKitty) is: " CLEAR << WrongKitty->getType()<< std::endl;
	std::cout << std::endl;

	std::cout << RED"-----Testing Animal Sounds-----" CLEAR << std::string(2, '\n');
	std::cout << RED"Animal (WrongBase) noise: " CLEAR; WrongBase->makeSound();
	std::cout << RED"Animal (WrongKitty) noise: " CLEAR; WrongKitty->makeSound();
	std::cout << std::endl;

	std::cout << RED"-----Deleting Objects-----" CLEAR << std::string(2, '\n');
	delete WrongBase; delete WrongKitty;
	std::cout << std::endl;

	return 0;
}
