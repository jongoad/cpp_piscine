#ifndef HUMANA_HPP
#define HUMANA_HPP

#pragma once

#include "Weapon.hpp"

class HumanA {
	public:
		/* Constructors & Destructor */
		HumanA(std::string const &name, Weapon& weapon);
		~HumanA();

		/* Public Member Functions */
		void attack() const;

	private:
		Weapon		&weapon;
		std::string	name;
};

#endif