/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:14:42 by kecheong          #+#    #+#             */
/*   Updated: 2025/04/29 17:58:40 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

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
void	test_grade_too_low();
void	test_grade_too_high();
void	test_negative_grade();
void	test_increment_grade();
void	test_decrement_grade();
void	f0();

template<typename T>
static void	println(const T& t);

template<typename T>
static std::string	to_string(const T& t);

int	main()
{
	void	(*test_cases[])() = {
		test_orthodox_canonical_form,
		test_grade_too_low,
		test_grade_too_high,
		test_increment_grade,
		test_decrement_grade,
		f0
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
		Bureaucrat	b;

		println(b);
		CHECK(b.getName() == "Default Bureaucrat");
		CHECK(b.getGrade() == 150);
	}
	println("--------------------");
	println("Valid construction");
	{
		Bureaucrat	b("Bob", 42);

		println(b);
		CHECK(b.getName() == "Bob");
		CHECK(b.getGrade() == 42);
	}
	println("--------------------");
	println("Copy construction");
	{
		Bureaucrat	b("Bobby", 99);
		Bureaucrat	bb(b);

		println(b);
		println(bb);
		CHECK(b.getName() == bb.getName());
		CHECK(b.getGrade() == bb.getGrade());
	}
	println("--------------------");
	println("Copy assignment operator");
	{
		Bureaucrat	not_bob;
		Bureaucrat	b("Bob", 4);

		println(not_bob);
		println(b);
		CHECK(not_bob.getName() != b.getName());
		CHECK(not_bob.getGrade() != b.getGrade());
		println("Assigning... ");
		not_bob = b;
		println(not_bob);
		println(b);
		CHECK(not_bob.getName() != b.getName());
		CHECK(not_bob.getGrade() == b.getGrade());
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
		try
		{
			while (1)
			{
				b.incrementGrade();
				println("Bob gets promoted to grade " +
						to_string(b.getGrade()) + "!");
			}
		}
		catch (Bureaucrat::GradeException& e)
		{
			println(std::string("Caught exception: ") + e.what());
		}
	}
	println("--------------------");
}

void	test_decrement_grade()
{
	println("Decrementing grade");
	{
		Bureaucrat	b("Bobbers", 101);
		try
		{
			while (1)
			{
				b.decrementGrade();
				println("Bob gets demoted to grade " +
						to_string(b.getGrade()) + "...");
			}
		}
		catch (Bureaucrat::GradeException& e)
		{
			println(std::string("Caught exception: ") + e.what());
		}
	}
	println("--------------------");
}

void	f10() { throw Bureaucrat::GradeException(-42U, "high"); }
void	f9() { f10(); }
void	f8() { f9(); }
void	f7() { f8(); }
void	f6() { f7(); }
void	f5() { f6(); }
void	f4() { f5(); }
void	f3() { f4(); }
void	f2() { f3(); }
void	f1() { f2(); }
void	f0()
{
	try
	{ 
		f1();
	}
	catch (Bureaucrat::GradeException& e)
	{
		println(e.what());
	}
}

template<typename T>
static void	println(const T& t)
{
	std::cout << t << '\n';
}

template<typename T>
static std::string	to_string(const T& t)
{
	std::stringstream	ss;
	ss << t;
	return ss.str();
}
