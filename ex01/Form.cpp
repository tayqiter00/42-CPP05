/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:31:32 by qtay              #+#    #+#             */
/*   Updated: 2024/11/10 17:45:05 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: _name("Default name"), _signed(false), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Form default constructor called\n";
}

Form::Form(std::string name, size_t gradeToSign, size_t gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw (Form::GradeTooHighException());
	if (gradeToSign > 150 || gradeToExec > 150)
		throw (Form::GradeTooLowException());
	else
		std::cout << "Form parameterized constructor called\n";
}

Form::Form(const Form &obj)
	: _name(obj._name), _signed(obj._signed), _gradeToSign(obj._gradeToExec), _gradeToExec(obj._gradeToExec)
{
	std::cout << "Form copy constructor called\n";	
}

Form	&Form::operator=(const Form &obj)
{
	if (this != &obj)
		this->_signed = obj._signed;
	std::cout << "Form copy assignment operator called\n";	
	return (*this);
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSignedStatus(void) const
{
	return (this->_signed);
}

size_t	Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

size_t	Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

void	Form::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() <= this->getGradeToSign())
	{
		if (this->_signed == false)
			this->_signed = true;
		else
		{
			std::cout << "Form already signed\n";
			return ;
		}
	}
	else
		throw (Form::GradeTooLowException());
}

Form::~Form(void)
{
	std::cout << "Form destructor called\n";	
}

std::ostream	&operator<<(std::ostream &stream, Form &obj)
{
	stream << " -------- FORM INFO -------- \n" 
	<< "Form Name    : " << obj.getName() << '\n'
	<< "Signed status: " << obj.getSignedStatus() << '\n'
	<< "Grade to sign: " << obj.getGradeToSign() << '\n'
	<< "Grade to exec: " << obj.getGradeToExec();

	return (stream);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form exception: Grade too high!");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form exception: Grade too low!");
}
