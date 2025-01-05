/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 05:10:21 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 05:17:06 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() { }

Intern::Intern(const Intern&) { }

Intern&	Intern::operator=(const Intern&)
{
	return *this;
}

Intern::~Intern() { }

namespace
{
	const int	TYPES_OF_FORMS = 3;
}

AForm*	Intern::makeShrubberyCreationForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}	

AForm*	Intern::makeRobotomyRequestForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}	

AForm*	Intern::makePresidentialPardonForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& formName,
						 const std::string& targetName)
{
	const std::string	formNames[TYPES_OF_FORMS] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm*	(*formMakers[TYPES_OF_FORMS])(const std::string&) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
	};

	for (int i = 0; i < TYPES_OF_FORMS; ++i)
	{
		if (formName == formNames[i])
		{
			AForm*	createdForm = formMakers[i](targetName);
			std::cout << "Intern creates " << createdForm->getName() << '\n';
			return createdForm;
		}
	}
	std::cout << "Cannot find form of " << formName
			  << " for target " << targetName << '\n';
	return 0;
}
