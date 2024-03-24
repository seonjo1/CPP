#ifndef INVEN_HPP
# define INVEN_HPP

#include "AMateria.hpp"

class Inven
{
private:
	AMateria* slot[4];
	int idx;

public:
	Inven();
	Inven(const Inven& copy);
	Inven& operator=(const Inven& copy);
	~Inven();
	void getMateria(AMateria* materia);
};

#endif