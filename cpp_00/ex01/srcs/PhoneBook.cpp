# include "../includes/PhoneBook.hpp"

/* Constructor/Destructor */
PhoneBook::PhoneBook(){
	this->SetIndices();
}

PhoneBook::~PhoneBook(){
	return;
}

/* Control Functions */
void	PhoneBook::PromptInput() {
	std::system("clear");
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|        Crappy Phonebook Main Menu       |" << std::endl;
	std::cout << "----------+----------+----------+----------" << std::endl;
	std::cout << "|     Welcome to Crappy Phonebook!        |" << std::endl;
	std::cout << "|  Enter one of the following commands:   |" << std::endl;
	std::cout << "|          Add, Search, or Exit           |" << std::endl;
	std::cout << "----------+----------+----------+----------" << std::endl << std::endl;
	std::cout << "Enter your command: " << std::endl;
}

void	PhoneBook::PromptAdd()	{
	std::system("clear");
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|     Crappy Phonebook Contact Manager     |" << std::endl;
	std::cout << "----------+----------+----------+----------" << std::endl;
	std::cout << "|   Please enter contact details below:   | " << std::endl;
	std::cout << "----------+----------+----------+----------" << std::endl << std::endl;
}

void	PhoneBook::AddContact() {

	
	Contact Input; /* Use a temporary contact to store the inputs before checking */

	this->PromptAdd();
	std::cout << "Enter First Name:" << std::endl;
	Input.SetFirstName();
	this->PromptAdd();
	std::cout << "Enter Last Name:" << std::endl;
	Input.SetLastName();
	this->PromptAdd();
	std::cout << "Enter Nickname:" << std::endl;
	Input.SetNickName();
	this->PromptAdd();
	std::cout << "Enter Phone Number:" << std::endl;
	Input.SetNumber();
	this->PromptAdd();
	std::cout << "Enter Darkest Secret:" << std::endl;
	Input.SetSecret();
	std::system("clear");

	if (!Input.CheckContact()) /* Check if any fields where blank, if so reject contact */
		std::cout << "One or more fields where empty. Contact rejected" << std::endl;
	else
	{
		this->RotateContacts();
		this->Contacts[0].CopyFirstName(Input.GetFirstName());
		this->Contacts[0].CopyLastName(Input.GetLastName());
		this->Contacts[0].CopyNickName(Input.GetNickName());
		this->Contacts[0].CopyNumber(Input.GetNumber());
		this->Contacts[0].CopySecret(Input.GetSecret());
	}
}

void	PhoneBook::SearchContacts() {
	
	if (this->PrintPhonebook()) /* Is this returns false there are no contacts stored, so do not run prompt for index */
		this->PrintContact();
}

bool	PhoneBook::PrintPhonebook() {

	if (!this->Contacts[0].CheckContact())
	{
		std::system("clear");
		std::cout << "There are no contacts stored." << std::endl;
		return (false);
	}

	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|  Crappy Phonebook Search System v3.14   |" << std::endl;
	std::cout << "----------+----------+----------+----------" << std::endl;
	std::cout << "|  Index  |   First  |   Last   | Nickname|" << std::endl;
	std::cout << "----------+----------+----------+----------" << std::endl;

	for(int i = 0; i < 8; i++)
	{
		if (!this->Contacts[i].CheckContact())
			break;
		std::cout << std::setiosflags(std::ios::right);
		std::cout << std::setw(10) << this->Contacts[i].GetIndex() << "|";
		std::cout << std::setw(10) << this->Contacts[i].TruncateString(this->Contacts[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << this->Contacts[i].TruncateString(this->Contacts[i].GetLastName()) << "|";
		std::cout << std::setw(10) << this->Contacts[i].TruncateString(this->Contacts[i].GetNickName()) << std::endl;
	}
	return (true);
}

void	PhoneBook::PrintContact() {
while (1)
	{
		std::string Input;
		std::system("clear");
		this->PrintPhonebook();
		std::cout << std::endl << "Enter a contact index to see full contact details:" << std::endl;
		std::cin >> Input;
		if (Input.length() == 1 && isdigit(Input[0]) && Input[0] != '0' && Input[0] != '9' && this->Contacts[(Input[0] - '0')  - 1].CheckContact()) 
		{
			std::system("clear");
			std::cout << "-------------------------------------------" << std::endl;
			std::cout << "|  Crappy Phonebook Search System v3.14   |" << std::endl;
			std::cout << "----------+----------+----------+----------" << std::endl;
			std::cout << "First Name: " << this->Contacts[(Input[0] - '0')  - 1].GetFirstName() << std::endl;
			std::cout << "Last Name: " << this->Contacts[(Input[0] - '0')  - 1].GetLastName() << std::endl;
			std::cout << "Nickname: " << this->Contacts[(Input[0] - '0')  - 1].GetNickName() << std::endl;
			std::cout << "Phone Number: " << this->Contacts[(Input[0] - '0')  - 1].GetNumber() << std::endl;
			std::cout << "Darkest Secret: " << this->Contacts[(Input[0] - '0')  - 1].GetSecret() << std::endl;
			break;
		}
		else
		{
			std::cout << "Invalid input. Please try again." << std::endl;
			sleep(1);
		}
	}
	std::cout << std::endl << "Press enter to return to main menu." << std::endl;
	std::system("read");
}

void	PhoneBook::RotateContacts() {

	for (int i = 7; i > 0; i--)
	{
			this->Contacts[i].CopyFirstName(this->Contacts[i - 1].GetFirstName());
			this->Contacts[i].CopyLastName(this->Contacts[i - 1].GetLastName());
			this->Contacts[i].CopyNickName(this->Contacts[i - 1].GetNickName());
			this->Contacts[i].CopyNumber(this->Contacts[i - 1].GetNumber());
			this->Contacts[i].CopySecret(this->Contacts[i - 1].GetSecret());
	}
}

/* Utility Functions */

void	PhoneBook::SetIndices()	{
	for (int i = 0; i < 8; i++)
		this->Contacts[i].SetIndex(i + 1);
}
