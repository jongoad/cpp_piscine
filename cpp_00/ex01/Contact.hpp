# include <iostream>
# include <string>
# include <iomanip>
# include <unistd.h>
# include <ctype.h>

class Contact {
	public:
		Contact();						/* Constructor */
		~Contact();						/* Destructor */

		int			GetIndex();
		std::string GetFirstName();
		std::string GetLastName();
		std::string GetNickName();
		std::string GetNumber();
		std::string GetSecret();

		void		SetIndex(int);
		void		SetFirstName();
		void		SetLastName();
		void		SetNickName();
		void		SetNumber();
		void		SetSecret();

		void		CopyIndex(int);
		void		CopyFirstName(std::string);
		void		CopyLastName(std::string);
		void		CopyNickName(std::string);
		void		CopyNumber(std::string);
		void		CopySecret(std::string);

		bool		CheckContact();		/* Check to ensure no empty fields */
		std::string TruncateString(std::string);

	private:
		int			Index;
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string PhoneNumber;
		std::string DarkestSecret;
};