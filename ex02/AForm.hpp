/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:13:29 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 02:02:41 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class	AForm
{
public:
	AForm(); // default constructor
	/*AForm(const std::string&, unsigned int, unsigned int); // constructor*/
	AForm(const std::string&, const std::string&, unsigned int, unsigned int);
	AForm(const AForm&); // copy constructor
	AForm&	operator=(const AForm&); // copy assignment operator
	~AForm(); // destructor

	/* Getters */
	const std::string&	getName() const;
	bool				getSignStatus() const;
	unsigned int		getGradeRequiredToSign() const;
	unsigned int		getGradeRequiredToExecute() const;
	const std::string&	getTarget() const;

	void				beSigned(const Bureaucrat&);
	void				execute(const Bureaucrat&) const;
	virtual void		action() const = 0;

	class	FormException: public std::exception
	{
	public:
		FormException(const std::string&);
		FormException(const std::string&, unsigned int, unsigned int);
		FormException(unsigned int, unsigned int, const std::string&);
		virtual ~FormException() throw();
		virtual const char*	what() const throw();
	private:
		std::string			message;
	};

	class	GradeTooHighException: public FormException
	{
	public:
		GradeTooHighException(const AForm&);
	};

	class	GradeTooLowException: public FormException
	{
	public:
		GradeTooLowException(const std::string&, unsigned int, unsigned int); 
		GradeTooLowException(const AForm&);
	};

	class	FormNotSignedException: public FormException 
	{
	public:
		FormNotSignedException();
	};

private:
	const std::string	name;
	const std::string	target;
	bool				isSigned;
	const unsigned int	gradeRequiredToSign;
	const unsigned int	gradeRequiredToExecute;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
