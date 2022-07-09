#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"



int main()
{
std::cout << "\033[1;31m----------------------------------\033[0m" << std::endl;
std::cout << "\033[1;31m|    Testing Original Version    |\033[0m" << std::endl;
std::cout << "\033[1;31m----------------------------------\033[0m" << std::string(2, '\n');

std::cout << "\033[1;31m-----Creating Objects-----\033[0m" << std::string(2, '\n');
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << std::endl;
std::cout << "\033[1;31mAnimal (meta) is:\033[0m" << " " << meta->getType() << " " << std::endl;
std::cout << "\033[1;31mAnimal (j) is:\033[0m" << " " << j->getType() << " " << std::endl;
std::cout << "\033[1;31mAnimal (i) is:\033[0m" << " " << i->getType() << " " << std::string(2, '\n');



std::cout << "\033[1;31m-----Testing Animal Sounds-----\033[0m" << std::string(2, '\n');
std::cout << "\033[1;31mAnimal (meta) noise:\033[0m" << " ";
meta->makeSound();
std::cout << "\033[1;31mAnimal (j) noise:\033[0m" << " ";
j->makeSound();
std::cout << "\033[1;31mAnimal (i) noise:\033[0m" << " ";
i->makeSound();


std::cout << std::endl << "\033[1;31m-----Deleting Objects-----\033[0m" << std::string(2, '\n');
delete meta;
delete j; 
delete i;

/*-----------------------------------------------------------------------------------*/

std::cout << std::endl;
std::cout << "\033[1;31m----------------------------------\033[0m" << std::endl;
std::cout << "\033[1;31m|      Testing Wrong Version     |\033[0m" << std::endl;
std::cout << "\033[1;31m----------------------------------\033[0m" << std::string(2, '\n');


std::cout << "\033[1;31m-----Creating Objects-----\033[0m" << std::string(2, '\n');
const Animal* meta2 = new Animal();
const Animal* j2 = new Dog();
const WrongAnimal* i2 = new WrongCat();
std::cout << std::endl;
std::cout << "\033[1;31mAnimal (meta2) is:\033[0m" << " " << meta2->getType() << " " << std::endl;
std::cout << "\033[1;31mAnimal (j2) is:\033[0m" << " " << j2->getType() << " " << std::endl;
std::cout << "\033[1;31mAnimal (i2) is:\033[0m" << " " << i2->getType() << " " << std::string(2, '\n');


std::cout << "\033[1;31m-----Testing Animal Sounds-----\033[0m" << std::string(2, '\n');
std::cout << "\033[1;31mAnimal (meta2) noise:\033[0m" << " ";
meta2->makeSound();
std::cout << "\033[1;31mAnimal (j2) noise:\033[0m" << " ";
j2->makeSound();
std::cout << "\033[1;31mAnimal (i2) noise:\033[0m" << " ";
i2->makeSound();

std::cout << std::endl << "\033[1;31m-----Deleting Objects-----\033[0m" << std::string(2, '\n');
delete meta2;
delete j2; 
delete i2;

return 0;
}
