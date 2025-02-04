/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:44:17 by qtay              #+#    #+#             */
/*   Updated: 2024/11/11 01:47:39 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

/**
 * Required grades: sign 25, exec 5
 * 
 * Informs that <target> has been pardoned by Zaphod Beeblebrox.
 * 
 * Can take only one parameter in their constructor.
 */
class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &obj);
		
		void	executePPF(void) const;
		void	execute(Bureaucrat const &executor) const;	// override
};

#endif
