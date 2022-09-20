#ifndef HARL_HPP
#define HARL_HPP

#pragma once

#include <string>
#include <iostream>


class Harl {
	public:
		/* Constructors & Destructor */
		Harl();
		~Harl();

		/* Public Member Functions */
		void	complain(std::string level);
	
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif