#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Inven.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	int idx;
	AMateria* slot[4];
	Inven inven;

public:
	Character();
	Character(std::string name);
	Character(const Character& copy);
	Character& operator=(const Character& copy);
	virtual ~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif