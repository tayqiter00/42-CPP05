/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:31:34 by qtay              #+#    #+#             */
/*   Updated: 2024/12/07 21:09:59 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	const	_name;
		bool				_signed;
		size_t const		_gradeToSign;
		size_t const		_gradeToExec;

	public:
		AForm(void);
		AForm(std::string name, size_t gradeToSign, size_t gradeToExec); // ref3 + target
		AForm(const AForm &obj);
		AForm	&operator=(const AForm &obj);
		virtual ~AForm(void);
		
		std::string	getName(void) const;
		bool	getSignedStatus(void) const;
		size_t	getGradeToSign(void) const;
		size_t	getGradeToExec(void) const;
		void	beSigned(Bureaucrat &obj);
		virtual void	execute(Bureaucrat const & executor) const = 0;
	
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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, AForm &obj);

#endif
