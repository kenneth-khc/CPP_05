/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 18:22:56 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 04:43:45 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class	Bureaucrat
{
public:
	Bureaucrat(); // default constructor
	Bureaucrat(const std::string&, unsigned int); // constructor
	Bureaucrat(const Bureaucrat&); // copy constructor
	Bureaucrat& operator=(const Bureaucrat&); // copy assignment operator
	~Bureaucrat(); // destructor
	
	const std::string&	getName() const;
	const unsigned int&	getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
	void				signForm(class AForm&);
	void				executeForm(const AForm&);

	class	GradeException: public std::exception
	{
	public:
		GradeException(unsigned int, const std::string&);
		virtual ~GradeException() throw();
		virtual const char*	what() const throw();
	private:
		const unsigned int	invalidGrade;
		std::string			message;
	};

	class	GradeTooHighException: public GradeException
	{
	public:
		GradeTooHighException(unsigned int);
	};

	class	GradeTooLowException: public GradeException
	{
	public:
		GradeTooLowException(unsigned int);
	};

private:
	const std::string	name;
	unsigned int		grade;
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);

#endif
