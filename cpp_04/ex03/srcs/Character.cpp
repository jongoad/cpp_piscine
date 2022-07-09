#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"

#include <iostream>

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/

/* Default Constructor */
Character::Character() {
	for (int i = 0; i < 4; i++)				/* Set inventory to empty at start */
		this->inventory[i] = NULL;
	this->name = "Joe Smith";
	this->numberDiscarded = 0;
	this->discard = NULL;
	std::cout << "Character default constructor called" << std::endl;
}

/* Name Constructor */
Character::Character(const std::string &name) {
	for (int i = 0; i < 4; i++)				/* Set inventory to empty at start */
		this->inventory[i] = NULL;
	this->numberDiscarded = 0;
	this->discard = NULL;
	this->name = name;
	std::cout << "Character name constructor called" << std::endl;
}

/* Copy Constructor */
Character::Character(const Character &character) {
	*this = character;
	std::cout << "Character copy constructor called" << std::endl;
}

/* Destructor */
Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < this->numberDiscarded; i++)
		delete this->discard[i];
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Character	&Character::operator=(const Character &character) {
	std::cout << "Character copy assignment operator called" << std::endl;
	/* Copy non-allocated data */
	this->name = character.getName();		/* Set name */
	this->numberDiscarded = character.numberDiscarded;

	/* Delete any stored invetory and discards */
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	for (int i = 0; i < this->numberDiscarded; i++)
		delete this->discard[i];

	/* Deep copy inventory */
	for (int i = 0; i < 4; i++)
		this->inventory[i] = character.inventory[i]->clone();

	/* Deep copy discards */
	AMateria *tmp[character.numberDiscarded];
	for (int i = 0; i < character.numberDiscarded; i++)
		tmp[i] = character.discard[i]->clone();
	this->discard = tmp;
	return (*this);

}

/*------------------------------*/
/*        Setters/Getters       */
/*------------------------------*/
std::string const & Character::getName() const {
	return(this->name);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

/* Equip a new ability */
void Character::equip(AMateria* m) {
	/* Check if there is an available inventory slot */
	for (int i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = m;
			return ;
		}
	}
	std::cout << "There are no empty inventory spaces. Unequip an ability first." << std::endl;
}

/* Unequip an ability */
void Character::unequip(int idx) {
	if (this->inventory[idx]) {
		AMateria *tmp[this->numberDiscarded + 1];				/* Create new array for discards */
		if (this->discard) {									/* If anything already discarded, copy to tmp array */
			for (int i = 0; i < this->numberDiscarded; i++)		/* Copy existing discards */
				tmp[i] = this->discard[i];
		}
		tmp[this->numberDiscarded] = this->inventory[idx];		/* Copy new discard */
		this->discard= tmp;							   		 	/* Assign new discard array */ 
		this->inventory[idx] = NULL;							/* Set cleared inventory slot to NULL */
		this->numberDiscarded++;								/* Increment number discarded */
	}
	else
		std::cout << "Inventory slot " << idx << " is already empty!" << std::endl;
}

/* Use an ability */
void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3 && this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << "Inventory slot " << idx << " is empty" << std::endl;
}

