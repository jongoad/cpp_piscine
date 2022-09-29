#include "../includes/Cat.hpp"

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/
Cat::Cat() : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string const type) : Animal(type) {
	std::cout << "Cat type constructor called" << std::endl;
}

Cat::Cat(Cat const& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

/*------------------------------*/
/*      Operator Overloads      */
/*------------------------------*/
Cat&	Cat::operator=(Cat const& rhs) {
	std::cout << "Cat copy assignement operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

/*------------------------------*/
/*      Function Overrides      */
/*------------------------------*/
void	Cat::makeSound(void) const{ std::cout << "*Meeeeeooooowwwww*" << std::endl; }