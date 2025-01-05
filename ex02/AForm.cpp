/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:15:21 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 04:51:22 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

namespace
{
	const char*	GREEN = "\033[0;32m";
	const char*	RED = "\033[0;31m";
	const char*	C_RESET = "\033[0m";
}

/* Default constructor */
AForm::AForm():
name("Default form"),
target("Default target"),
isSigned(false),
gradeRequiredToSign(150),
gradeRequiredToExecute(1)
{
	std::cout << GREEN << "AForm's default constructor called" << C_RESET << '\n';
}

/* Constructor */
AForm::AForm(const std::string& name, const std::string& target,
unsigned int signGrade, unsigned int execGrade):
name(name),
target(target),
isSigned(false),
gradeRequiredToSign(signGrade),
gradeRequiredToExecute(execGrade)
{
	std::cout << GREEN << "AForm's constructor called" << C_RESET << '\n';
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
	{
		throw AForm::GradeTooHighException(*this);
	}
	else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
	{
		throw AForm::GradeTooLowException(*this);
	}
}

/* Copy constructor */
AForm::AForm(const AForm& other):
name(other.name),
target(other.target),
isSigned(other.isSigned),
gradeRequiredToSign(other.gradeRequiredToSign),
gradeRequiredToExecute(other.gradeRequiredToExecute)
{
	std::cout << GREEN << "AForm's copy constructor called" << C_RESET << '\n';
}

/* Copy assignment operator */
AForm&	AForm::operator=(const AForm& rhs)
{
	isSigned = rhs.isSigned;
	// can't assign to const members
	// name = rhs.name;
	// grade_required_to_sign = rhs.grade_required_to_sign;
	// grade_required_to_execute = rhs.grade_required_to_execute;
	return *this;
}

/* Destructor */
AForm::~AForm()
{
	std::cout << RED << "AForm's destructor called" << C_RESET << '\n';
}

const std::string&	AForm::getName() const
{
	return name;
}

bool	AForm::getSignStatus() const
{
	return isSigned;
}

unsigned int	AForm::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

unsigned int	AForm::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}

const std::string&	AForm::getTarget() const
{
	return target;
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	std::cout << "Form at " << &form << " | "
			  << "name: " << form.getName() << " | "
			  << "target: " << form.getTarget() << " | "
			  << "isSigned: " << (form.getSignStatus() ? "true" : "false") << " | "
			  << "signGrade: " << form.getGradeRequiredToSign() << " | "
			  << "execGrade: " << form.getGradeRequiredToExecute() << " | ";
	return os;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeRequiredToSign)
	{
		isSigned = true;
	}
	else
	{
		throw GradeTooLowException("sign",
								   gradeRequiredToSign,
								   bureaucrat.getGrade());
	}
}

AForm::
FormException::
FormException(const std::string& msg):
message(msg) { }

AForm::
FormException::
FormException(unsigned int signGrade,
			   unsigned int execGrade,
			   const std::string& high_or_low)
{
	std::stringstream	ss;
	ss << "Creating AForm with too " << high_or_low << " a grade. "
	   << "Expected range: 1 (highest) - 150 (lowest), "
	   << "got signGrade " << signGrade << " "
	   << "and execGrade " << execGrade << " instead.";
	message = ss.str();
}

const char*	AForm::FormException::what() const throw()
{
	return message.c_str();
}

AForm::FormException::~FormException() throw() { }

AForm::
GradeTooLowException::
GradeTooLowException(const AForm& form):
FormException(form.gradeRequiredToSign, form.gradeRequiredToExecute, "low")
{ }

AForm::
GradeTooHighException::
GradeTooHighException(const AForm& form):
FormException(form.gradeRequiredToSign, form.gradeRequiredToExecute, "high")
{ }

AForm::
FormException::
FormException(const std::string& bureaucratAction,
			   unsigned int requiredGrade,
			   unsigned int bureaucratGrade)
{
	std::stringstream	ss;
	ss << "trying to " << bureaucratAction
	   << " AForm of required grade " << requiredGrade
	   << " with Bureaucrat of grade " << bureaucratGrade;
	message = ss.str();
}

AForm::
GradeTooLowException::
GradeTooLowException(const std::string& bureaucratAction,
					 unsigned int requiredGrade,
					 unsigned int bureaucratGrade):
FormException(bureaucratAction, requiredGrade, bureaucratGrade)
{ }

AForm::
FormNotSignedException::
FormNotSignedException():
FormException("Form is not signed") { }

void	AForm::execute(const Bureaucrat& executor) const
{
	bool	is_signed = getSignStatus();

	if (is_signed == false)
	{
		throw FormNotSignedException();
	}
	else if (executor.getGrade() > gradeRequiredToExecute)
	{
		throw GradeTooLowException("execute",
								   gradeRequiredToExecute,
								   executor.getGrade());
	}
	action();
}

