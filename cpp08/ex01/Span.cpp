#include "Span.hpp"

Span::Span()
	: maxSize(0), sSpan(0), lSpan(0) {};

Span::Span(unsigned int n)
	: maxSize(n), sSpan(0), lSpan(0)  {};

Span::Span(const Span& copy)
	: v(copy.v), maxSize(copy.maxSize), sSpan(copy.sSpan), lSpan(copy.lSpan)  {};

Span::~Span() {};

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		v = copy.v;
		maxSize = copy.maxSize;
		sSpan = copy.sSpan;
		lSpan = copy.lSpan;
	}
	return (*this);
}

void Span::addNumber(int num)
{
	unsigned int size = v.size();
	if (size == maxSize) throw std::out_of_range("Vector is already full");
	else if (size > 1)
	{
		unsigned int span;
		unsigned int uNum = static_cast<unsigned int>(num);
		unsigned int lastNum = static_cast<unsigned int>(v.back());
		
		if (uNum > lastNum)
			span = uNum - lastNum;
		else
			span = lastNum - uNum;
		
		if (size == 2)
		{
			sSpan = span;
			lSpan = span;
		}
		else
		{
			sSpan = std::min(sSpan, span);
			lSpan = std::max(lSpan, span);
		}
	}
	v.push_back(num);
}

unsigned int Span::shortestSpan()
{
	if (v.size() < 2) throw std::invalid_argument("Vector has too few elements");
	return (sSpan);
}

unsigned int Span::longestSpan()
{
	if (v.size() < 2) throw std::invalid_argument("Vector has too few elements");
	return (lSpan);
}

void Span::addNumbers(int num, unsigned int length)
{
	if (length == 0) throw std::invalid_argument("length argument is too small");
	else if (length > maxSize - v.size()) throw std::invalid_argument("length argument is large");
	addNumber(num);
	length--;
	if (length != 0)
	{
		sSpan = 0;
		if (v.size() == 1)
			lSpan = 0;
		v.insert(v.end(), length, num);
	}
}
