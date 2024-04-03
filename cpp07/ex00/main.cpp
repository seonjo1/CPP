#include "whatever.hpp"
#include <iostream>
#include <string>

class Object
{
private:
	std::string name;
	int num;
public:
	Object(std::string name, int num)
		: name(name), num(num) {};
	std::string getName() {	return (name); }
	int getNum() { return (num); }
	bool operator<(Object& obj) { return (this->num < obj.num);	}
	bool operator>(Object& obj) { return (this->num > obj.num);	}
};

int main()
{
	Object obj1("seon", 1);
	Object obj2("jo", 2);
	std::cout << "min : " << min(obj1, obj2).getName() << std::endl;
	std::cout << "max : " << max(obj1, obj2).getName() << std::endl;
	swap(obj1, obj2);
	std::cout << "obj1's name: " << obj1.getName() << "\nobj1's num: " << obj1.getNum() << std::endl;
	std::cout << "obj2's name: " << obj2.getName() << "\nobj2's num: " << obj2.getNum() << std::endl;

	const Object obj3("seon", 3);
	const Object obj4("jo", 4);
	std::cout << "min : " << min(obj3, obj4).getName() << std::endl;
	std::cout << "max : " << max(obj3, obj4).getName() << std::endl;

	std::cout << "min : " << min(obj1, obj4).getName() << std::endl;
	std::cout << "max : " << max(obj1, obj4).getName() << std::endl;

	return (0);
}