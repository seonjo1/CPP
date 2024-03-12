#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <cctype>

class PhoneBook {
private:
	Contact book[8];
	int size;
	int	idx;
	void contact_info(int idx, Contact &contact);
	void print_info(std::string info, int len);
	bool is_invalid_idx(std::string& str);

public:
	PhoneBook();
	void ADD();
	Contact& SEARCH();
	void EXIT();
	bool is_invalid_input(std::string& str);
};

#endif