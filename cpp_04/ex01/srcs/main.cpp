#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include "../includes/Brain.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"


int main()
{
	std::cout << RED"----------------------------------"CLEAR << std::endl;
	std::cout << RED"|          Testing Array         |"CLEAR << std::endl;
	std::cout << RED"----------------------------------"CLEAR << std::string(2, '\n') << std::flush;

	std::cout << RED"-----Creating Objects-----"CLEAR << std::string(2, '\n') << std::flush;
	Animal *arr[8];
	for (int i = 0; i < 6; i++) {
		if (i < 3)
			arr[i] = new Cat();
		if (i >= 3)
			arr[i] = new Dog(); 
	}
	std::cout << std::endl;

	std::cout << RED"-----Testing Animal Sounds-----"CLEAR << std::string(2, '\n') << std::flush;
	for (int i = 0; i < 6; i++) {
		std::cout << RED"Animal " << i << " noise:"CLEAR << " ";
		arr[i]->makeSound();
	}

	std::cout << std::endl << RED"-----Deleting Objects-----"CLEAR << std::string(2, '\n') << std::flush;
	for (int i = 0; i < 6; i++) {
		delete arr[i];
	}
	std::cout << std::endl;

	std::cout << RED"----------------------------------"CLEAR << std::endl;
	std::cout << RED"|        Testing Deep Copy       |"CLEAR << std::endl;
	std::cout << RED"----------------------------------"CLEAR << std::string(2, '\n') << std::flush;

	std::cout << RED"-----Creating Objects-----"CLEAR << std::string(2, '\n') << std::flush;
	Cat *cat1 = new Cat();
	Cat *cat2 = new Cat();



	std::cout << RED"-----Checking Current Ideas-----"CLEAR << std::string(2, '\n') << std::flush;
	cat1->setIdea(1, "Cats should rule the world!");
	std::cout << RED"cat1's first idea: "CLEAR << cat1->getIdea(1) << std::endl;
	std::cout << RED"cat2's first idea: "CLEAR << cat2->getIdea(1) << std::endl;

	std::cout << std::endl;
	std::cout << RED"-----Overwritting Idea-----"CLEAR << std::string(2, '\n') << std::flush;
	cat2->removeBrain();
	*cat2 = *cat1;

	std::cout << RED"cat2's first idea: "CLEAR << cat2->getIdea(1) << std::endl;


	std::cout << std::endl;
	std::cout << RED"-----Deleting First Cat-----"CLEAR << std::string(2, '\n') << std::flush;
	delete cat1;

	std::cout << std::endl;
	std::cout << RED"----Confirm Second Cat Still Has A Brain-----"CLEAR << std::string(2, '\n') << std::flush;
	std::cout << RED"cat2's first idea: "CLEAR << cat2->getIdea(1) << std::endl;

	std::cout << std::endl;
	std::cout << RED"-----Deleting Objects-----"CLEAR << std::string(2, '\n') << std::flush;
	delete cat2;

	return (0);
}

