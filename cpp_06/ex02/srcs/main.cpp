#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"


#define RED "\033[1;31m"
#define CLEAR "\033[0m"



class Thing {

};


int	main(void) {
	Base* test1;
	Base* test2;
	Base* test3;

	test1 = generate();
	test2 = generate();
	test3 = generate();

	Base& ref1 = *test1;
	Base& ref2 = *test2;
	Base& ref3 = *test3;

	std::cout << RED"--------------Testing with pointer--------------" CLEAR << std::endl;
	identify(test1);
	identify(test2);
	identify(test3);


	std::cout << RED"--------------Testing with reference--------------" CLEAR << std::endl;
	identify(ref1);
	identify(ref2);
	identify(ref3);
}
