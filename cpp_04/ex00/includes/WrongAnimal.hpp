#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
    public:
        /* Constructors & Destructor */
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const& other);
        virtual ~WrongAnimal();

        /* Operator Overloads */
        WrongAnimal& operator=(WrongAnimal const& rhs);

        /* Public Member Fuctions */
        void    makeSound(void) const;

        /* Setters/Getters */
        std::string getType(void) const;
        
    protected:
        std::string type;
};

#endif