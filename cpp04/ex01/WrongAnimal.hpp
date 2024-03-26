#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP 

# include <iostream>
# include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& copy);
	WrongAnimal& operator=(const WrongAnimal& copy);
	~WrongAnimal();
	void makeSound() const;
	const std::string& getType() const;
};

#endif
