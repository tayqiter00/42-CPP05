/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:40:39 by qtay              #+#    #+#             */
/*   Updated: 2024/11/11 02:12:48 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

/**
 * Required grades: sign 145, exec 137
 * 
 * Create a file <target>_shrubbery in the working directory, and writes ASCII trees 
 * inside it.
 * 
 * Can take only one parameter in their constructor, e.g., "home" for home
 * directory.
 */
class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;	

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &form);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &form);

		void	executeSCF(void) const;
		void	execute(Bureaucrat const &executor) const;
};

#endif
