#include "Contact.hpp"

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string p_num, std::string secret)
	: first_name(f_name), last_name(l_name), nickname(n_name), phone_number(p_num), darkest_secret(secret)
{
	f_size = f_name.size();
	l_size = l_name.size();
	n_size = n_name.size();
	p_size = p_num.size();
	s_size = secret.size();
}