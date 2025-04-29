/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:14:42 by kecheong          #+#    #+#             */
/*   Updated: 2025/04/29 21:47:41 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

template<typename T>
void	println(const T& t);

template<typename T>
std::string	to_string(const T& t);

template<typename T>
void	test_orthodox_canonical_form();

template<typename T>
void	test_execute();

int	main()
{
	test_orthodox_canonical_form<ShrubberyCreationForm>();
	test_orthodox_canonical_form<RobotomyRequestForm>();
	test_orthodox_canonical_form<PresidentialPardonForm>();
	/*test_execute<ShrubberyCreationForm>();*/
	/*test_execute<RobotomyRequestForm>();*/
	/*test_execute<PresidentialPardonForm>();*/
}

template<typename T>
void	test_orthodox_canonical_form()
{
	println("--------------------");
	println("Default constructor");
	{
		T	form;
		println(form);
		CHECK(form.getTarget() == "Default target");
	}
	println("--------------------");
	println("Valid construction");
	{
		T	form("Target One");
		println(form);
		CHECK(form.getTarget() == "Target One");
	}
	println("--------------------");
	println("Copy construction");
	{
		T	form("Target Two");
		println(form);
		CHECK(form.getTarget() == "Target Two");

		T	form2(form);
		println(form2);
		CHECK(form2.getTarget() == form.getTarget());
	}
	println("--------------------");
	println("Copy assignment operator");
	{
		T	form("Target Three");
		println(form);
		CHECK(form.getTarget() == "Target Three");

		T		form2("Target Four");
		Bureaucrat	b("Temp Guy", 4);
		form2.beSigned(b);
		println(form2);
		CHECK(form2.getTarget() == "Target Four");
		CHECK(form2.getSignStatus() == true);

		form = form2;
		println(form);
		CHECK(form.getSignStatus() == form2.getSignStatus());
	}
	println("--------------------\n");
}

template<typename T>
void	test_execute()
{
	Bureaucrat	lowestGrade("Small Fry", 150);
	Bureaucrat	averageGrade("Middle Guy", 75);
	Bureaucrat	highestGrade("Big Guy", 1);
	T			form("SomeTargetName");
	Bureaucrat	justEnoughGradeToSign("Just Signing", form.getGradeRequiredToSign());
	Bureaucrat	justEnoughGradeToExecute("Just Executing", form.getGradeRequiredToExecute());

	CHECK(form.getTarget() == "SomeTargetName");
	CHECK(justEnoughGradeToSign.getGrade() ==  form.getGradeRequiredToSign());
	CHECK(justEnoughGradeToExecute.getGrade() ==  form.getGradeRequiredToExecute());

	lowestGrade.executeForm(form);
	averageGrade.executeForm(form);
	highestGrade.executeForm(form);

	println("--------------------");

	lowestGrade.signForm(form);
	averageGrade.signForm(form);
	highestGrade.signForm(form);
	justEnoughGradeToSign.signForm(form);
	CHECK(form.getSignStatus() == true);

	println("--------------------");

	lowestGrade.executeForm(form);
	averageGrade.executeForm(form);
	highestGrade.executeForm(form);
	justEnoughGradeToExecute.executeForm(form);

	println("--------------------\n");
}

template<typename T>
void	println(const T& t)
{
	std::cout << t << '\n';
}

template<typename T>
std::string	to_string(const T& t)
{
	std::stringstream	ss;
	ss << t;
	return ss.str();
}
