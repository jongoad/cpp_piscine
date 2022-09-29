#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#pragma once

#include <string>
#include "AMateria.hpp"
class AMateria;

class IMateriaSource {
    public:
		/* Constructors/Destructor */
		virtual ~IMateriaSource() {};

		/* Public Member Functions */
		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const& type) = 0;
};

#endif
