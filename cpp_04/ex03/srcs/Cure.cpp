#include "../includes/Cure.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Cure::Cure() : AMateria("cure") {
	// std::cout << "Cure default constructor called" << std::endl;
}

/* Copy Constructor */
Cure::Cure(const Cure &amateria) : AMateria(amateria) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

// /* Type Constructor */
// Cure::Cure(std::string const &type) {
// 	this->type = type;
// 	std::cout << "Cure type constructor called" << std::endl;
// }

/* Destructor */
Cure::~Cure() {
	// std::cout << "Cure destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Cure    &Cure::operator=(const Cure &amateria) {
	this->type = amateria.getType();
	// std::cout << "Cure copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

AMateria* Cure::clone() const{
	AMateria *clone = new Cure();
	return (clone);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
