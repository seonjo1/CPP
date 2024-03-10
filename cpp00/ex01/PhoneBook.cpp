#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
 : idx(0), size(0) {};

void PhoneBook::Add()
{
	std::string f_name, l_name, n_name, p_num, secret;
	std::cout << "first name : ";
	std::cin >> f_name;
	std::cout << "last name : ";
	std::cin >> l_name;
	std::cout << "nickname : ";
	std::cin >> n_name;
	std::cout << "phone number : ";
	std::cin >> p_num;
	std::cout << "darkest secret : ";
	std::cin >> secret;
	book[idx] = Contact (f_name, l_name, n_name, p_num, secret);
	idx = (idx + 1) % 8;
	if (size < 8) size++;
}

void PhoneBook::print_info(std::string info, int len)
{
	int i = 0;
	int j = 0;
	for (; len + i < 10; i++)
		std::cout << " ";
	for (; i < 9; i++)
		std::cout << info[j++];
	if (len <= 10)
		std::cout << info[j] << "|";
	else
		std::cout << "." << "|";
}

void PhoneBook::contact_info(int idx, Contact &contact)
{
	std::cout << "|        " << idx << "|";
	print_info(contact.get_first_name(), contact.get_first_name().length());
	print_info(contact.get_last_name(), contact.get_last_name().length());
	print_info(contact.get_nickname(), contact.get_nickname().length());
	std::cout << std::endl;
}

void PhoneBook::Search()
{
	std::cout << "--------------------------------------------\n";
	for (int i = 0; i < size; i++)
		contact_info(i, book[i]);
	std::cout << "--------------------------------------------\n\n";
	// int idx;
	// while (true)
	// {
	// 	std::cout << "Index : ";
	// 	std::cin >> idx;
	// 	std::cout << idx << std::endl;
	// 	if (!(idx >= 0 && idx < size))
	// 	{
	// 		std::cin.clear();
	// 		std::cout << "Please re-enter the index\n";
	// 		continue ;
	// 	}
	// 	std::cout << "first_name : " << book[idx].get_first_name() << std::endl;
	// 	std::cout << "last_name : " << book[idx].get_last_name() << std::endl;
	// 	std::cout << "nickname : " << book[idx].get_nickname() << std::endl;
	// 	std::cout << "phone_number : " << book[idx].get_phone_number() << std::endl;
	// 	std::cout << "darkest_secret : " << book[idx].get_darkest_secret() << std::endl;
	// 	break ;
	// }
}

void PhoneBook::Exit()
{

}