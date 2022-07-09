#include "../includes/Ice.hpp"
#include <iostream>

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
}

/* Copy Constructor */
Ice::Ice(const Ice &amateria) : AMateria(amateria) {
	std::cout << "Ice copy constructor called" << std::endl;
}

// /* Type Constructor */
// Ice::Ice(std::string const &type) {
// 	this->type = type;
// 	std::cout << "Ice type constructor called" << std::endl;
// }

/* Destructor */
Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Ice    &Ice::operator=(const Ice &amateria) {
	this->AMateria::operator=(amateria);
	std::cout << "Ice copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

AMateria* Ice::clone() const{
	AMateria *clone = new Ice();
	return (clone);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
