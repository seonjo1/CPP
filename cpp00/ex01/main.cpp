#include "PhoneBook.hpp"

void print_contact(Contact &contact)
{
	std::cout << "first_name : " << contact.get_first_name() << std::endl;
	std::cout << "last_name : " << contact.get_last_name() << std::endl;
	std::cout << "nickname : " << contact.get_nickname() << std::endl;
	std::cout << "phone_number : " << contact.get_phone_number() << std::endl;
	std::cout << "darkest_secret : " << contact.get_darkest_secret() << std::endl;
	std::cout << "\n";
}

int main(int argc, char **argv)
{
	PhoneBook book;

	if (argc != 1)
	{
		std::cerr << "too many arguments\n";
		(void)argv;
		return (1);
	}
	while (true)
	{
		try
		{
			std::cout << "Please enter command\n";
			std::cout << "1. ADD\n";
			std::cout << "2. SEARCH\n";
			std::cout << "3. EXIT\n\n";
			std::string cmd;
			if (!std::getline(std::cin, cmd))
				throw(std::string("Program terminated upon receiving EOF\n\n"));
			else if (book.is_invalid_input(cmd))
				throw(std::string("Invalid input\n\n"));
			std::cout << std::setw(46) << std::setfill('-') << "\n";
			if (cmd.compare("ADD") == 0)
				book.ADD();
			else if (cmd.compare("SEARCH") == 0)
			{
				Contact& contact = book.SEARCH();
				print_contact(contact);
			}
			else if (cmd.compare("EXIT") == 0)
			{
				book.EXIT();
				break ;
			}
			else
				std::cerr << "Put in a valid command\n\n";
		}
		catch(const std::string& e)
		{
			std::cerr << e;
			std::cin.clear();
			clearerr(stdin);
		}
	}
	return (0);
}