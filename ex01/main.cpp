/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:14:42 by kecheong          #+#    #+#             */
/*   Updated: 2025/04/29 18:28:58 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

#define COUNT_OF(array) (sizeof((array)) / sizeof((array[0])))

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0;0m"

void	test_orthodox_canonical_form();
void	test_invalid_form_construction();
void	test_sign_form();

template<typename T>
void	println(const T& t);

template<typename T>
std::string	to_string(const T& t);

int	main()
{
	void	(*test_cases[])() = {
		test_orthodox_canonical_form,
		test_invalid_form_construction,
		test_sign_form
	};
	for (size_t i = 0; i < COUNT_OF(test_cases); ++i)
	{
		test_cases[i]();
	}
}

void	test_orthodox_canonical_form()
{
	println("Default constructor");
	{
		Form	f;
		println(f);
		CHECK(f.getName() == "Default form");
		CHECK(f.getSignStatus() == false);
		CHECK(f.getGradeRequiredToSign() == 150);
		CHECK(f.getGradeRequiredToExecute() == 1);
	}
	println("--------------------");
	println("Valid construction");
	{
		Form	f("Form Number One", 50, 50);
		println(f);
		CHECK(f.getName() == "Form Number One");
		CHECK(f.getSignStatus() == false);
		CHECK(f.getGradeRequiredToSign() == 50);
		CHECK(f.getGradeRequiredToExecute() == 50);
	}
	println("--------------------");
	println("Copy construction");
	{
		Form	f("Form Number Two", 42, 1);
		Form	ff(f);
		println(f);
		println(ff);
		CHECK(f.getName() == ff.getName());
		CHECK(f.getSignStatus() == ff.getSignStatus());
		CHECK(f.getGradeRequiredToSign() == ff.getGradeRequiredToSign());
		CHECK(f.getGradeRequiredToExecute() == ff.getGradeRequiredToExecute());
	}
	println("--------------------");
	println("Copy assignment operator");
	{
		Form	f("Form Number Three", 149, 149);
		Form	ff("Form Number Four", 4, 4);
		f = ff;
		println(f);
		println(ff);
		CHECK(f.getName() != ff.getName());
		CHECK(f.getSignStatus() == ff.getSignStatus());
		CHECK(f.getGradeRequiredToSign() != ff.getGradeRequiredToSign());
		CHECK(f.getGradeRequiredToExecute() != ff.getGradeRequiredToExecute());
		ff.beSigned(Bureaucrat("tmp", 4));
		println("Assigning ff to f after signing ff...");
		f = ff;
		println(f);
		CHECK(f.getSignStatus() == ff.getSignStatus());
	}
	println("--------------------");
}

void	test_invalid_form_construction()
{
	println("Test form grade too high");
	{
		try
		{
			Form	f("Invalid High Grade Form", 0, 0);
		}
		catch (Form::GradeException& e)
		{
			std::cout << "Caught exception: ";
			println(e.what());
		}
	}
	println("--------------------");
	println("Test form grade too low");
	{
		try
		{
			Form	f("Invalid Low Grade Form", 151, 151);
		}
		catch (Form::GradeException& e)
		{
			std::cout << "Caught exception: ";
			println(e.what());
		}
		try
		{
			Form	ff("Second Invalid Low Grade Form", -1, -1);
		}
		catch (Form::GradeException& e)
		{
			std::cout << "Caught exception: ";
			println(e.what());
		}
	}
	println("--------------------");
}

void	test_sign_form()
{
	Bureaucrat	Bob("Bob", 42);
	Form		highGradeForm("High Grade Form Not For Bob", 5, 5);
	Form		lowGradeForm("Low Grade Form For Bob", 50, 50);

	Bob.signForm(highGradeForm);
	CHECK(highGradeForm.getSignStatus() == false);

	Bob.signForm(lowGradeForm);
	CHECK(lowGradeForm.getSignStatus() == true);
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
