#include "../includes/WrongCat.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
WrongCat::WrongCat() {
	this->type = "Cat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

/* Copy Constructor */
WrongCat::WrongCat(const WrongCat &wrongcat) {
	*this = wrongcat;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

/* Destructor */
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

WrongCat    &WrongCat::operator=(const WrongCat &wrongcat) {
	this->type = wrongcat.type;
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/

/*------------------------------*/
/*      Function Overrides      */
/*------------------------------*/
