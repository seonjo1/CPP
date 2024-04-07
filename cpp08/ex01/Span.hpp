#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <vector>
# include <cmath>

class Span
{
private:
	std::vector<int> v;
	unsigned int maxSize;
	unsigned int sSpan;
	unsigned int lSpan;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& copy);
	~Span();
	Span& operator=(const Span& copy);

	void addNumber(int num);
	void addNumbers(int num, unsigned int length);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif
