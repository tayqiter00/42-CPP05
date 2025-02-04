/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:47:53 by qtay              #+#    #+#             */
/*   Updated: 2024/11/11 10:04:48 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "[ GENERAL ]" << std::endl;
	{
		Form f1("Grade 5 form", 5, 5); // Constructor
		Form f2(f1); // Copy constructor
		Form f3; 
		
		f3 = f2; // Copy assignment
		std::cout << f1 << "\n";
	}

	std::cout << std::endl;
	std::cout << "[ TEST 1: FORM GRADE TOO LOW ]" << std::endl;
	try
	{
		Form a("Low", 151, 1);
		std::cout << a << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << std::endl;
	std::cout << "[ TEST 2: FORM GRADE TOO HIGH ]" << std::endl;
	try
	{
		Form b("High", 0, 1);
		std::cout << b << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	
	std::cout << std::endl;
	std::cout << "[ TEST 3: BUREAU CANNOT SIGN ]" << std::endl;
	{
		Bureaucrat b1("Bureau-1", 150);
		Form c("Form grade 149", 149, 1);		
		std::cout << b1 << '\n';
		b1.signForm(c);
	}

	std::cout << std::endl;
	std::cout << "[ TEST 4: NORMAL ]" << std::endl;
	{
		Bureaucrat b2("Bureau-2", 1);
		Form d("Form grade 75", 75, 1);		
		std::cout << b2 << '\n';
		b2.signForm(d);
	}
	
	return (0);
}
