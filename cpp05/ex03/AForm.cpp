#include "AForm.hpp"

AForm::AForm()
	: isSigned(false), GradeRequiredToSign(150), GradeRequiredToExecute(150) {};

AForm::AForm(std::string name, std::string target, int GradeRequiredToSign, int GradeRequiredToExecute)
	: name(name), target(target), isSigned(false), GradeRequiredToSign(GradeRequiredToSign), 
		GradeRequiredToExecute(GradeRequiredToExecute)
{
	if (GradeRequiredToSign < 1 || GradeRequiredToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (GradeRequiredToSign > 150 || GradeRequiredToExecute > 150)
		throw AForm::GradeTooLowException();	
}

AForm::AForm(const AForm& obj)
	: name(obj.name), target(obj.target), isSigned(obj.isSigned), 
		GradeRequiredToSign(obj.GradeRequiredToSign), 
		GradeRequiredToExecute(obj.GradeRequiredToExecute) {};

AForm::~AForm() {};

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		return (*this);
	return (*this);
}

std::string AForm::getName() const
{
	return (name);
}

std::string AForm::getTarget() const
{
	return (target);
}

bool AForm::getIsSigned() const
{
	return (isSigned);
}

int AForm::getGradeRequiredToSign() const
{
	return (GradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
	return (GradeRequiredToExecute);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (isSigned) throw AForm::FormAlreadySignedException();
	else if (bureaucrat.getGrade() > GradeRequiredToSign) throw AForm::GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return ("form is already signed");
}

const char* AForm::FormIsNotSignedException::what() const throw()
{
	return ("form is not signed");
}

const char* AForm::FileOpenException::what() const throw()
{
	return ("fail to open file");
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	if (obj.getIsSigned())
		os << obj.getName() << " is signed and the Grade required to sign is "
			<< obj.getGradeRequiredToSign() << " and Grade required to execute is "
			<< obj.getGradeRequiredToExecute();
	else
		os << obj.getName() << " is not signed and the Grade required to sign is "
			<< obj.getGradeRequiredToSign() << " and Grade required to execute is "
			<< obj.getGradeRequiredToExecute();
	return (os);
}
