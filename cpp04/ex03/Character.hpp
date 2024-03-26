#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Floor.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string name;
	int idx;
	AMateria* slot[4];
	Floor *floor;
public:
	Character();
	Character(std::string name);
	Character(std::string name, Floor* floor);
	Character(const Character& copy);
	Character& operator=(const Character& copy);
	virtual ~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif