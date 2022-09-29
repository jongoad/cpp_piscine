#include "../includes/MateriaSource.hpp"
#include <iostream>

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)				/* Set inventory to empty at start */
		this->inventory[i] = NULL;
	std::cout << "MateriaSource default constructor called" << std::endl;
}

/* Copy Constructor */
MateriaSource::MateriaSource(const MateriaSource &other) {
	*this = other;
	std::cout << "Character copy constructor called" << std::endl;
}

/* Destructor */
MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

/* Copy Assignment Operator */
MateriaSource&	MateriaSource::operator=(const MateriaSource &rhs) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	for (int i = 0; i < 4; i++)
		this->inventory[i] = rhs.inventory[i]->clone();
	return (*this);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void	MateriaSource::learnMateria(AMateria* amateria) {
/* Check if there is an available inventory slot */
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = amateria;
			return ;
		}
	}
	delete amateria;
	std::cout << "There are no empty inventory spaces. Unequip an ability first." << std::endl;
}

/* Create New Materia Based on Input String */
AMateria*	MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] && (this->inventory[i]->getType() == type)) {
			AMateria *tmp = this->inventory[i]->clone();
			return (tmp);
		}
	}
	std::cout << "That Materia has not been learned yet" << std::endl;
	return (0);
}
