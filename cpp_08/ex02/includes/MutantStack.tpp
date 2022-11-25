#include "MutantStack.hpp"

/* Constructors & Destructor */

template <typename T, typename Container>
	MutantStack<T, Container>::MutantStack () {};

template <typename T, typename Container>
	MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& other) : MutantStack<T, Container>::stack(other) {};

template <typename T, typename Container>
	MutantStack<T, Container>::~MutantStack() {};


/* Operator Overloads */
template <typename T, typename Container>
	MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack<T, Container>& rhs) {
		if (*this != rhs) {
			this->MutantStack<T, Container>::stack::operator=(rhs);
			return (*this);
		}
	};

/* Iterator Functions */
template <typename T, typename Container>
	typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin() {
		return (this->c.begin());
};

template <typename T, typename Container>
	typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end() {
		return (this->c.end());
};

template <typename T, typename Container>
	typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin() {
		return (this->c.rbegin());
};

template <typename T, typename Container>
	typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend() {
		return (this->c.rend());
};

