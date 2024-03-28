#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string name;
	std::string target;
	bool isSigned;
	const int GradeRequiredToSign;
	const int GradeRequiredToExecute;

protected:
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
	class FormIsNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class FileOpenException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

public:
	AForm();
	AForm(std::string name = "", std::string target = "", 
		int GradeRequiredToSign, int GradeRequiredToExecute);
	AForm(const AForm& obj);
	virtual ~AForm();
	AForm&	operator=(const AForm& obj);

	std::string getName() const;
	std::string getTarget() const;
	bool getIsSigned() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	void beSigned(Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat cosnt & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
