#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "GradeTooHighException.hpp"
# include "GradeTooLowException.hpp"

class Bureaucrat
{
private:
	const std::string name;
	int	grade;
	static const GradeTooHighException high;
	static const GradeTooLowException low;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& obj);
	std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

#endif

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: grade(75) {};

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name)
{
	try
	{
		if (grade < 1) throw GradeTooHighException;
		else if (grade > 150) throw GradeTooLowException;
		this->grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
	: name(obj.name), grade(obj.grade) {};

Bureaucrat::~Bureaucrat() {};

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		name = obj.name;
		grade = obj.grade;
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
		if (grade == 1) throw Bureaucrat::high;
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
		if (grade == 150) throw Bureaucrat::low;
		grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

std::ostream&
