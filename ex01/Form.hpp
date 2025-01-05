/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:13:29 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/05 19:32:00 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	Form
{
public:
	Form(); // default constructor
	Form(const std::string&, unsigned int, unsigned int); // constructor
	Form(const Form&); // copy constructor
	Form&	operator=(const Form&); // copy assignment operator
	~Form(); // destructor

	/* Getters */
	const std::string&	getName() const;
	bool				getSignStatus() const;
	unsigned int		getGradeRequiredToSign() const;
	unsigned int		getGradeRequiredToExecute() const;

	void	beSigned(const Bureaucrat&);

	class	GradeException: public std::exception
	{
	public:
		GradeException(unsigned int, unsigned int);
		GradeException(unsigned int, unsigned int, const std::string&);
		virtual ~GradeException() throw();
		virtual const char*	what() const throw();
	private:
		std::string			message;
	};

	class	GradeTooHighException: public GradeException
	{
	public:
		GradeTooHighException(const Form&);
	};

	class	GradeTooLowException: public GradeException
	{
	public:
		GradeTooLowException(const Form&, const Bureaucrat&);
		GradeTooLowException(const Form&);
	};

private:
	const std::string	name;
	bool				isSigned;
	const unsigned int	gradeRequiredToSign;
	const unsigned int	gradeRequiredToExecute;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
