/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:47:53 by qtay              #+#    #+#             */
/*   Updated: 2024/12/07 22:59:33 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

int	main()
{
	Intern someRandomIntern;
	std::cout << std::endl;

	const std::string formNames[] =
	{
		"Robotomy Request Form",
		"Presidential Pardon Form",
		"Shrubbery Creation Form",
		"Rubbish Form"
	};

	for (int i = 0; i < 4; ++i)
	{
		try
		{
			AForm* form = someRandomIntern.makeForm(formNames[i], "Bender");
			if (form)
				delete form;
		}
		catch (const Intern::FormDoesNotExistException& e)
		{
			std::cerr << e.what() << ": " << formNames[i] << '\n';
		}
		std::cout << std::endl;
	}
	return (0);
}

