#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define INIT_HIT_POINTS 10
# define INIT_ENERGY_POINTS 10
# define INIT_ATTACK_DAMAGE 0

class ClapTrap
{
	public:
		/* Constructors/Destructors */
		ClapTrap();										/* Default Constructor */
		ClapTrap(const std::string name);				/* Name constructor */
		ClapTrap(const ClapTrap &claptrap);				/* Copy constructor */
		~ClapTrap();									/* Destructor */

		/* Operator Overloads */
		ClapTrap 	&operator=(const ClapTrap &claptrap);	/* Copy assignment operator */

		/* Public Member Functions */
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		/* Setters/Getters */
		std::string	getName(void) const;
		void		setName(std::string name);
		int			getHitPoints(void) const;
		void		setHitPoints(int amount);
		int 		getEnergyPoints(void) const;
		void		setEnergyPoints(int amount);
		int			getAttackDamage(void) const;
		void		setAttackDamage(int amount);

	private:
		/* Private Attributes */
		std::string	name;
		int			hitPoints;
		int 		energyPoints;
		int			attackDamage;
};

#endif