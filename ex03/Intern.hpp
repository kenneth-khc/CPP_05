/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:07:30 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 06:51:51 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class	Intern
{
public:
	Intern(); // default constructor
	Intern(const Intern&); // copy constructor
	Intern&	operator=(const Intern&); // copy assignment operator
	~Intern(); // destructor
		 
	AForm*	makeForm(const std::string&, const std::string&);

private:
	static AForm*	makeShrubberyCreationForm(const std::string&);
	static AForm*	makeRobotomyRequestForm(const std::string&);
	static AForm*	makePresidentialPardonForm(const std::string&);
};

#endif
