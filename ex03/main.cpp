/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:14:42 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 06:51:42 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>

#define CHECK(condition)												\
{																		\
	if (!(condition))													\
	{																	\
		std::cerr << __FUNCTION__ << ":" << __LINE__ << ": "			\
				  << RED << "ERROR:" << RESET							\
				  << " \"" << #condition << '"' << " failed\n";			\
		exit(1);														\
	}																	\
	else																\
	{																	\
		std::cout << __FUNCTION__ << ":" << __LINE__ << ": "			\
				  << GREEN << "OK" << RESET << '\n';					\
	}																	\
}

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0;0m"

int	main()
{
	Bureaucrat	bigShot("Big Shot", 1);
	Intern		someRandomIntern;
	AForm*		form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	CHECK(form->getName() == "RobotomyRequestForm");
	CHECK(form->getTarget() == "Bender");
	CHECK(form->getSignStatus() == false);
	bigShot.signForm(*form);
	bigShot.executeForm(*form);
	delete form;

	std::cout << "-------------------------------------------------" << '\n';

	form = someRandomIntern.makeForm("shrubbery creation", "Tender");
	CHECK(form->getName() == "ShrubberyCreationForm");
	CHECK(form->getTarget() == "Tender");
	CHECK(form->getSignStatus() == false);
	bigShot.signForm(*form);
	bigShot.executeForm(*form);
	delete form;

	std::cout << "-------------------------------------------------" << '\n';

	form = someRandomIntern.makeForm("presidential pardon", "Ender");
	CHECK(form->getName() == "PresidentialPardonForm");
	CHECK(form->getTarget() == "Ender");
	CHECK(form->getSignStatus() == false);
	bigShot.signForm(*form);
	bigShot.executeForm(*form);
	delete form;

	std::cout << "-------------------------------------------------" << '\n';

	form = someRandomIntern.makeForm("some non-existent form", "bla bla bla");
	CHECK(form == NULL);
}
