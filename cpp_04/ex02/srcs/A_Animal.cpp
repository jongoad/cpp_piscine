#include "../includes/A_Animal.hpp"

/*------------------------------*/
/*    Constructors/Destructor   */
/*------------------------------*/

A_Animal::A_Animal() : type("Ambiguous Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

A_Animal::A_Animal(std::string const type) : type(type) {
	std::cout << "Animal type constructor called" << std::endl; 
}

A_Animal::A_Animal(const A_Animal &other) {
	*this = other;
	std::cout << "Animal copy constructor called" << std::endl;
}

A_Animal::~A_Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

A_Animal& A_Animal::operator=(A_Animal const& rhs) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/

/* Get animal type */
std::string	A_Animal::getType(void) const{ return(this->type); }
