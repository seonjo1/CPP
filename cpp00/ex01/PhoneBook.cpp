#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
 : idx(0), size(0) {};

void PhoneBook::ADD()
{
	std::string f_name, l_name, n_name, p_num, secret;

	std::cout << "first name : ";
	if (!std::getline(std::cin, f_name))
		throw(std::string("\nProgram terminated upon receiving EOF\n"));
	else if (is_invalid_input(f_name))
		throw(std::string("Invalid input\n\n"));
	
	std::cout << "last name : ";
	if (!std::getline(std::cin, l_name))
		throw(std::string("\nProgram terminated upon receiving EOF\n"));
	else if (is_invalid_input(l_name))
		throw(std::string("Invalid input\n\n"));

	std::cout << "nickname : ";
	if (!std::getline(std::cin, n_name))
		throw(std::string("\nProgram terminated upon receiving EOF\n"));
	else if (is_invalid_input(n_name))
		throw(std::string("Invalid input\n\n"));

	std::cout << "phone number : ";
	if (!std::getline(std::cin, p_num))
		throw(std::string("\nProgram terminated upon receiving EOF\n"));
	else if (is_invalid_input(p_num))
		throw(std::string("Invalid input\n\n"));

	std::cout << "darkest secret : ";
	if (!std::getline(std::cin, secret))
		throw(std::string("\nProgram terminated upon receiving EOF\n"));
	else if (is_invalid_input(secret))
		throw(std::string("Invalid input\n\n"));
	
	std::cout << std::setw(22) << std::setfill('-') << "\n\n";

	book[idx] = Contact (f_name, l_name, n_name, p_num, secret);
	idx = (idx + 1) % 8;
	if (size < 8) size++;
}

void PhoneBook::print_info(std::string info, int len)
{
	std::string str = info.substr(0, 10);
	if (len > 10) str[9] = '.';
	std::cout << std::setw(10) << std::setfill(' ') << str << "|";
}

void PhoneBook::contact_info(int idx, Contact &contact)
{
	std::cout << "|" << std::setw(10) << std::setfill(' ') << idx << "|";
	print_info(contact.get_first_name(), contact.get_first_name().length());
	print_info(contact.get_last_name(), contact.get_last_name().length());
	print_info(contact.get_nickname(), contact.get_nickname().length());
	std::cout << "\n";
}

bool PhoneBook::is_invalid_idx(std::string& str)
{
	if (str.length() != 1)
		return (1);
	if (str[0] < '0' || str[0] > '8')
		return (1);
	if (str[0] - '0' >= size)
		return (1);
	return (0);
}

bool PhoneBook::is_invalid_input(std::string& str)
{
	for (int i = 0; i < str.length(); i++)
		if (!isprint(str[i])) return true;
	return false;
}

Contact& PhoneBook::SEARCH()
{
	if (size == 0)
		throw (std::string("There are currently no registered contacts\n\n"));

	std::cout << "|" << std::setw(10) << std::setfill(' ') << "index";
	std::cout << "|" << std::setw(10) << std::setfill(' ') << "first name";
	std::cout << "|" << std::setw(10) << std::setfill(' ') << "last name";
	std::cout << "|" << std::setw(10) << std::setfill(' ') << "nickname";
	std::cout << "|\n";
	for (int i = 0; i < size; i++)
		contact_info(i, book[i]);
	std::cout << std::setw(46) << std::setfill('-') << "\n";

	int idx;
	while (true)
	{
		std::string str;
		std::cout << "Index : ";
		if (!std::getline(std::cin, str))
			throw(std::string("\nProgram terminated upon receiving EOF\n"));
		else if (is_invalid_input(str))
			throw(std::string("Invalid input\n\n"));
		if (is_invalid_idx(str))
		{
			std::cerr << "Please re-enter the index\n\n";
			continue ;
		}
		idx = str[0] - '0';
		break ;
	}
	return (book[idx]);
}

void PhoneBook::EXIT()
{
	std::cout << "The program will exit.\n";
	std::exit(0);
}