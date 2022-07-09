#include "../includes/AMateria.hpp"
#include <iostream>
/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
AMateria::AMateria(std::string const &type) : type(type) {
	std::cout << "AMateria default constructor called" << std::endl;
}

/* Copy Constructor */
AMateria::AMateria(const AMateria &amateria) : type(amateria.type) {
	*this = amateria;
	std::cout << "AMateria copy constructor called" << std::endl;
}

/* Destructor */
AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

AMateria    &AMateria::operator=(const AMateria &amateria) {
	this->type = amateria.type;
	std::cout << "AMateria copy constructor called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/

std::string const & AMateria::getType() const{
	return (this->type);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void AMateria::use(ICharacter &target) {
	(void)target;
}
