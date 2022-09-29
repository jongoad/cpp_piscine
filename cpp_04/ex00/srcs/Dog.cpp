#include "../includes/Dog.hpp"

/*------------------------------*/
/*  Constructors & Destructor   */
/*------------------------------*/
Dog::Dog() : Animal ("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string const type) : Animal(type) {
	std::cout << "Dog type constructor called" << std::endl;
}

Dog::Dog(Dog const& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/
Dog&	Dog::operator=(Dog const& rhs) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

/*------------------------------*/
/*      Function Overrides      */
/*------------------------------*/
void	Dog::makeSound(void) const{ std::cout << "*Bark Bark*" << std::endl; }

