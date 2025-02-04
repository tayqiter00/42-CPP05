/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:43:02 by qtay              #+#    #+#             */
/*   Updated: 2024/11/11 02:06:04 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

/**
 * Required grades: sign 72, exec 45
 * 
 * Makes some drilling noises. Then, informs that <target> has been robotomized
 * successfully 50% of the time. Otherwise, informs that the robotomy failed.
 * 
 * Can take only one parameter in their constructor.
 */
class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &form);
		~RobotomyRequestForm(void);
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &form);
		
		void	executeRRF(void) const;
		void	execute(Bureaucrat const &executor) const;
};

#endif
