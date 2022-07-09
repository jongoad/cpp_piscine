#include "../includes/ClapTrap.hpp"

/*------------------------------*/
/*    Constructors/Destructors  */
/*------------------------------*/

/* Default Constructor */
ClapTrap::ClapTrap(void) {
	this->hitPoints = INIT_HIT_POINTS;
	this->energyPoints = INIT_ENERGY_POINTS;
	this->attackDamage = INIT_ATTACK_DAMAGE;
	std::cout << "A nameless ClapTrap has been created!"
		<< std::endl;
}

/* Name constructor */
ClapTrap::ClapTrap(const std::string name) {
	this->name = name;
	this->hitPoints = INIT_HIT_POINTS;
	this->energyPoints = INIT_ENERGY_POINTS;
	this->attackDamage = INIT_ATTACK_DAMAGE;
	std::cout << "A new ClapTrap named " << this->name <<
		" has been created!" <<std::endl;
}

/* Copy Constructor */
ClapTrap::ClapTrap(const ClapTrap &claptrap) {
	*this = claptrap;
	std::cout << "ClapTrap " << claptrap.name <<
		" has been cloned!" << std::endl;
}

/* Destructor */
ClapTrap::~ClapTrap(void)	{
	std::cout << "ClapTrap " << this->name <<
		" has been destroyed!" << std::endl;
}

/*------------------------------*/
/*    	Operator Overloads      */
/*------------------------------*/

/* Copy Assignment Operator */
ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap) {
	std::string nameTemp = this->name;
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;	
	std::cout << "ClapTrap copy assignment operator called!"
		<< std::endl;
	return (*this);
}

/*------------------------------*/
/*    Public Member Functions   */
/*------------------------------*/

/* Perform an attack if enough energy */
void	ClapTrap::attack(const std::string &target) {
	if (this->energyPoints != 0) {							/* Check if enough energy to perform attack */
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name <<
			" attacks " << target << ", causing "
			<< this->attackDamage << " points of damage!"
			<< std::endl;  
	}
	else													/* Print message if not enough energy */	
		std::cout << "ClapTrap "<< this->name <<
			" does not have enough energy to attack!"
			<< std::endl;

}

/* Take damage and adjust HP, or check for death */
void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << this->name << " has taken "
		<< amount << " damage!" << std::endl;
	if ((this->hitPoints - amount) <= 0) {					/* Check for death */
		this->~ClapTrap();									/* Call destructor if destroyed */
	}
	else {													/* If not destroyed, display remaining HP */
		this->hitPoints -= amount;
		std::cout << "ClapTrap " << this->name << " has "
			<< this->hitPoints << " hitpoints remaining!"
			<< std::endl;
	}
			
}

/* Perform repair if enough energy */
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->getEnergyPoints() >= 1) {						/* Check if sufficient energy to repair */
		this->hitPoints += amount;							/* Perform repair and decrement energy */
		this->energyPoints--;
		std::cout << "ClapTrap " << this->name <<
			" has repaired " << amount << " hitpoints!"
			<< " They now have " << this->hitPoints <<
			" remaining!" << std::endl;
	}
	else													/* Print message if repair unsuccessful */
		std::cout << "ClapTrap " << this->getName() <<
		" has insufficient energy to repair" << std::endl;
}

/*------------------------------*/
/*       Setters/Getters 	    */
/*------------------------------*/

/* Get name */
std::string	ClapTrap::getName(void) const{
	return (this->name);
}

/* Set name */
void	ClapTrap::setName(std::string name)	{
	this->name = name;
}

/* Get hitpoints */
int	ClapTrap::getHitPoints(void) const{
	return (this->hitPoints);
}

/* Set hitpoints */
void	ClapTrap::setHitPoints(int amount) {
	this->hitPoints = amount;
}

/* Get energy points */
int	ClapTrap::getEnergyPoints(void) const{
	return (this->energyPoints);
}

/* Set energy points */
void	ClapTrap::setEnergyPoints(int amount) {
	this->energyPoints = amount;
}

/* Get attack damage */
int	ClapTrap::getAttackDamage(void) const{
	return (this->attackDamage);
}

/* Set attack damage */
void	ClapTrap::setAttackDamage(int amount) {
	this->attackDamage = amount;
}
