#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
	: grade(150) {};

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name), grade(grade)
{
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	else if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
	: name(obj.name), grade(obj.grade) {};

Bureaucrat::~Bureaucrat() {};

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		Bureaucrat::~Bureaucrat();
		new(this) Bureaucrat(obj);
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (grade == 1) throw Bureaucrat::GradeTooHighException();
		grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (grade == 150) throw Bureaucrat::GradeTooLowException();
		grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << name << " couldn't sign " << form.getName() << " because " 
			<< e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}
