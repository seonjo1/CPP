#include "Floor.hpp"

Floor::Floor()
    : idx(0) {};

Floor::Floor(const Floor& copy)
    : idx(copy.idx)
{
    for (int i = 0; i < copy.idx; i++)
        slot[i] = copy.slot[i]->clone();
}

Floor& Floor::operator=(const Floor& copy)
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

Floor::~Floor()
{
    for (int i = 0; i < idx; i++)
        delete slot[i];
}

void Floor::getMateria(AMateria* materia)
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
