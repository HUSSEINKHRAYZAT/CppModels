/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:56:53 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 18:56:53 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Alice", 2);
		std::cout << a << std::endl;

		a.incrementGrade();
		std::cout << a << std::endl;

		a.incrementGrade(); // Should throw
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	b("Bob", 149);
		std::cout << b << std::endl;

		b.decrementGrade();
		std::cout << b << std::endl;

		b.decrementGrade(); // Should throw
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	c("Charlie", 151); // Should throw
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
