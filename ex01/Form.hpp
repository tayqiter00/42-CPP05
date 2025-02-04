/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:31:34 by qtay              #+#    #+#             */
/*   Updated: 2024/11/10 16:03:22 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	const	_name;
		bool				_signed;
		size_t const		_gradeToSign;
		size_t const		_gradeToExec;

	public:
		Form(void);
		Form(std::string name, size_t gradeToSign, size_t gradeToExec);
		Form(const Form &obj);
		Form	&operator=(const Form &obj);
		~Form(void);
		
		std::string	getName(void) const;
		bool	getSignedStatus(void) const;
		size_t	getGradeToSign(void) const;
		size_t	getGradeToExec(void) const;
		void	beSigned(Bureaucrat &obj);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, Form &obj);

#endif
