/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:19:29 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 00:42:45 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class	RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(); // default constructor
	RobotomyRequestForm(const std::string&); // constructor
	RobotomyRequestForm(const RobotomyRequestForm&); // copy constructor
	RobotomyRequestForm&	operator=(const RobotomyRequestForm&); // copy assignment operator
	~RobotomyRequestForm(); // destructor
		
	virtual void	action() const; // override
};

#endif
