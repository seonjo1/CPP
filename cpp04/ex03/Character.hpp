#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string name;
    int idx;
    AMateria* slot[4];

public:
    Character();
    Character(std::string name);
    Character(const Character& copy);
    Character& operator=(const Character& copy);
    ~Character();
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    AMateria* getMateria(int idx);
};

#endif