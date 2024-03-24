#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <new>
# include <cstdlib>

class Cat : public Animal
{
private:
	Brain* brain;

public:
	Cat();
	Cat(const Cat& copy);
	Cat& operator=(const Cat& copy);
	~Cat();
	void makeSound() const;
};

#endif
