/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:59:18 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 18:59:18 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../Include/Bureaucrat.hpp"
#include "../Include/PresidentialPardonForm.hpp"
#include "../Include/Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        Form* rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        // Do something with the form
        std::cout << *rrf << std::endl;

        // Don't forget to delete the form when done
        delete rrf;
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}



