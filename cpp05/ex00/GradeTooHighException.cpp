#include "GradeTooHighException.hpp"

const char* GradeTooHighException::what() const noexcept
{
	return ("grade is greater than the maximum value");
}