
#include "../includes/AMateria.hpp"
#include "../includes/Character.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"


#define RED "\033[1;31m"
#define CLEAR "\033[0m"

int main()
{
	std::cout << RED"----------------------------------" CLEAR << std::endl;
	std::cout << RED"|   Testing Materia Interface    |" CLEAR << std::endl;
	std::cout << RED"----------------------------------" CLEAR << std::string(2, '\n');

	std::cout << RED"-----Creating Materia Spellbook-----" CLEAR << std::string(2, '\n');
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	std::cout << std::endl;
	std::cout << RED"-----Creating \"Me\"-----" CLEAR << std::string(2, '\n');
	ICharacter* me = new Character("me");

	std::cout << std::endl;
	std::cout << RED"-----Create Test Target----" CLEAR << std::string(2, '\n');
	ICharacter* bob = new Character("bob");
	
	std::cout << std::endl;
	std::cout << RED"-----Test Empty Inventory Item Use----" CLEAR << std::string(2, '\n');
	me->use(0, *bob);

	std::cout << std::endl;
	std::cout << RED"-----Test Empty Inventory Unequip----" CLEAR << std::string(2, '\n');
	me->unequip(0);

	std::cout << std::endl;
	std::cout << RED"-----Create and Equip Materia-----" CLEAR << std::string(2, '\n');
	AMateria* arr[5];
	arr[0] = src->createMateria("ice");
	arr[1] = src->createMateria("cure");
	arr[2] = src->createMateria("ice");
	arr[3] = src->createMateria("cure");
	arr[4] = src->createMateria("ice");
	me->equip(arr[0]);
	me->equip(arr[1]);
	me->equip(arr[2]);
	me->equip(arr[3]);

	std::cout << std::endl;
	std::cout << RED"-----Test Full Inventory Item Add-----" CLEAR << std::string(2, '\n');
	me->equip(arr[4]);

	std::cout << std::endl;
	std::cout << RED"-----Test Item Use-----" CLEAR << std::string(2, '\n');
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);


	std::cout << std::endl;
	std::cout << RED"-----Test Unequip-----" CLEAR << std::string(2, '\n');
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	std::cout << std::endl;
	std::cout << RED"-----Deleting Objects-----" CLEAR << std::string(2, '\n');
	delete bob;
	delete me;
	delete src;

	for (int i = 0; i < 5; i++)
		delete arr[i];

	return 0;
}