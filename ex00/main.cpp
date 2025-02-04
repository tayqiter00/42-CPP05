/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:47:53 by qtay              #+#    #+#             */
/*   Updated: 2024/11/09 22:03:00 by qtay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "[ GENERAL ]" << std::endl;
	{
		Bureaucrat	b1("alice", 2); // Constructor
		Bureaucrat	b2(b1); // Copy constructor
		Bureaucrat	b3; 
		
		b3 = b2; // Copy assignment (notice how the name for b3 doesn't change)
		std::cout << b3 << "\n";
	}

	std::cout << std::endl;
	std::cout << "[ TEST 1: GRADE TOO LOW ]" << std::endl;
	try
	{
		Bureaucrat a("Low", 0);
		std::cout << a << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << std::endl;
	std::cout << "[ TEST 2: GRADE TOO HIGH ]" << std::endl;
	try
	{
		Bureaucrat b("High", 0);
		std::cout << b << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	
	std::cout << std::endl;
	std::cout << "[ TEST 3: GO BELOW MIN GRADE ]" << std::endl;
	try
	{
		Bureaucrat c("Lowest", 150);
		c.downGrade();
		std::cout << c << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << std::endl;
	std::cout << "[ TEST 4: GO ABOVE MAX GRADE ]" << std::endl;
	try
	{
		Bureaucrat d("Highest", 1);
		d.upGrade();
		std::cout << d << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << std::endl;
	std::cout << "[ TEST 5: NORMAL TEST ]" << std::endl;
	try
	{
		Bureaucrat e("Normal", 75);
		e.upGrade();
		std::cout << e << '\n';
		e.downGrade();
		std::cout << e << '\n';

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	return (0);
}
