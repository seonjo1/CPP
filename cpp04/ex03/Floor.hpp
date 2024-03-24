#ifndef FLOOR_HPP
# define FLOOR_HPP

#include "AMateria.hpp"

class Floor
{
private:
	AMateria* slot[4];
	int idx;

public:
	Floor();
	Floor(const Floor& copy);
	Floor& operator=(const Floor& copy);
	~Floor();
	void getMateria(AMateria* materia);
};

#endif