#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	int idx;
	AMateria *slot[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& copy);
	MateriaSource& operator=(const MateriaSource& copy);
	virtual ~MateriaSource();
	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);
};

#endif
