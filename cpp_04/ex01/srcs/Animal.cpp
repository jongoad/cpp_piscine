#include "../includes/Animal.hpp"

/*------------------------------*/
/*    Constructors/Destructor   */
/*------------------------------*/

/* Default Constructor */
Animal::Animal() {
	this->type = "Ambiguous Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

/* Copy Constructor */
Animal::Animal(const Animal &animal) {
	*this = animal;
	std::cout << "Animal copy constructor called" << std::endl;
}

/* Destructor */
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Animal	&Animal::operator=(const Animal &animal) {
	this->type = animal.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/

/* Get animal type */
std::string	Animal::getType(void) const{
	return(this->type);
}

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/
void	Animal::makeSound(void) const{
	std::cout << "*Default animal noise*" << std::endl;
}
