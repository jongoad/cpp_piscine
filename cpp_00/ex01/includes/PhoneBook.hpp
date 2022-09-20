#include "PhoneBook.h"
#include "Contact.hpp"

class PhoneBook
{
	public:
	/* Constructors & Destructor */
		PhoneBook();
		~PhoneBook();

	/* Public Member Functions */
		void	PromptInput();
		void	PromptAdd();
		void	AddContact();
		void	SearchContacts();
		bool	PrintPhonebook();	/* Return false if no contacts saved, or true is at least one is saved */
		void	PrintContact();
		void	RotateContacts();
		void	SetIndices();

	private:
		Contact Contacts[8];
};