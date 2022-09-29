#ifndef BRAIN_HPP
#define BRAIN_HPP

#pragma once
#include <string>
#include <iostream>

class Brain
{
    public:
        /* Constructors/Destructor */
        Brain();
        Brain(Brain const& other);
        ~Brain();

        /* Operator Overloads */
        Brain&  operator=(Brain const& rhs);

        /* Setters/Getters */
        std::string getIdea(int const i) const;
        void    setIdea(int i, std::string idea);

    protected:
        std::string ideas[100];
};

#endif