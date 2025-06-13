/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:57:29 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 18:57:29 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Bureaucrat.hpp"
#include "../Include/Form.hpp"

int	main(void)
{
	Bureaucrat	a("Ali", 5);
	Bureaucrat	b("Bob", 140);

	Form	form1("Contract A", 10, 20);
	Form	form2("Contract B", 150, 150);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	a.signForm(form1);
	b.signForm(form2);
	a.signForm(form2); // should succeed

	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;

	return (0);
}
