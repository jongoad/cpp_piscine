#include "../includes/WrongAnimal.hpp"

/*------------------------------*/
/*    Constructors/Destructor   */
/*------------------------------*/
WrongAnimal::WrongAnimal() : type("Ambiguous Animal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/
WrongAnimal& WrongAnimal::operator=(WrongAnimal const &rhs) {
	this->type = rhs.type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return (*this);
}

/*------------------------------*/
/*       Setters/Getters        */
/*------------------------------*/
std::string	WrongAnimal::getType(void) const{
	return(this->type);
}

/*------------------------------*/
/*   Public Member Functions    */
/*------------------------------*/
void	WrongAnimal::makeSound(void) const{ std::cout << "*Default animal noise*" << std::endl; }
