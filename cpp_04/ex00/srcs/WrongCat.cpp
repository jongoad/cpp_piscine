#include "../includes/WrongCat.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/
WrongCat::WrongCat() {
	this->type = "Cat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

WrongCat&	WrongCat::operator=(WrongCat const& rhs) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound(void) const{ std::cout << "*Meeeeeeoooooww*" << std::endl; }
