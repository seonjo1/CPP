#include "Contact.hpp"

class PhoneBook {
private:
	Contact book[8];
	int	idx;
public:
	PhoneBook() : idx(1) {};
	~PhoneBook();
	PhoneBook(const PhoneBook &copy);
	PhoneBook &operator= (const PhoneBook &copy);
	void Add();
	void Search();
	void Exit();
};