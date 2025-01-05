/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:15:46 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 06:34:16 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

namespace
{
	const char*	GREEN = "\033[0;32m";
	const char*	RED = "\033[0;31m";
	const char*	C_RESET = "\033[0m";
}

/* Default constructor */
PresidentialPardonForm::PresidentialPardonForm():
AForm("PresidentialPardonForm", "Default target", 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm's default constructor called"
			  << C_RESET << '\n';
}

/* Constructor */
PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm's constructor called"
			  << C_RESET << '\n';
}

/* Copy constructor */
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
AForm(other)
{
	std::cout << GREEN << "PresidentialPardonForm's copy constructor called"
			  << C_RESET << '\n';
}

/* Copy assignment operator */
PresidentialPardonForm&
PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	AForm::operator=(rhs);
	return *this;
}

/* Destructor */
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm's destructor called"
			  << C_RESET << '\n';
}

void	PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
