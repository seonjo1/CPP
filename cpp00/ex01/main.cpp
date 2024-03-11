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

int main()
{
	PhoneBook book;

	while (true)
	{
		std::cout << "Please enter command\n";
		std::cout << "1. ADD\n";
		std::cout << "2. SEARCH\n";
		std::cout << "3. EXIT\n\n";
		std::string cmd;
		if (!std::getline(std::cin, cmd))
		{
			std::cout << "Program terminated upon receiving EOF\n";
			std::exit(1);
		}
		if (cmd.compare("ADD") == 0)
		{
			std::cout << std::setw(21) << std::setfill('-') << "\n";
			book.ADD();
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			try
			{
				Contact& contact = book.SEARCH();
				print_contact(contact);
			}
			catch(const std::string& e)
			{
				std::cerr << e;
			}
		}
		else if (cmd.compare("EXIT") == 0)
			book.EXIT();
		else
			std::cout << "Put in a valid command\n\n";
	}
	return (0);
}