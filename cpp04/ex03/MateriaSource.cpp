
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
    : idx(0) {};

MateriaSource::MateriaSource(const MateriaSource& copy)
    : idx(copy.idx)
{
    for (int i = 0; i < copy.idx; i++)
        slot[i] = copy.slot[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
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

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < idx; i++)
        delete slot[i];
}

void MateriaSource::learnMateria(AMateria* materia)
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
    else
        std::cout << "fail to learn materia\n";
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < idx; i++)
    {
        if (slot[i]->getType().compare(type) == 0)
            return (slot[i]->clone());
    }
    return (0);
}
