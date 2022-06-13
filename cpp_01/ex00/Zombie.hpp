#include "Zombie.h"

class Zombie {
	public:

		Zombie(std::string name);
		~Zombie();


		void		Announce(void);
		void		randomChump(std::string name);
		std::string	GetName();

	private:
		std::string name;

};