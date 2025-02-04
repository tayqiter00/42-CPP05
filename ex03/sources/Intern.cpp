/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:54:45 by qtay              #+#    #+#             */
/*   Updated: 2024/12/07 23:01:25 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(Intern &intern)
{
	(void)intern;
	std::cout << "Intern copy constructor called\n";
}

Intern	&Intern::operator=(Intern &intern)
{
	if (this != &intern)
		std::cout << "Intern copy assignment operator called\n";
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called\n";	
}

const	char	*Intern::FormDoesNotExistException::what(void) const throw()
{
	return ("Intern exception: Form does not exist");
}

static AForm*	makePresidentialPardonForm(std::string const &target)
{
    return (new PresidentialPardonForm(target));
}

static AForm*	makeRobotomyRequestForm(std::string const &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm*	makeShrubberyCreationForm(std::string const &target)
{
    return (new ShrubberyCreationForm(target));
}

/**
 * Cannot do form = &PresentialPardonForm() because the address will be a temporary
 * object. Have to use "new".
 */
AForm	*Intern::makeForm(std::string const formName, std::string const target) const
{
	AForm* ret;

	std::string formTypes[] =
		{
			"Presidential Pardon Form",
			"Robotomy Request Form",
			"Shrubbery Creation Form"
		};
	AForm* (*ft_ptrs[])(std::string const &) =
		{
			&makePresidentialPardonForm,
			&makeRobotomyRequestForm,
			&makeShrubberyCreationForm,
		};
	for (size_t i = 0; i < 3; i++)
	{
		if (formName.compare(formTypes[i]) == 0)
		{
			ret = ft_ptrs[i](target);
            std::cout << "Intern creates " << formName << std::endl;
			return (ret);
		}
	}
    throw (Intern::FormDoesNotExistException());
}
