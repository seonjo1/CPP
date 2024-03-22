#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <new>
# include <cstdlib>

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& copy);
	Ice& operator=(const Ice& copy);
	~Ice();

	AMateria* clone() const;
	void use(ICharacter& target);
};

#endif
