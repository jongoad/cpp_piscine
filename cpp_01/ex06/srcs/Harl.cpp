#include "../includes/Harl.hpp"
#include <iostream>
#include <string>

/* Constructors & Destructor */
Harl::Harl() {
	std::cout << "Harl Protocol Engaged" << std::endl;
}

Harl::~Harl() {
	std::cout << "Harl Protocol Disengaged" << std::endl;
}

/* Public Member Functions */
void	Harl::complain(std::string level) {

	void (Harl::*complaint[])(void) = { /* Create an array of member function pointers */
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	std::string complaintLevel[] = {	/* Create an array of complaint strings */
		"[DEBUG]",
		"[INFO]",
		"[WARNING]",
		"[ERROR]",
	};

	int i;
	
	// int test = Harl::getLevel(level);
	// std::cout << std::endl << test << std::endl;
	switch (Harl::getLevel(level)) {
		case (Harl::filterLevel (filterDebug)):
			i = 0;
			break;
		case (Harl::filterLevel (filterInfo)):
			i = 1;
			break;
		case (Harl::filterLevel (filterWarning)):
			i = 2;
			break;
		case (Harl::filterLevel (filterError)):
			i = 3;
			break;
		default:
			i = 4;
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	};

	while (i < 4) {
		std::cout << complaintLevel[i] << std::endl;
		void (Harl::*outputComplaint)(void) = complaint[i];	/* Set output function pointer */
			(this->*outputComplaint)();
		std::cout << std::endl;
		i++;
	}
}

/* Public Member Functions */
/* Return the enum for filter level based on input string */
Harl::filterLevel Harl::getLevel(std::string level) {
	std::string complaintLevels[] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
		"DEFAULT"
	};

	for (int i = 0; i < 5; i++)	{
		if (level == complaintLevels[i])
			return ((filterLevel)i);
	}
	return ((filterLevel) - 1);
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
