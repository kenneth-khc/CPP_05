#include <iostream>
#include <string>
#include <sstream>
#include "Bureaucrat.hpp"

/* Default constructor */
Bureaucrat::Bureaucrat():
name("Default Bureaucrat"),
grade(150)
{
	std::cout << "Bureaucrat's default constructor called\n";
}

/* Constructor */
Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade):
name(name),
grade(grade)
{
	std::cout << "Bureaucrat's constructor called\n";
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
	std::cout << "Bureaucrat's copy constructor called\n";
}

/* Copy assignment operator */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->grade = other.grade;
	}
	return *this;
}

/* Destructor */
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat's destructor called\n";
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

Bureaucrat::
GradeException::
~GradeException() throw() { }

const char*	Bureaucrat::GradeException::what() const throw()
{
	return message.c_str();
}

Bureaucrat::
GradeTooHighException::
GradeTooHighException(unsigned int input_grade):
GradeException(input_grade, "high") { }

Bureaucrat::
GradeTooLowException::
GradeTooLowException(unsigned int input_grade):
GradeException(input_grade, "low") { }

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& B)
{
	std::cout << B.getName() << ", bureaucrat grade " << B.getGrade();
	return os;
}
