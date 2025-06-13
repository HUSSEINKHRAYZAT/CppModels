/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:00:17 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 19:00:17 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../Include/Bureaucrat.hpp"
#include "../Include/PresidentialPardonForm.hpp"

int main()
{
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm form("Ford Prefect");

		std::cout << "\nTrying to execute without signing:\n";
		try {
			president.executeForm(form);
		} catch (const std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}

		std::cout << "\nSigning the form:\n";
		form.beSigned(president);

		std::cout << "\nTrying to execute after signing:\n";
		president.executeForm(form);

	} catch (const std::exception& e) {
		std::cerr << "Exception in main: " << e.what() << std::endl;
	}

	return 0;
}



