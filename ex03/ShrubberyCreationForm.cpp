/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 22:59:49 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 02:06:54 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

namespace
{
	const char*	GREEN = "\033[0;32m";
	const char*	RED = "\033[0;31m";
	const char*	C_RESET = "\033[0m";
}

/* Default constructor */
ShrubberyCreationForm::ShrubberyCreationForm():
AForm("ShrubberyCreationForm",
	  "Default target",
	  145,
	  137)
{
	std::cout << GREEN << "ShrubberyCreationForm's default constructor called"
			  << C_RESET << '\n';
}

/* Constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm's constructor called"
			  << C_RESET << '\n';
}

/* Copy constructor */
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
AForm(other)
{
	std::cout << GREEN << "ShrubberyCreationForm's copy constructor called"
			  << C_RESET << '\n';
}

/* Copy assignment operator */
ShrubberyCreationForm&
ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << GREEN << "ShrubberyCreationForm's copy assignment operator called"
			  << C_RESET << '\n';
	AForm::operator=(rhs);
	return *this;
}

/* Destructor */
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm's destructor called"
			  << C_RESET << '\n';
}

void	ShrubberyCreationForm::action() const
{
	std::string		filename = getTarget() + "_shrubbery";
	std::ofstream	outfile(filename.c_str());

	outfile <<
"                                                         . \n\
                                              .         ;   \n\
                 .              .              ;%     ;;   \n\
                   ,           ,                :;%  %;   \n\
                    :         ;                   :;%;'\n\
           ,.        %;     %;            ;        %;'    ,;\n\
             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n\
              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n\
               ;%;      %;        ;%;        % ;%;  ,%;'\n\
                `%;.     ;%;     %;'         `;%%;.%;'\n\
                 `:;%.    ;%%. %@;        %; ;@%;%'\n\
                    `:%;.  :;bd%;          %;@%;'\n\
                      `@%:.  :;%.         ;@@%;'\n \
                        `@%.  `;@%.      ;@@%;\n    \
                          `@%%. `@%%    ;@@%;\n \
                            ;@%. :@%%  %@@%;\n\
                              %@bd%%%bd%%:;\n\
                                #@%%%%%:;;\n\
                                %@@%%%::;\n\
                                %@@@%(o);  . '\n\
                                %@@@o%;:(.,'\n\
                            `.. %@@@o%::;\n\
                               `)@@@o%::;\n\
                                %@@(o)::;\n\
                               .%@@@@%::;\n\
                               ;%@@@@%::;\n \
                              ;%@@@@%%:;;;.\n\
                          ...;%@@@@@%%:;;;;,..\n\
\n\
\n\
\n\
               1                         1                         1\n\
              111                       111                       111\n\
             11111                     11111                     11111\n\
            1111111                   1111111                   1111111\n\
           111111111                 111111111                 111111111\n\
             11111                     11111                     11111\n\
            1111111                   1111111                   1111111\n\
           111111111                 111111111                 111111111\n\
          11111111111               11111111111               11111111111\n\
         1111111111111             1111111111111             1111111111111\n\
           111111111                 111111111                 111111111\n\
          11111111111               11111111111               11111111111\n\
         1111111111111             1111111111111             1111111111111\n\
        111111111111111           111111111111111           111111111111111\n\
       11111111111111111         11111111111111111         11111111111111111\n\
         1111111111111             1111111111111             1111111111111\n\
        111111111111111           111111111111111           111111111111111\n\
       11111111111111111         11111111111111111         11111111111111111\n\
      1111111111111111111       1111111111111111111       1111111111111111111\n\
     111111111111111111111     111111111111111111111     111111111111111111111\n\
              111                       111                       111\n\
              111                       111                       111\n\
              111                       111                       111\n";
}
