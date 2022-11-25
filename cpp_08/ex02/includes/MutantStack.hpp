#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#pragma once

#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        /* Constructors/Destructor */
        MutantStack();
        MutantStack(const MutantStack<T, Container> &other);
        virtual ~MutantStack();

        /* Operator Overloads */
        MutantStack &operator=(const MutantStack<T, Container>& rhs);

        /* Public Member Functions */

        typedef typename Container::iterator	        iterator;
        typedef typename Container::reverse_iterator	reverse_iterator;

		iterator	        begin();
        iterator            end();
        reverse_iterator    rbegin();
        reverse_iterator    rend();
};

#endif