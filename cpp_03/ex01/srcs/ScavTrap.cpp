#include "../includes/ScavTrap.hpp"

/*------------------------------*/
/*    Constructors/Destructors  */
/*------------------------------*/

/* Default constructor */
ScavTrap::ScavTrap(void) {
	std::cout << "A new ScavTrap has been created!" << std::endl;
	this->guardingGate = false;
	this->setAttackDamage(INIT_SCAV_DAMAGE);
	this->setEnergyPoints(INIT_SCAV_ENERGY);
	this->setHitPoints(INIT_SCAV_HP);
}

/* Name constructor */
ScavTrap::ScavTrap(std::string name):  ClapTrap(name){
	this->guardingGate = false;
	this->setAttackDamage(INIT_SCAV_DAMAGE);
	this->setEnergyPoints(INIT_SCAV_ENERGY);
	this->setHitPoints(INIT_SCAV_HP);
	std::cout << "A new ScavTrap named " << this->getName()
		<< " has been created!" << std::endl;
}

/* Copy constructor */
ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap(scavtrap) {
	std::cout << "ScavTrap copy constructor called!" << std::endl;
	*this = scavtrap;
}

/* Destructor */
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->getName() <<
		" has been destroyed!" << std::endl;
}

/*------------------------------*/
/*    	Operator Overloads      */
/*------------------------------*/

/* Copy assignment operator */
ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap) {
	this->guardingGate = scavtrap.guardingGate;
	this->setName(scavtrap.getName()); 
	this->setHitPoints(scavtrap.getHitPoints());
	this->setEnergyPoints(scavtrap.getEnergyPoints());
	this->setAttackDamage(scavtrap.getAttackDamage());
	std::cout << "ScavTrap copy assignement operator called!"
		<< std::endl;
	return (*this);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

/* Guard gate toggle functions */
void ScavTrap::guardGate(void) {
	if (this->guardingGate == true) {						/* Check if already guarding gate */
		std::cout << this->getName() <<
			" is already guarding the gate!" << std::endl;
	}
	else {													/* Switch to gate guarding mode */
		this->guardingGate = true;
		std::cout << this->getName() <<
			" is now guarding the gate!" << std::endl;
	}
}

/*------------------------------*/
/*       Function Overrides     */
/*------------------------------*/

/* Attack override */
void	ScavTrap::attack(const std::string &target) {
	std::cout << "ScavTrap " << this->getName() << " attacks "
		<< target << " dealing " << this->getAttackDamage() <<
		" points of damage!" << std::endl;
}