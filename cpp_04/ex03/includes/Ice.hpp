#ifndef ICE_HPP
#define ICE_HPP

#pragma once

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {

    public:
        /* Constructors/Destructor */
        Ice();                                  /* Default Construtor */
        Ice(const Ice &amateria);               /* Copy Constructor */
        //Ice(std::string const & type);          /* Type constructor */
    	~Ice();                                 /* Destructor */

        /* Operator Overloads */
        Ice &operator=(const Ice &amateria);

        /* Public Member Functions */
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif