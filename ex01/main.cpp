/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:14:42 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/05 19:34:32 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void	test_orthodox_canonical_form()
{
	println("--------------------");
	println("Default constructor");
	{
		Form	f;
		println(f);
	}
	println("--------------------");
	println("Valid construction");
	{
		Form	f("Form Number One", 50, 50);
		println(f);
	}
	println("--------------------");
	println("Copy construction");
	{
		Form	f("Form Number Two", 42, 1);
		println(f);

		Form	ff(f);
		println(ff);

	}
	println("--------------------");
	println("Copy assignment operator");
	{
		Form	f("Form Number Three", 149, 149);
		println(f);

		Form		ff("Form Number Four", 4, 4);
		Bureaucrat	b("Temp Guy", 4);
		ff.beSigned(b);
		println(ff);

		f = ff;
		println(f);
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
	Bob.signForm(lowGradeForm);
}

int	main()
{
	test_orthodox_canonical_form();
	//test_invalid_form_construction();
	//test_sign_form();
}
