#include "Form.hpp"

Form::Form()
	: isSigned(false), GradeRequiredToSign(150), GradeRequiredToExecute(150) {};

Form::Form(std::string name, int GradeRequiredToSign, int GradeRequiredToExecute)
	: name(name), isSigned(false), GradeRequiredToSign(GradeRequiredToSign), 
		GradeRequiredToExecute(GradeRequiredToExecute)
{
	try
	{
		if (GradeRequiredToSign < 1 || GradeRequiredToExecute < 1)
			throw Form::GradeTooHighException();
		else if (GradeRequiredToSign > 150 || GradeRequiredToExecute > 150)
			throw Form::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}

Form::Form(const Form& obj)
	: name(obj.name), isSigned(obj.isSigned), GradeRequiredToSign(obj.GradeRequiredToSign), 
		GradeRequiredToExecute(obj.GradeRequiredToExecute) {};

Form::~Form() {};

Form& Form::operator=(const Form& obj)
{
	if (this != &obj)
	{
		Form::~Form();
		new(this) Form(obj);
	}
	return (*this);
}

std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const
{
	return (isSigned);
}

int Form::getGradeRequiredToSign() const
{
	return (GradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
	return (GradeRequiredToExecute);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > GradeRequiredToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}
