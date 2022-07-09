#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"


Base::~Base() {

}

/* Randomly Generate one of the derived classes of base */
Base*   generate(void) {
	static bool seeded = false;
	if (seeded == false) {
		srand(time(NULL));
		seeded = true;
	}
	int i = rand() % 3;
	Base* tmp;
	switch (i) {
		case 0:
			tmp = new A();
			break;
		case 1:
			tmp = new B();
			break;
		case 2:
			tmp = new C();
			break;
	}
	return (tmp);
};

void	identify(Base* p) {
	std::cout << "(pointer)";
	if (dynamic_cast<A*>(p))
		std::cout << "Type of object is: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Type of object is: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Type of object is: C" << std::endl;
	else
		std::cerr << "Bad cast" << std::endl;
}

void	identify(Base& p) {
	try {
		std::cout << "(reference)";
		if (dynamic_cast<A*>(&p))
			std::cout << "Type of object is: A" << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << "Type of object is: B" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "Type of object is: C" << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
