#include "GradeTooLowException.hpp"

const char* GradeTooLowException::what() const noexcept
{
	return ("grade is less than the minimum value");
}