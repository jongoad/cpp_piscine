#include <iostream>
#include <string>
#include <sstream>

int	main(void)
{
	std::string Brain = "HI THIS IS BRAIN";
	std::string *p_Brain;
	p_Brain = &Brain;
	std::string &ref_Brain = Brain;

	
	std::cout << &Brain << std::endl;
	std::cout << &p_Brain << std::endl;
	std::cout << &ref_Brain << std::endl;
	
	std::cout << Brain << std::endl;
	std::cout << p_Brain << std::endl;
	std::cout << ref_Brain << std::endl;
	
}