#ifndef ICE_HPP
#define ICE_HPP

#pragma once

#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {

    public:
        /* Constructors/Destructor */
        Ice();
        Ice(const Ice& other);
    	~Ice();

        /* Operator Overloads */
        Ice&    operator=(const Ice& rhs);

        /* Public Member Functions */
        AMateria*   clone() const;
        void        use(ICharacter& target);
};

#endif