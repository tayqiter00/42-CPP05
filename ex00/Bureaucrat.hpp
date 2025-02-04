/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:02:13 by qtay              #+#    #+#             */
/*   Updated: 2024/11/09 22:32:35 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

/**
 * Exceptions are runtime errors that a program encounters during its
 * execution.
 * 
 * Exception handling is done using try, catch and throw.
 * 
 * std::exception is the base class for all standard exceptions in C++. You can
 * throw an exception using this base class or your own derived class, which in
 * turn can be caught using a catch block.
 * 
 * what() is a member function of the std::exception class. It provides a
 * description of the exception that was thrown. The throw() specification
 * prevents the what() function from throwing any exceptions whatsover (in
 * C++98 and C++03) otherwise the program will be terminated.
 * 		virtual const char* what() const throw();
 */
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

		std::string	getName(void);
		size_t		&getGrade(void);
		void		upGrade(void);
		void		downGrade(void);

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
