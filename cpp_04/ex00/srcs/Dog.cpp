#include "../includes/Dog.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

/* Copy Constructor */
Dog::Dog(const Dog &dog) {
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}

/* Destructor */
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Dog    &Dog::operator=(const Dog &dog) {
	this->type = dog.type;
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/

/*------------------------------*/
/*      Function Overrides      */
/*------------------------------*/

void	Dog::makeSound(void) const{
	std::cout << "*Bark Bark*" << std::endl;
}

