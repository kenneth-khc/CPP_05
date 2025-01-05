/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 21:14:42 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 06:47:45 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main()
{
	Bureaucrat	bigShot("Big Shot", 1);
	Intern		someRandomIntern;
	AForm*		form;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	bigShot.signForm(*form);
	bigShot.executeForm(*form);
	delete form;

	std::cout << "-------------------------------------------------" << '\n';

	form = someRandomIntern.makeForm("shrubbery creation", "Tender");
	bigShot.signForm(*form);
	bigShot.executeForm(*form);
	delete form;

	std::cout << "-------------------------------------------------" << '\n';

	form = someRandomIntern.makeForm("presidential pardon", "Ender");
	bigShot.signForm(*form);
	bigShot.executeForm(*form);
	delete form;

	std::cout << "-------------------------------------------------" << '\n';

	form = someRandomIntern.makeForm("some non-existent form", "bla bla bla");
}
