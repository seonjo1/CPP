#include "Contact.hpp"
#include <iostream>

class PhoneBook {
private:
	Contact book[8];
	int size;
	int	idx;
public:
	PhoneBook();
	// ~PhoneBook();
	// PhoneBook(const PhoneBook &copy);
	void Add();
	void Search();
	void Exit();
	void contact_info(int idx, Contact &contact);
	void print_info(const std::string &info, int len);
};