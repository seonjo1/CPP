#include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	int	f_size;
	int	l_size;
	int	n_size;
	int	p_size;
	int	s_size;

public:
	Contact();
	Contact(std::string f_name, std::string l_name, std::string n_name, std::string p_num, std::string secret);
	~Contact();
	Contact(const Contact &copy);
	Contact &operator= (const Contact &copy);
	std::string& get_first_name();
	std::string& get_last_name();
	std::string& get_nick_name();
	std::string& get_phone_number();
	std::string& get_darkest_secret();
	int get_f_size();
	int get_l_size();
	int get_n_size();
	int get_p_size();
	int get_s_size();
};
