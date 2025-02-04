/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:02:13 by qtay              #+#    #+#             */
/*   Updated: 2024/11/10 16:16:17 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const	std::string	_name;
		size_t	_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(std::string giveName, size_t givenGrade);
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat	&operator=(const Bureaucrat &obj);
		~Bureaucrat(void);

		std::string	getName(void) const;
		size_t		&getGrade(void);
		void		upGrade(void);
		void		downGrade(void);
		void		signForm(Form &obj);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &newOut, Bureaucrat &Bureaucrat);

#endif
