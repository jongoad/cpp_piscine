#include "../includes/WrongAnimal.hpp"

/*------------------------------*/
/*    Constructors/Destructor   */
/*------------------------------*/

/* Default Constructor */
WrongAnimal::WrongAnimal() {
	this->type = "Ambiguous Animal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

/* Copy Constructor */
WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal) {
	*this = wronganimal;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

/* Destructor */
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wronganimal) {
	this->type = wronganimal.type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/

/* Get animal type */
std::string	WrongAnimal::getType(void) const{
	return(this->type);
}

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/
void	WrongAnimal::makeSound(void) const{
	std::cout << "*Default animal noise*" << std::endl;
}
