#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

# define INIT_SCAV_HP 100
# define INIT_SCAV_ENERGY 50
# define INIT_SCAV_DAMAGE 20

class ScavTrap : virtual public ClapTrap {
	public:
		/* Constructors/Destructors */
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(ScavTrap const& other);
		~ScavTrap();

		/* Operator Overloads */
		ScavTrap&	operator=(ScavTrap const& rhs);

		/* Public Member Functions */
		void 		guardGate(void);

		/* Function Overrides */
		void		attack(std::string const& target);

		/* Setters & Getters */
		void		setGuard(const bool status);
		bool		getGuard(void) const;

	protected:
		/* Private attributes */
		bool guardingGate;
};

#endif




