#include "Harl.hpp"

int	main(void)
{
	Harl complainer;

	complainer.complain("debug");
	complainer.complain("info");
	complainer.complain("warning");
	complainer.complain("error");
	complainer.complain("something");
}