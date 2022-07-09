#include "../includes/Cat.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Cat::Cat() {
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

/* Copy Constructor */
Cat::Cat(const Cat &cat) {
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

/* Destructor */
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/

Cat    &Cat::operator=(const Cat &cat) {
	this->type = cat.type;
	std::cout << "Cat copy assignement operator called" << std::endl;
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

void	Cat::makeSound(void) const{
	std::cout << "*Meeeeeooooowwwww*" << std::endl;
}

