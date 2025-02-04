/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:41:10 by qtay              #+#    #+#             */
/*   Updated: 2024/11/11 10:11:29 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: AForm("PPForm", 25, 5), _target("Default target")
{
	std::cout << "Presidential Pardon Form default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PPForm", 25, 5), _target(target)
{
	std::cout << "Presidential Pardon Form parameterized constructor called\n";	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj)
	: AForm(obj), _target(obj._target)
{
	std::cout << "Presidential Pardon Form copy constructor called\n";	
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential Pardon Form destructor called\n";	
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this != &obj)
	{
		AForm::operator=(obj);
		this->_target = obj._target;
		std::cout << "Presidential Pardon Form copy assignment operator called\n";
	}
	return (*this);
}

void	PresidentialPardonForm::executePPF(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox!\n";
}

/**
 * form is signed and that the grade of the bureaucrat
 */
	// if (!this->getSignedStatus())
	// 	throw (AForm::FormNotSignedException());
	// if (executor.getGrade() > this->getGradeToExec())
	// 	throw (AForm::GradeTooLowException());
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << executor.getName() << " executed " << this->getName() << " form\n";
	this->executePPF();
}
