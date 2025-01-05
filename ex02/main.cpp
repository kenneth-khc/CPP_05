/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:14:42 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 04:52:01 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

template<typename T>
void	test_orthodox_canonical_form()
{
	println("--------------------");
	println("Default constructor");
	{
		T	form;
		println(form);
	}
	println("--------------------");
	println("Valid construction");
	{
		T	form("Target One");
		println(form);
	}
	println("--------------------");
	println("Copy construction");
	{
		T	form("Target Two");
		println(form);

		T	form2(form);
		println(form2);
	}
	println("--------------------");
	println("Copy assignment operator");
	{
		T	form("Target Three");
		println(form);

		T		form2("Target Four");
		Bureaucrat	b("Temp Guy", 4);
		form2.beSigned(b);
		println(form2);

		form = form2;
		println(form);
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

	lowestGrade.executeForm(form);
	averageGrade.executeForm(form);
	highestGrade.executeForm(form);
	println("--------------------");
	lowestGrade.signForm(form);
	averageGrade.signForm(form);
	highestGrade.signForm(form);
	justEnoughGradeToSign.signForm(form);
	println("--------------------");
	lowestGrade.executeForm(form);
	averageGrade.executeForm(form);
	highestGrade.executeForm(form);
	justEnoughGradeToExecute.executeForm(form);
	println("--------------------\n");
}

int	main()
{
	test_orthodox_canonical_form<ShrubberyCreationForm>();
	test_orthodox_canonical_form<RobotomyRequestForm>();
	test_orthodox_canonical_form<PresidentialPardonForm>();
	//test_execute<ShrubberyCreationForm>();
	//test_execute<RobotomyRequestForm>();
	//test_execute<PresidentialPardonForm>();
}
