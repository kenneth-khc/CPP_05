/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:15:21 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/05 19:27:35 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

namespace
{
	const char*	GREEN = "\033[0;32m";
	const char*	RED = "\033[0;31m";
	const char*	C_RESET = "\033[0m";
}

/* Default constructor */
Form::Form():
name("Default form"),
isSigned(false),
gradeRequiredToSign(150),
gradeRequiredToExecute(1)
{
	std::cout << GREEN << "Form's default constructor called" << C_RESET << '\n';
}

/* Constructor */
Form::Form(const std::string& name,
unsigned int signGrade, unsigned int execGrade):
name(name),
isSigned(false),
gradeRequiredToSign(signGrade),
gradeRequiredToExecute(execGrade)
{
	std::cout << GREEN << "Form's constructor called" << C_RESET << '\n';

	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
	{
		throw Form::GradeTooHighException(*this);
	}
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
	{
		throw Form::GradeTooLowException(*this);
	}
}

/* Copy constructor */
Form::Form(const Form& other):
name(other.name),
isSigned(other.isSigned),
gradeRequiredToSign(other.gradeRequiredToSign),
gradeRequiredToExecute(other.gradeRequiredToExecute)
{
	std::cout << GREEN << "Form's copy constructor called" << C_RESET << '\n';
}

/* Copy assignment operator */
Form&	Form::operator=(const Form& rhs)
{
	isSigned = rhs.isSigned;
	// can't assign to const members
	// name = rhs.name;
	// grade_required_to_sign = rhs.grade_required_to_sign;
	// grade_required_to_execute = rhs.grade_required_to_execute;
	return *this;
}

/* Destructor */
Form::~Form()
{
	std::cout << RED << "Form's destructor called" << C_RESET << '\n';
}

const std::string&	Form::getName() const
{
	return name;
}

bool	Form::getSignStatus() const
{
	return isSigned;
}

unsigned int	Form::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

unsigned int	Form::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	std::cout << "Form at " << &form << " | "
			  << "name: " << form.getName() << " | "
			  << "isSigned: " << (form.getSignStatus() ? "true" : "false") << " | "
			  << "signGrade: " << form.getGradeRequiredToSign() << " | "
			  << "execGrade: " << form.getGradeRequiredToExecute() << " | ";
	return os;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeRequiredToSign)
	{
		isSigned = true;
	}
	else
	{
		throw GradeTooLowException(*this, bureaucrat);
	}
}

Form::
GradeException::
GradeException(unsigned int signGrade,
			   unsigned int execGrade,
			   const std::string& high_or_low)
{
	std::stringstream	ss;
	ss << "Creating Form with too " << high_or_low << " a grade. "
	   << "Expected range: 1 (highest) - 150 (lowest), "
	   << "got signGrade " << signGrade << " "
	   << "and execGrade " << execGrade << " instead.";
	message = ss.str();
}

const char*	Form::GradeException::what() const throw()
{
	return message.c_str();
}

Form::GradeException::~GradeException() throw() { }

Form::
GradeTooLowException::
GradeTooLowException(const Form& form):
GradeException(form.gradeRequiredToSign, form.gradeRequiredToExecute, "low")
{ }

Form::
GradeTooHighException::
GradeTooHighException(const Form& form):
GradeException(form.gradeRequiredToSign, form.gradeRequiredToExecute, "high")
{ }

Form::
GradeException::
GradeException(unsigned int requiredGrade, unsigned int grade)
{
	std::stringstream	ss;
	ss << "trying to sign Form of required grade " << requiredGrade
	   << " with Bureaucrat of grade " << grade;
	message = ss.str();
}

Form::
GradeTooLowException::
GradeTooLowException(const Form& form, const Bureaucrat& bureaucrat):
GradeException(form.gradeRequiredToSign, bureaucrat.getGrade())
{ }
