/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:47:53 by qtay              #+#    #+#             */
/*   Updated: 2024/12/07 21:30:29 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int	main()
{
	// AForm	f1; // proves AForm is an abstract class

	// std::cout << "[ GENERAL PRESIDENTIAL PARDON FORM ]" << std::endl;
	// {
	// 	PresidentialPardonForm	ppf1; // default constructor
	// 	PresidentialPardonForm	ppf2("Custom PPF2 target"); // param. constructor
	// 	PresidentialPardonForm	ppf3(ppf2); // copy constructor
	// 	PresidentialPardonForm	ppf4;
		
	// 	ppf4 = ppf3; // copy assignment
	// 	std::cout << ppf1 << "\n";
	// 	std::cout << ppf2 << "\n";
	// 	std::cout << ppf3 << "\n";
	// 	std::cout << ppf4 << "\n";
	// }
	// std::cout << "\n";

	// std::cout << "[ GENERAL ROBOTOMY REQUEST FORM ]" << std::endl;
	// {
	// 	RobotomyRequestForm	rrf1; // default constructor
	// 	RobotomyRequestForm	rrf2("Custom RRF2 target"); // param. constructor
	// 	RobotomyRequestForm	rrf3(rrf2); // copy constructor
	// 	RobotomyRequestForm	rrf4;
		
	// 	rrf4 = rrf3; // copy assignment
	// 	std::cout << rrf1 << "\n";
	// 	std::cout << rrf2 << "\n";
	// 	std::cout << rrf3 << "\n";
	// 	std::cout << rrf4 << "\n";
	// }
	// std::cout << "\n";

	// std::cout << "[ GENERAL SHRUBBERY CREATION FORM ]" << std::endl;
	// {
	// 	ShrubberyCreationForm	scf1; // default constructor
	// 	ShrubberyCreationForm	scf2("Custom SCF2 target"); // param. constructor
	// 	ShrubberyCreationForm	scf3(scf2); // copy constructor
	// 	ShrubberyCreationForm	scf4;
		
	// 	scf4 = scf3; // copy assignment
	// 	std::cout << scf1 << "\n";
	// 	std::cout << scf2 << "\n";
	// 	std::cout << scf3 << "\n";
	// 	std::cout << scf4 << "\n";
	// }

/************************************************************************************************/
	
	std::cout << std::endl;
	std::cout << "[ PPForm not signed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 1);
		PresidentialPardonForm	ppf1("Criminal");
		
		b1.executeForm(ppf1);
	}

	std::cout << std::endl;
	std::cout << "[ PPForm cannot be executed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 25);
		PresidentialPardonForm	ppf1("Criminal");
		
		b1.signForm(ppf1);
		b1.executeForm(ppf1);
	}

	std::cout << std::endl;
	std::cout << "[ PPForm can be executed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 5);
		PresidentialPardonForm	ppf1("Criminal");
		
		b1.signForm(ppf1);
		b1.executeForm(ppf1);
	}

/************************************************************************************************/

	std::cout << std::endl;
	std::cout << "[ RRForm not signed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 1);
		RobotomyRequestForm	rrf1("half human");
		
		b1.executeForm(rrf1);
	}

	std::cout << std::endl;
	std::cout << "[ RRForm cannot be executed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 46);
		RobotomyRequestForm	rrf1("half human");
		
		b1.signForm(rrf1);
		b1.executeForm(rrf1);
	}

	std::cout << std::endl;
	std::cout << "[ RRForm can be executed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 5);
		RobotomyRequestForm	rrf1("half-human-1");
		RobotomyRequestForm	rrf2("half-human-2");
		RobotomyRequestForm	rrf3("half-human-3");
		RobotomyRequestForm	rrf4("half-human-4");
		
		b1.signForm(rrf1), b1.signForm(rrf2), b1.signForm(rrf3), b1.signForm(rrf4);
		b1.executeForm(rrf1), b1.executeForm(rrf2), b1.executeForm(rrf3), b1.executeForm(rrf4);
	}
	
/************************************************************************************************/

	std::cout << std::endl;
	std::cout << "[ SCForm not signed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 1);
		ShrubberyCreationForm	scf1("home");
		
		b1.executeForm(scf1);
	}

	std::cout << std::endl;
	std::cout << "[ SCForm cannot be executed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 145);
		ShrubberyCreationForm	scf1("home");
		b1.signForm(scf1);
		b1.executeForm(scf1);
	}

	std::cout << std::endl;
	std::cout << "[ SCForm can be executed ]" << std::endl;
	{
		Bureaucrat	b1("Mr Bureaucrat", 137);
		ShrubberyCreationForm	scf1("home");
		
		b1.signForm(scf1);
		b1.executeForm(scf1);
	}
	return (0);
}
