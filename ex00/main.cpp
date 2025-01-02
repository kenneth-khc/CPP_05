/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:14:42 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/03 04:26:06 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

template<typename T>
void	println(const T t)
{
	std::cout << t << '\n';
}

template<typename T>
std::string	to_string(const T t)
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
		Bureaucrat	b;

		println(b);
	}
	println("--------------------");
	println("Valid construction");
	{
		Bureaucrat	b("Bob", 42);

		println(b);
	}
	println("--------------------");
	println("Copy construction");
	{
		Bureaucrat	b("Bobby", 99);
		Bureaucrat	bb(b);

		println(b.getName() + " = " + bb.getName());
		println(to_string(b.getGrade()) + " = " + to_string(bb.getGrade()));
	}
	println("--------------------");
	println("Copy assignment operator");
	{
		Bureaucrat	not_bob;
		Bureaucrat	b("Bob", 4);

		println(not_bob.getName() + " != " + b.getName());
		println(to_string(not_bob.getGrade()) + " != " +
				to_string(b.getGrade()));
		not_bob = b;
		println("Assigning... ");
		println(not_bob.getName() + " == " + b.getName());
		println(to_string(not_bob.getGrade()) + " == " +
				to_string(b.getGrade()));
	}
	println("--------------------");
}

void	test_grade_too_low()
{
	println("Catch grade too low");
	{
		try
		{
			Bureaucrat	b("Not Gonna Be Bob", 151);
		}
		catch (Bureaucrat::GradeException& e)
		{
			println(std::string("Caught exception: ") + e.what());
		}
	}
	println("--------------------");
	println("Don't catch grade too low");
	{
		Bureaucrat	b("Not Gonna Be Bob", 151);
	}
	println("function is exited. this doesn't run");
	println("--------------------");
}

void	test_grade_too_high()
{
	println("Catch grade too high");
	{
		try
		{
			Bureaucrat	b("Not Gonna Be Bobbing", 0);
		}
		catch (Bureaucrat::GradeException& e)
		{
			println(std::string("Caught exception: ") + e.what());
		}
	}
	println("--------------------");
	println("Don't catch grade too high");
	{
		Bureaucrat	b("Not Gonna Be Bobbing", 0);
	}
	println("function is exited. this doesn't run");
	println("--------------------");
}

void	test_negative_grade()
{
	println("Negative grades are treated as unsigned");
	{
		try
		{
			Bureaucrat	b("Big Bob", -1);
		}
		catch (Bureaucrat::GradeException& e)
		{
			println(std::string("Caught exception: ") + e.what());
		}
	}
	println("--------------------");
}

void	test_increment_grade()
{
	println("Incrementing grade");
	{
		Bureaucrat	b("Bobbing", 42);
		while (1)
		{
			b.incrementGrade();
			println("Bob gets promoted to grade " +
					to_string(b.getGrade()) + "!");
		}
	}
	println("--------------------");
}

void	test_decrement_grade()
{
	println("Decrementing grade");
	{
		Bureaucrat	b("Bobbers", 101);
		while (1)
		{
			b.decrementGrade();
			println("Bob gets demoted to grade " +
					to_string(b.getGrade()) + "...");
		}
	}
	println("--------------------");
}

int	main()
{
	test_orthodox_canonical_form();
	/*test_grade_too_low();*/
	/*test_grade_too_high();*/
	/*test_negative_grade();*/
	/*test_increment_grade();*/
	/*test_decrement_grade();*/
}
