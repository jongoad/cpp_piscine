#ifndef CAT_HPP
#define CAT_HPP

#pragma once

#include "../includes/A_Animal.hpp"
#include "../includes/Brain.hpp"

class Cat : public A_Animal{
    public:
        /* Constructors & Destructor */
        Cat();
        Cat(std::string const type);
        Cat(Cat const& other);
        virtual ~Cat();

        /* Operator Overloads */
        Cat& operator=(Cat const& rhs);

        /* Function Overrides */
        void    makeSound(void) const;

        /* Setters & Getters */
        Brain*   getBrain(void);
        
        private: 
            Brain *brain;
};

#endif