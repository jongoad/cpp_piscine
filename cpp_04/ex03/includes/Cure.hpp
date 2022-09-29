#ifndef CURE_HPP
#define CURE_HPP

#pragma once

#include "AMateria.hpp"
#include <iostream>

class ICharacter;

class Cure : public AMateria {
    public:
        /* Constructors/Destructor */
        Cure();
        Cure(const Cure& other);
    	~Cure();

        /* Operator Overloads */
        Cure&   operator=(const Cure& rhs);

        /* Public Member Functions */
        AMateria*   clone() const;
        void        use(ICharacter& target);
};

#endif