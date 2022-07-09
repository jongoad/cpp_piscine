#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#pragma once

#include <string>
#include "ICharacter.hpp"

class AMateria
{
    public:
	
		/* Constructors/Destructor */
		// AMateria();
		AMateria(const AMateria &amateria);
		AMateria(std::string const &type);
		virtual ~AMateria();


		/* Public Member Functions */
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		/* Setters/Getters */
		std::string const & getType() const; //Returns the materia type
		
		/* Operator Overloads */
		AMateria &operator=(const AMateria &amateria);

    protected:
        std::string type;
};

#endif