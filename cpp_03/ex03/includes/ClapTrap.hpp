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
		ClapTrap();
		ClapTrap(std::string const name);
		ClapTrap(ClapTrap const& other);
		virtual ~ClapTrap();

		/* Operator Overloads */
		ClapTrap&	operator=(ClapTrap const& rhs);

		/* Public Member Functions */
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		/* Setters/Getters */
		std::string	getName(void) const;
		void		setName(std::string const name);
		int			getHitPoints(void) const;
		void		setHitPoints(int const amount);
		int			getInitHitPoints(void) const;
		void		setInitHitPoints(int const amount);
		int 		getEnergyPoints(void) const;
		void		setEnergyPoints(int const amount);
		int			getAttackDamage(void) const;
		void		setAttackDamage(int const amount);

	protected:
		/* Private Attributes */
		std::string	name;
		int			hitPoints;
		int			initHP;
		int			energyPoints;
		int			attackDamage;
};

#endif