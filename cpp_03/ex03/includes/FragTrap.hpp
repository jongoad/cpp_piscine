#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

# define INIT_FRAG_HP 100
# define INIT_FRAG_ENERGY 100
# define INIT_FRAG_DAMAGE 30

class FragTrap : virtual public ClapTrap {
	public:
		/* Constructors/Destructors */
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const& other);
		~FragTrap();

		/* Operator Overloads */
		FragTrap &operator=(FragTrap const& rhs);

		/* Public Member Functions */
		void	highFivesGuys(void);

		/* Function Overrides */
		void	attack(std::string const& target);

	private:
};


#endif