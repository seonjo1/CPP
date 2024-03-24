#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <new>
# include <cstdlib>

class Dog : public Animal
{
private:
	Brain* brain;

public:
	Dog();
	Dog(const Dog& copy);
	Dog& operator=(const Dog& copy);
	virtual ~Dog();
	virtual void makeSound() const;
};

#endif
