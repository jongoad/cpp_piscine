#include "../includes/Span.hpp"

/* Constructors/Destructors */

/* Default Constructor */
Span::Span(void) {

}

/* Size constructor */
Span::Span(const unsigned int N): size(N) {

}

/* Copy constructor */
Span::Span(const Span &other) {

}

/* Destructor */
Span::~Span(void) {
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

/* Return shortest span amongst stored values */
int	Span::shortestSpan(void) {
	int min = INT_MAX;
	int max = INT_MIN;
	if (this->store.size() <= 1)
		throw noSpanException();
	else {
		while (store.begin() != store.end()) {

		}
	}
}

/* Return longest span amongst stored values */
int	Span::longestSpan(void) {
	if (this->store.size() <= 1)
		throw noSpanException();
	else {

	}
}

