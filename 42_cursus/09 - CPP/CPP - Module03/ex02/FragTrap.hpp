#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap const &copy);
		FragTrap &operator=(FragTrap const &rhs);
		~FragTrap();

		void	highFivesGuys(void);
};

#endif
