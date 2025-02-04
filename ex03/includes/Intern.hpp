/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:52:56 by qtay              #+#    #+#             */
/*   Updated: 2024/11/11 15:24:01 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class AForm;

class Intern
{
	private:
		/* data */

	public:
		Intern(void);
		Intern(Intern &intern);
		Intern	&operator=(Intern &intern);
		~Intern(void);
		AForm	*makeForm(std::string const formName, std::string const target) const;

		class FormDoesNotExistException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

#endif
