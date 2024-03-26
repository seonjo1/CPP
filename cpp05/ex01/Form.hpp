#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int GradeRequiredToSign;
	const int GradeRequiredToExecute;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

public:
	Form();
	Form(std::string name, int GradeRequiredToSign, int GradeRequiredToExecute);
	Form(const Form& obj);
	~Form();
	Form&	operator=(const Form& obj);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	bool beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif

#include "Form.hpp"

Form::Form()
	: isSigned(false), GradeRequiredToSign(150), GradeRequiredToExecute(150) {};

Form::Form(std::string name, int GradeRequiredToSign, int GradeRequiredToExecute)
	: name(name), isSigned(isSigned)
{
	try
	{
		if (GradeRequiredToSign < 1 || GradeRequiredToExecute < 1)
			throw Form::GradeTooHighException();
		else if (GradeRequiredToSign > 150 || GradeRequiredToExecute > 150)
			throw Form::GradeTooLowException();
		this->GradeRequiredToSign = GradeRequiredToSign;
		this->GradeRequiredToExecute = GradeRequiredToExecute;
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
	return (*this)
}

std::string Form::getName() const
{
	return (name);
}

bool Form::getIsSigned() const;
{
	return (IsSigned);
}

int Form::getGradeRequiredToSign() const;
{
	return (GradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const;
{
	return (GradeRequiredToExecute);
}

bool beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > GradeRequiredToSign)
		throw Form::GradeTooLowException();
	IsSigned = true;
	return (true);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

