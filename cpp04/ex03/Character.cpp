#include "Character.hpp"

Character::Character()
	: idx(0) {};

Character::Character(std::string name)
	: name(name), idx(0) {};

Character::Character(const Character& copy)
	: name(copy.name), idx(copy.idx)
{
	for (int i = 0; i < copy.idx; i++)
		slot[i] = copy.slot[i]->clone();
}

Character& Character::operator=(const Character& copy)
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

Character::~Character()
{
	for (int i = 0; i < idx; i++)
		delete slot[i];
}

const std::string& Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	if (m)
	{
		for (int i = 0; i < idx; i++)
		{
			if (slot[i]->getType().compare(m->getType()) == 0)
				return ;
		}
		if (idx == 4)
		{
			delete slot[0];
			for (int i = 0; i < 3; i++)
				slot[i] = slot[i + 1];
			slot[3] = m;
		}
		else
		{
			slot[idx] = m;
			idx++;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < this->idx)
	{
		floor.getMateria(slot[idx]);
		this->idx--;
		for (int i = idx; i < this->idx; i++)
			slot[i] = slot[i + 1];
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < this->idx)
		slot[idx]->use(target);
}
