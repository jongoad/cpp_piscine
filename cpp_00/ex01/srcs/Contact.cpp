#include "../includes/Contact.hpp"

Contact::Contact() {
	return;
}

Contact::~Contact() {
	return;
}

/* Accessor Functions */

int Contact::GetIndex() {
	return (this->Index);
}

std::string Contact::GetFirstName() {
	return (this->FirstName);
}

std::string Contact::GetLastName() {
	return (this->LastName);
}

std::string Contact::GetNickName() {
	return (this->NickName);
}

std::string Contact::GetNumber() {
	return (this->PhoneNumber);
}

std::string Contact::GetSecret() {
	return (this->DarkestSecret);
}

/* Setter Functions */

void	Contact::SetIndex(int i) {
	this->Index = i;
}

void	Contact::SetFirstName() {
	std::string input;
	std::getline(std::cin >> std::ws, input);
	if (input.empty())
		exit(0);
	this->FirstName = input;
}

void Contact::SetLastName() {
	std::string input;
	std::getline(std::cin >> std::ws, input);
	if (input.empty())
		exit(0);
	this->LastName = input;
}

void	Contact::SetNickName() {
	std::string input;
	std::getline(std::cin >> std::ws, input);
	if (input.empty())
		exit(0);
	this->NickName = input;
}

void	Contact::SetNumber() {
	std::string input;
	std::getline(std::cin >> std::ws, input);
	if (input.empty())
		exit(0);
	this->PhoneNumber = input;
}

void	Contact::SetSecret() {
	std::string input;
	std::getline(std::cin >> std::ws, input);
	if (input.empty())
		exit(0);
	this->DarkestSecret = input;
}

/* Copy functions */
void	Contact::CopyFirstName(std::string Input) {
	this->FirstName = Input;
}

void	Contact::CopyLastName(std::string Input) {
	this->LastName = Input;
}

void	Contact::CopyNickName(std::string Input) {
	this->NickName = Input;
}

void	Contact::CopyNumber(std::string Input) {
	this->PhoneNumber = Input;
}

void	Contact::CopySecret(std::string Input) {
	this->DarkestSecret = Input;
}

bool	Contact::CheckContact() {
	if (this->FirstName.empty() || this->LastName.empty() || this->NickName.empty()
		|| this->PhoneNumber.empty() || this->DarkestSecret.empty())
		return (false);
	return (true);
}

/* Utility Functions */

std::string Contact::TruncateString(std::string Input) {
	if (Input.length() > 10)
		return (Input.substr(0, 9) + ".");
	return (Input);
}
