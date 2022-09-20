#ifndef HARL_HPP
#define HARL_HPP

#pragma once

#include <string>

class Harl {
	public:
		/* Constructors & Destructor */
		Harl();
		~Harl();

		/* Enumeration for Filter Level */
		enum	filterLevel {
			filterDebug = 0,
			filterInfo = 1,
			filterWarning = 2,
			filterError = 3,
			filterInsignificant = -1
		};

		/* Public Member Functions */
		void		complain(std::string level);
		filterLevel	getLevel(std::string level) const;

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif