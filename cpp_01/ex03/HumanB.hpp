#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	public:
		HumanB(std::string const &name);
		~HumanB();

		void setWeapon(Weapon const &weapon);
		void attack() const;
	private:
		const Weapon *weapon;
		std::string name;
};


#endif