#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>
# include <cctype>

class RPN
{
private:
	std::stack<int> st;

public:
	RPN();
	RPN(const RPN& copy);
	~RPN();
	RPN& operator=(const RPN& copy);
	void inputChar(char c);
	int getResult();
};

#endif
