#include "../includes/Data.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"




int	main(void) {

	Data guy;
	guy.age = 34;
	guy.favColour = "green";
	guy.firstName = "Jim";
	guy.lastName = "Bob";

	std::cout << RED"--------------Testing before Serialize/Deserialize--------------" CLEAR << std::endl;
	std::cout << "Address of object: " << &guy << std::endl;
	std::cout << "First Name: " << guy.firstName << std::endl;
	std::cout << "Last Name: " << guy.lastName << std::endl;
	std::cout << "Favourite Colour: " << guy.favColour << std::endl;
	std::cout << "Age: " << guy.age << std::endl;
	std::cout << std::endl;
	
	Data *newGuy = deserialize(serialize(&guy));

	std::cout << RED"--------------Testing after Serialize/Deserialize--------------" CLEAR << std::endl;
	std::cout << "Address of object: " << newGuy << std::endl;
	std::cout << "First Name: " << (*newGuy).firstName << std::endl;
	std::cout << "Last Name: " << (*newGuy).lastName << std::endl;
	std::cout << "Favourite Colour: " << (*newGuy).favColour << std::endl;
	std::cout << "Age: " << (*newGuy).age << std::endl;
	std::cout << std::endl;
}