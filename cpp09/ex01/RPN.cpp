#include "RPN.hpp"

RPN::RPN() {};

RPN::~RPN() {};

RPN::RPN(const RPN& copy)
	: st(copy.st) {};

RPN& RPN::operator=(const RPN& copy)
{
	if (this != &copy)
		st = copy.st;
	return (*this);
}

void RPN::inputChar(char c)
{
	if (std::isdigit(c))
		st.push(c - '0');
	else
	{
		if (st.size() < 2) throw std::string("Error");
		int a = st.top();
		st.pop();
		int b = st.top();
		st.pop();
		switch (c)
		{
			case '+':
				st.push(b + a);
				break;
			case '-':
				st.push(b - a);
				break;
			case '*':
				st.push(b * a);
				break;
			case '/':
				if (a == 0) throw std::string("Error");
				st.push(b / a);
				break;
			default:
				throw std::string("Error");
		}
	}
}

int RPN::getResult()
{
	if (st.size() != 1) throw std::string("Error");
	return (st.top());
}
