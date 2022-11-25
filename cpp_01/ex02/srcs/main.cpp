#include <iostream>
#include <string>
#include <sstream>

#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int	main(void)
{
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|        HI THIS IS BRAIN!       |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::string brain = "HI THIS IS BRAIN";
	std::string *brainPTR = &brain;
	std::string &brainREF = brain;

	std::cout << RED"-----Testing Memory Adresses----" CLEAR << std::string(2, '\n');
	std::cout << "Address of string: " << &brain << std::endl;
	std::cout << "Address of PTR: " << &brainPTR << std::endl;
	std::cout << "Address of REF: " << &brainREF << std::endl;
	
	std::cout << std::endl;
	std::cout << RED"-----Testing Values----" CLEAR << std::string(2, '\n');
	std::cout << "Value of string: " << brain << std::endl;
	std::cout << "Value of PTR: " << brainPTR << std::endl;
	std::cout << "Value of REF: " << brainREF << std::endl;	
}