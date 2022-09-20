# include "../includes/PhoneBook.hpp"

void	lower(std::string& str) {
	for (std::string::iterator it=str.begin(); it!=str.end(); ++it)
		*it = tolower(*it);
}

int	main(void)
{
	PhoneBook NewPhoneBook;
	std::string Input;

	while(1)
	{
		NewPhoneBook.PromptInput();
		std::getline(std::cin >> std::ws, Input);
		if (Input.empty())
			exit(0);
		lower(Input);
		if (Input == "add")
			NewPhoneBook.AddContact();
		else if (Input == "search")
			NewPhoneBook.SearchContacts();
		else if (Input == "exit")
			std::exit(0);
		else {
			std::system("clear");
			std::cout << "Invalid Command. Please try again." << std::endl;
			sleep(1);
			continue;
		}
	}
}