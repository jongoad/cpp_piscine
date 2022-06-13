#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <string>
#include <iostream>


class Weapon {
	public:
		Weapon();
		Weapon(std::string const &type);
		~Weapon();

		const std::string &getType() const;
		void setType(std::string const &type);

	private:
		std::string type;
};

#endif