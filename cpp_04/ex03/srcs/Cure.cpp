#include "../includes/Cure.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure default constructor called" << std::endl;
}

/* Copy Constructor */
Cure::Cure(const Cure &other) : AMateria(other) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

/* Destructor */
Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Cure    &Cure::operator=(const Cure &rhs) {
	this->type = rhs.getType();
	// std::cout << "Cure copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

AMateria*	Cure::clone() const {
	AMateria *clone = new Cure();
	return (clone);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
