#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#pragma once

#include "../includes/WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        /* Constructors & Destructor */
        WrongCat();
        WrongCat(std::string const type);
        WrongCat(WrongCat const& other);
        virtual ~WrongCat();

        /* Operator Overloads */
        WrongCat& operator=(WrongCat const& rhs);

        /* Function Overrides */
        void    makeSound(void) const;
};

#endif