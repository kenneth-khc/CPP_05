#include <iostream>
#include <string>
#include <sstream>
#include "Bureaucrat.hpp"

const char*	GREEN = "\033[0;32m";
const char*	RED = "\033[0;31m";
const char*	YELLOW = "\033[0;33m";
const char*	C_RESET = "\033[0m";

/* Default constructor */
Bureaucrat::Bureaucrat():
name("Default Bureaucrat"),
grade(150)
{
	std::cout << GREEN << "Bureaucrat's default constructor called"
			  << C_RESET << '\n';
}

/* Constructor */
Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade):
name(name),
grade(grade)
{
	std::cout << GREEN << "Bureaucrat's constructor called"
			  << C_RESET << '\n';
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException(grade);
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException(grade);
	}
}

/* Copy constructor */
Bureaucrat::Bureaucrat(const Bureaucrat& other):
name(other.name),
grade(other.grade)
{
	std::cout << GREEN << "Bureaucrat's copy constructor called"
			  << C_RESET << '\n';
}

/* Copy assignment operator */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		//this->name = other.name; // can't assign to a const
		this->grade = other.grade;
	}
	return *this;
}

/* Destructor */
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat's destructor called"
			  << C_RESET << '\n';
}

const std::string&	Bureaucrat::getName() const
{
	return name;
}

const unsigned int&	Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade()
{
	if (--grade < 1)
	{
		throw Bureaucrat::GradeTooHighException(grade);
	}
}

void	Bureaucrat::decrementGrade()
{
	if (++grade > 150)
	{
		throw Bureaucrat::GradeTooLowException(grade);
	}
}

/* GradeException constructor */
Bureaucrat::
GradeException::
GradeException(unsigned int grade, const std::string& high_or_low):
invalid_grade(grade)
{
	std::stringstream	ss;
	ss << "Grade " << invalid_grade << " is too " << high_or_low
	   << ". Expected range: 1 (highest) - 150 (lowest)";
	message = ss.str();
}

/* GradeException destructor */
Bureaucrat::
GradeException::
~GradeException() throw() { }

const char*	Bureaucrat::GradeException::what() const throw()
{
	return message.c_str();
}

/* GradeTooHighException constructor */
Bureaucrat::
GradeTooHighException::
GradeTooHighException(unsigned int input_grade):
GradeException(input_grade, "high") { }

/* GradeTooLowException constructor */
Bureaucrat::
GradeTooLowException::
GradeTooLowException(unsigned int input_grade):
GradeException(input_grade, "low") { }

/* Overload << to print Bureaucrat's status */
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& B)
{
	std::cout << B.getName() << ", bureaucrat grade " << B.getGrade();
	return os;
}
