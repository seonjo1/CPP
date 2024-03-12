#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

class PhoneBook {
private:
	Contact book[8];
	int size;
	int	idx;
public:
	PhoneBook();
	void ADD();
	Contact& SEARCH();
	void EXIT();
	void contact_info(int idx, Contact &contact);
	void print_info(std::string info, int len);
	bool is_invalid_idx(std::string& str);
	bool is_invalid_input(std::string& str);
};