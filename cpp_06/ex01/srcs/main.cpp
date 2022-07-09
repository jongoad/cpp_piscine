#include "../includes/Data.hpp"

#define RED "\033[1;31m"
#define CLEAR "\033[0m"




int	main(void) {

	Data Guy;
	Data *NewGuy;

	Guy.age = 34;
	Guy.favColour = "green";
	Guy.firstName = "Jim";
	Guy.lastName = "Bob";

	std::cout << RED"--------------Testing before Serialize/Deserialize--------------" CLEAR << std::endl;

	std::cout << "Address of object: " << &Guy << std::endl;
	std::cout << "First Name: " << Guy.firstName << std::endl;
	std::cout << "Last Name: " << Guy.lastName << std::endl;
	std::cout << "Favourite Colour: " << Guy.favColour << std::endl;
	std::cout << "Age: " << Guy.age << std::endl;
	std::cout << std::endl;

	NewGuy = deserialize(serialize(&Guy));

	std::cout << RED"--------------Testing after Serialize/Deserialize--------------" CLEAR << std::endl;

	std::cout << "Address of object: " << NewGuy << std::endl;
	std::cout << "First Name: " << (*NewGuy).firstName << std::endl;
	std::cout << "Last Name: " << (*NewGuy).lastName << std::endl;
	std::cout << "Favourite Colour: " << (*NewGuy).favColour << std::endl;
	std::cout << "Age: " << (*NewGuy).age << std::endl;
	std::cout << std::endl;
}
