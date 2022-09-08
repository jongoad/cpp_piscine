#include "../includes/Span.hpp"
#include <numeric>
#include <cstdlib>

/* Constructors/Destructors */

/* Default Constructor */
Span::Span(void): size(0) {

}

/* Size constructor */
Span::Span(const unsigned int N): size(N) {

}

/* Copy constructor */
Span::Span(const Span &other): size(other.size) {
	*this = other;
}

/* Destructor */
Span::~Span(void) {
}

/* Operator Overloads */

/* Copy assignment operator overload */
Span& Span::operator=(const Span& other) {
	if (this != &other) {
			this->store = other.store;
	}
	return (*this);
}


/* Public Member Functions */

/* Attempt to add number to storage */
void	Span::addNumber(const int num) {
	if (this->store.size() == this->size)
		throw noSpaceException();
	else {
		store.push_back(num);
	}
}

/* Attempt to add multiple numbers to storage */
void	Span::addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end) {
	int dist = std::distance(begin, end);
	if (dist + this->store.size() > this->size) { /* If not enough space, add until container full and throw exception */
		this->store.insert(this->store.end(), begin, begin + (this->size - this->store.size()));
		throw noSpaceException();
	}
	else {
		this->store.insert(this->store.end(), begin, end);
	}
}

/* Attempt to return the shortest span amongst stored values */
unsigned int Span::shortestSpan() const
{
	std::vector<int> tmp;

	int (*iabs)(int) = &std::abs; /* Create pointer to absolute value function */
	if (this->store.size() <= 1)
		throw noSpanException();
	std::adjacent_difference(this->store.begin(), this->store.end(), std::back_inserter(tmp)); /* Get difference between each pair of adjacent elements, inserting result and end of tmp container using back_inserter */
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), iabs); /* Apply absolute value function to range so we can compare all values properly*/
	return *min_element(tmp.begin(), tmp.end());
}

/* Attempt to return the longest span amongst stored values */
unsigned int Span::longestSpan() const
{
	std::vector<int> tmp;

	int (*iabs)(int) = &std::abs;
	if (this->store.size() <= 1)
		throw noSpanException();
	std::adjacent_difference(this->store.begin(), this->store.end(), std::back_inserter(tmp));
	std::transform(tmp.begin(), tmp.end(), tmp.begin(), iabs);
	return *max_element(tmp.begin(), tmp.end());
}
