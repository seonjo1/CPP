#include "Contact.hpp"

Contact::Contact() {;}

Contact::Contact(std::string f_name, std::string l_name, std::string n_name, std::string p_num, std::string secret)
	: first_name(f_name), last_name(l_name), nickname(n_name), phone_number(p_num), darkest_secret(secret) {};


std::string Contact::get_first_name() const { return (this->first_name); }

std::string Contact::get_last_name() const { return (this->last_name); }

std::string Contact::get_nickname() const {	return (this->nickname); }

std::string Contact::get_phone_number() const { return (this->phone_number); }

std::string Contact::get_darkest_secret() const { return (this->darkest_secret); }
