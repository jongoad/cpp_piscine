# include "../includes/PhoneBook.hpp"

int	main(void)
{
	PhoneBook NewPhoneBook;
	std::string Input;

	while(1)
	{
		NewPhoneBook.PromptInput();
		std::cin >> Input;

		if (Input == "Add")
			NewPhoneBook.AddContact();
		else if (Input == "Search")
			NewPhoneBook.SearchContacts();
		else if (Input == "Exit")
			std::exit(0);
		else {
			std::system("clear");
			std::cout << "Invalid Command. Please try again." << std::endl;
			sleep(1);
			continue;
		}
	}
}