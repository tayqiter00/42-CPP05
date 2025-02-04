/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:02:25 by qtay              #+#    #+#             */
/*   Updated: 2025/02/04 14:47:33 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default bureaucrat"), _grade(150) 
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string givenName, size_t givenGrade)
	:_name(givenName)
{
		if (givenGrade > 150)
			throw (Bureaucrat::GradeTooLowException());
		else if (givenGrade < 1)
			throw (Bureaucrat::GradeTooHighException());
		else
		{
			this->_grade = givenGrade;
			std::cout << "Bureaucrat parameterized constructor called\n";
		}
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
	: _name(obj._name), _grade(obj._grade)
{
	std::cout << "Bureaucrat copy constructor called\n";
}

/**
 * Bureaucrat can only copy grade because _name is declared as constant
 */
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		this->_grade = obj._grade;
		std::cout << "Bureaucrat copy assignment operator called\n";
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called\n";
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

size_t &Bureaucrat::getGrade(void)
{
	return (this->_grade);
}

void	Bureaucrat::upGrade(void)
{

	if (this->_grade > 1)
	{
		this->getGrade()--;
		std::cout << this->getName() << " upgraded to grade " << this->getGrade() << "\n";
	}
	else
		throw (Bureaucrat::GradeTooHighException());
}

void	Bureaucrat::downGrade(void)
{
	if (this->_grade < 150)
	{
		this->getGrade()++;
		std::cout << this->getName() << " downgraded to grade " << this->getGrade() << "\n";
	}
	else
		throw (Bureaucrat::GradeTooLowException());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat exception: Grade too high!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat exception: Grade too low!");
}

std::ostream	&operator<<(std::ostream &newOut, Bureaucrat &Bureaucrat)
{
	newOut << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return (newOut);
}

/* *********************************  ADDED  ******************************** */

void		Bureaucrat::signForm(Form &obj)
{

	try
	{
		obj.beSigned(*this);
		std::cout << this->getName() << " signed " << obj.getName() << " form.\n";
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cerr << this->getName() << " couldn’t sign " << obj.getName()
			<< " because " << e.what() << '\n';
	}
}
