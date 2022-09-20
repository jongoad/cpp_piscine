#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#pragma once

#include <string>
#include <iostream>

class Zombie {
	public:
		/* Constructors & Destructors */
		Zombie(const std::string name);
		~Zombie();

		/* Public Member Functions */
		void				announce(void);
		std::string	const&	getName() const;

	private:
		std::string name;
};



#endif