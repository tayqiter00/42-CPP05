/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:48:41 by qtay              #+#    #+#             */
/*   Updated: 2024/12/07 21:25:18 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RRForm", 72, 45), _target("Default target")
{
	std::cout << "Robotomy Request Form default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RRForm", 72, 45), _target(target)
{
	std::cout << "Robotomy Request Form parameterized constructor called\n";	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
	: AForm(form), _target(form._target)
{
	std::cout << "Robotomy Request Form copy constructor called\n";	
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy Request Form destructor called\n";	
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
	{
		AForm::operator=(form);
		this->_target = form._target;
		std::cout << "Robotomy Request Form copy assignment operator called\n";
	}
	return (*this);
}

void	RobotomyRequestForm::executeRRF(void) const
{
	static int	counter = 0;

	std::cout << "[DRILLING NOISES] BRRRRRRRRRRRRRRR... ";
	if (counter % 2 == 0)
		std::cout << this->_target << " has been successfully robotomized!\n";
	else
		std::cout << this->_target << "'s robotomy failed!\n";
	counter++;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << executor.getName() << " executed " << this->getName() << " form\n";
	this->executeRRF();
}
