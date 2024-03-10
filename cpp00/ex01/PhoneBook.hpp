#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
	Contact book[8];
	int size;
	int	idx;
public:
	PhoneBook();
	void Add();
	void Search();
	void Exit();
	void contact_info(int idx, Contact &contact);
	void print_info(std::string info, int len);
};