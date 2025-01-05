/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:21:15 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 02:15:41 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

namespace
{
	const char*	GREEN = "\033[0;32m";
	const char*	RED = "\033[0;31m";
	const char*	C_RESET = "\033[0m";
}

/* Default constructor */
RobotomyRequestForm::RobotomyRequestForm():
AForm("RobotomyRequestForm", "Default target", 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm's default constructor called"
			  << C_RESET << '\n';
}

/* Constructor */
RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
AForm("RobotomyRequestForm", target, 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm's constructor called"
			  << C_RESET << '\n';
}

/* Copy constructor */
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
AForm(other)
{
	std::cout << GREEN << "RobotomyRequestForm's copy constructor called"
			  << C_RESET << '\n';
}

/* Copy assignment operator */
RobotomyRequestForm&
RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << GREEN << "RobotomyRequestForm's copy assignment operator called"
			  << C_RESET << '\n';
	AForm::operator=(rhs);
	return *this;
}

/* Destructor */
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm's destructor called"
			  << C_RESET << '\n';
}

void	RobotomyRequestForm::action() const
{
	static bool	seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}
	std::cout << "* insert drilling noises here *\n";

	int	fiftyFifty = std::rand() % 2;
	if (fiftyFifty == 0)
	{
		std::cout << getTarget() << " has been robotomized successfully.\n";
	}
	else
	{
		std::cout << getTarget() << "'s robotomy has failed.\n";
	}
}
