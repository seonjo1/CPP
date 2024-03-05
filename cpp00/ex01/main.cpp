#include "PhoneBook.hpp"

int main()
{
	PhoneBook book;
	for (int i = 0; i < 8; i++)
	{
		book.Add();
		book.Search();
	}
}