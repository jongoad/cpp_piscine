#ifndef WEAPON_HPP
#define WEAPON_HPP

#pragma once

#include <string>
#include <iostream>


class Weapon {
	public:
		/* Constructors & Destructor */
		Weapon();
		Weapon(std::string const &type);
		~Weapon();

		/* Setters & Getters */
		std::string const& getType() const;
		void		setType(std::string const &type);

	private:
		std::string type;
};

#endif