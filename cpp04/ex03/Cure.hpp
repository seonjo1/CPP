#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <new>
# include <cstdlib>

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& copy);
	Cure& operator=(const Cure& copy);
	virtual ~Cure();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
