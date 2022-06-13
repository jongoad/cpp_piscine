#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {
	public:
		HumanA(std::string const &name, const Weapon &weapon);
		~HumanA();
		void attack() const;

	private:
		const Weapon &weapon;
		std::string name;
};

#endif