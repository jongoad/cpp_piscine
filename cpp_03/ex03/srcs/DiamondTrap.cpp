#include "../includes/DiamondTrap.hpp"

/*------------------------------*/
/*    Constructors/Destructors  */
/*------------------------------*/

/* Default Constructor */
DiamondTrap::DiamondTrap(void) {
	this->name = "Default";
	this->FragTrap::setHitPoints(INIT_FRAG_HP);
	this->ScavTrap::setEnergyPoints(INIT_SCAV_ENERGY);
	this->FragTrap::setAttackDamage(INIT_FRAG_DAMAGE);
	std::cout << "A new DiamondTrap has been created!" << std::endl;
}

/* Name Constructor */
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name) {
	this->FragTrap::setHitPoints(INIT_FRAG_HP);
	this->ScavTrap::setEnergyPoints(INIT_SCAV_ENERGY);
	this->FragTrap::setAttackDamage(INIT_FRAG_DAMAGE);
	std::cout << "A new DiamondTrap named " << this->name << " has been created!" << std::endl;
}
/* Copy Constructor */
DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap): ClapTrap(diamondtrap) {
	std::cout << "DiamondTrap copy constructor called!" << std::endl;
	*this = diamondtrap;
}

/* Destructor */
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->getLocalName() << " has been destroyed!" << std::endl;
}

/*------------------------------*/
/*    	Operator Overloads      */
/*------------------------------*/

/* Copy Assignment Operator */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap) {
	this->name = diamondtrap.name;
	this->setName(diamondtrap.getName());
	this->setHitPoints(diamondtrap.getHitPoints());
	this->setEnergyPoints(diamondtrap.getEnergyPoints());
	this->setAttackDamage(diamondtrap.getAttackDamage());
	this->setGuard(diamondtrap.getGuard());
	std::cout << "DiamondTrap copy assignement operator called!" << std::endl;
	return (*this);
}


/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

void	DiamondTrap::whoAmI(void)	{
	std::cout << "DiamondTrap name is " << this->name <<
		". ClapTrap name is " << this->getName() << "." << std::endl;
}

/*------------------------------*/
/*       Function Overrides     */
/*------------------------------*/

/* Attack Override Function */
void	DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

/*------------------------------*/
/*       Setters/Getters 	    */
/*------------------------------*/

std::string	DiamondTrap::getLocalName(void) const {
	return (this->name);
}