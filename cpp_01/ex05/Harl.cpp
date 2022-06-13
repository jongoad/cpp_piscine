#include "Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void	Harl::complain(std::string level) {
	//Need to use the string level to call the appropriate function using a function pointer

	void (Harl::*complaint[])(void) = { /* Create an array of member function pointers */
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	std::string complaintLevel[] = {	/* Create an array of complaint strings */
		"debug",
		"info",
		"warning",
		"error",
	};
	
	for(int i = 0; i < 4; i++) {	/* Iterate through array to find match */
		void (Harl::*outputComplaint)(void) = complaint[i];	/* Set output function pointer */
		if (level == complaintLevel[i])
			(this->*outputComplaint)();
	}
}

/* Private member functions */
void	Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."<< std::endl;
}

void	Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
