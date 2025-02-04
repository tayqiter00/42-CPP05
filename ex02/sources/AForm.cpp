/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:31:32 by qtay              #+#    #+#             */
/*   Updated: 2024/11/11 10:17:10 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"

AForm::AForm(void)
	: _name("Default name"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "AForm default constructor called\n";
}

AForm::AForm(std::string name, size_t gradeToSign, size_t gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw (AForm::GradeTooHighException());
	if (gradeToSign > 150 || gradeToExec > 150)
		throw (AForm::GradeTooLowException());
	else
		std::cout << "AForm parameterized constructor called\n";
}

AForm::AForm(const AForm &obj)
	: _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
	std::cout << "AForm copy constructor called\n";	
}

AForm	&AForm::operator=(const AForm &obj)
{
	if (this != &obj)
		this->_signed = obj._signed;
	std::cout << "AForm copy assignment operator called\n";	
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSignedStatus(void) const
{
	return (this->_signed);
}

size_t	AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

size_t	AForm::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

void	AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= this->getGradeToSign())
	{
		if (this->_signed == false)
			this->_signed = true; // bureaucrat.signForm(this->getName(), this->is_signed);
		else
		{
			std::cout << "Form already signed\n";
			return ;
		}
	}
	else
		throw (AForm::GradeTooLowException());
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called\n";	
}

std::ostream	&operator<<(std::ostream &stream, AForm &obj)
{
	stream << " -------- FORM INFO -------- \n" 
	<< "Form Name    : " << obj.getName() << '\n'
	<< "Signed status: " << obj.getSignedStatus() << '\n'
	<< "Grade to sign: " << obj.getGradeToSign() << '\n'
	<< "Grade to exec: " << obj.getGradeToExec();

	return (stream);
}

/**
 * Keep as "Form" for printing errors
 */
const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form exception: Grade too high!");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form exception: Grade too low!");
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form exception: Form not signed!");
}

/**
 * Removed:
 * // else
 * 		// 	this->executeForm();
 */
void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignedStatus() == false)
		throw (AForm::FormNotSignedException());
	if (this->getGradeToExec() < executor.getGrade())
		throw (AForm::GradeTooLowException());
}
