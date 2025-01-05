/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:27:32 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 00:20:32 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(); // default constructor
	ShrubberyCreationForm(const std::string&); // constructor
	ShrubberyCreationForm(const ShrubberyCreationForm&); // copy constructor
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm&); // copy assignment operator
	~ShrubberyCreationForm(); // destructor
		
	virtual void	action() const; // override
};

#endif
