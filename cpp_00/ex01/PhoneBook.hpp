#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();				/* Contructor */
		~PhoneBook();				/* Destructor */

		void	PromptInput();
		void	PromptAdd();
		void	AddContact();
		void	SearchContacts();
		bool	PrintPhonebook();	/* Return false if no contacts saved, or true is at least one is saved */
		void	PrintContact();

		void	RotateContacts();
		void	SetIndices();

	private:
		//Add array of contacts
		Contact Contacts[8];
};