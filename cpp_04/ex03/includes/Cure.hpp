#ifndef CURE_HPP
#define CURE_HPP

#pragma once

#include "AMateria.hpp"
#include <iostream>

class ICharacter;

class Cure : public AMateria {

    public:
        /* Constructors/Destructor */
        Cure();                                  /* Default Construtor */
        Cure(const Cure &amateria);               /* Copy Constructor */
        // Cure(std::string const & type);          /* Type constructor */
    	~Cure();                                 /* Destructor */

        /* Operator Overloads */
        Cure &operator=(const Cure &amateria);

             /* Public Member Functions */
        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif