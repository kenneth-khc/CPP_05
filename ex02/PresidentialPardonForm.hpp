/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecheong <kecheong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 00:14:17 by kecheong          #+#    #+#             */
/*   Updated: 2025/01/06 00:20:03 by kecheong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm(); // default constructor
	PresidentialPardonForm(const std::string&); // constructor
	PresidentialPardonForm(const PresidentialPardonForm&); // copy constructor
	PresidentialPardonForm&	operator=(const PresidentialPardonForm&); // copy assignment operator
	~PresidentialPardonForm(); // destructor
		
	virtual void	action() const; // override
};

#endif
