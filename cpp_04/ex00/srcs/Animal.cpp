#include "../includes/Animal.hpp"

/*------------------------------*/
/*    Constructors/Destructor   */
/*------------------------------*/

Animal::Animal() : type("Ambiguous Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const type) : type(type) {
	std::cout << "Animal type constructor called" << std::endl; 
}

Animal::Animal(const Animal &other) {
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Animal& Animal::operator=(Animal const& rhs) {
	this->type = rhs.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/

/* Get animal type */
std::string	Animal::getType(void) const{ return(this->type); }

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/
void	Animal::makeSound(void) const{ std::cout << "*Default animal noise*" << std::endl; }
