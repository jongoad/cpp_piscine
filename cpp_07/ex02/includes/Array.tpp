#include "Array.hpp"

/* Copy constructor */
template <class T>
Array<T>::Array(const Array& other) {
	this->num = other.num;
	this->arr = new T[other.num];
	for (unsigned int i = 0; i < other.num; i++)
		this->arr[i] = other.arr[i];
}

/* Destructor */
template <class T>
Array<T>::~Array(void) {
	delete [] this->arr;
}

/* Copy assigment operator overlaod */
template <class T>
Array<T>&	Array<T>::operator=(const Array& rhs) {
	if (this != &rhs) {
		this->~Array();
		this->num = rhs.num;
		this->arr = new T[this->num];
		for (unsigned int i = 0; i < this->num; i++)
			this->arr[i] = rhs.arr[i];
	}
	return (*this);
}

/* Subscript operator overload */
template <class T>
T&		Array<T>::operator[](unsigned int n) {
		if (n >= this->num)
			throw Array::invalidIndex();
		else
			return (this->arr[n]);
}

/* Size member function */
template <class T>
unsigned int	Array<T>::size(void) {
	return (this->num);
}