#include "Inven.hpp"

Inven::Inven()
	: idx(0) {};

Inven::Inven(const Inven& copy)
	: idx(copy.idx)
{
	for (int i = 0; i < copy.idx; i++)
		slot[i] = copy.slot[i]->clone();
}

Inven& Inven::operator=(const Inven& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < idx; i++)
			delete slot[i];
		idx = copy.idx;
		for (int i = 0; i < idx; i++)
			slot[i] = copy.slot[i]->clone();
	}
	return (*this);
}

Inven::~Inven()
{
	for (int i = 0; i < idx; i++)
		delete slot[i];
}

void Inven::getMateria(AMateria* materia)
{
	if (materia)
	{
		if (idx == 4)
		{
			delete slot[0];
			for (int i = 0; i < 3; i++)
				slot[i] = slot[i + 1];
			slot[3] = materia;
		}
		else
		{
			slot[idx] = materia;
			idx++;
		}
	}
}
