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
	class FormAlreadySignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
public:
	Form();
	Form(std::string name, int GradeRequiredToSign, int GradeRequiredToExecute);
	Form(const Form& obj);
	~Form();
	Form& operator=(const Form& obj);
	std::string getName() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	void beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif
