#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#pragma once

#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource {
    public:
		/* Constructors/Destructor */
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		/* Operator Overloads */
		MateriaSource&	operator=(const MateriaSource &rhs);

		/* Public Member Functions */
		void		learnMateria(AMateria* amateria);
		AMateria*	createMateria(std::string const& type);

	private:
		AMateria *inventory[4];
};

#endif