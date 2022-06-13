#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl {
	public:
		Harl();
		~Harl();

		enum	filterLevel {
			filterDebug = 0,
			filterInfo = 1,
			filterWarning = 2,
			filterError = 3,
			filterInsignificant = -1
		};

		void		complain(std::string level);
		filterLevel	getLevel(std::string level);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif