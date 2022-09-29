#include "../includes/Character.hpp"
#include "../includes/AMateria.hpp"

#include <iostream>

/*------------------------------*/
/*   Constructors/Destructor    */
/*------------------------------*/
Character::Character() {
	for (int i = 0; i < 4; i++)				/* Set inventory to empty at start */
		this->inventory[i] = nullptr;
	this->name = "Joe Smith";
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string& name) {
	for (int i = 0; i < 4; i++)				/* Set inventory to empty at start */
		this->inventory[i] = NULL;
	this->name = name;
	std::cout << "Character name constructor called" << std::endl;
}

Character::Character(const Character& other) {
	*this = other;
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) { delete this->inventory[i]; }
}

/*------------------------------*/
/*     Operator Overloads       */
/*------------------------------*/

Character	&Character::operator=(const Character& rhs) {
	std::cout << "Character copy assignment operator called" << std::endl;
	/* Copy non-allocated data */
	this->name = rhs.getName();

	/* Delete any stored invetory and discards */
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
	/* Deep copy inventory */
	for (int i = 0; i < 4; i++)
		this->inventory[i] = rhs.inventory[i]->clone();
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
		this->inventory[idx] = nullptr;
		std::cout << "Ability in inventory slot " << idx << " has been unequipped." << std::endl;
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

