#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#pragma once

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
    public:
		/* Constructors/Destructor */
		MateriaSource();												/* Default Constructor */
		MateriaSource(const MateriaSource &materiasource);				/* Copy constructor */
		~MateriaSource();												/* Destructor */

		/* Operator Overloads */
		MateriaSource &operator=(const MateriaSource &materiasource);	/* Copy assignement operator */

		/* Public Member Functions */
		void learnMateria(AMateria* amateria);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria *inventory[4];
};

#endif