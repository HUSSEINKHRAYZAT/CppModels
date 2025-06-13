/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:59:12 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 18:59:12 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void) {
}

Intern::Intern(const Intern &src) {
    *this = src;
}

Intern::~Intern(void) {
}

Intern &Intern::operator=(const Intern &rhs) {
    (void)rhs;
    return *this;
}

Form *Intern::makeForm(std::string formName, std::string target) const {
    const std::string formTypes[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    int formIndex = -1;
    for (int i = 0; i < 3; i++) {
        if (formName == formTypes[i]) {
            formIndex = i;
            break;
        }
    }
    Form* form = NULL;
    switch (formIndex) {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
            throw FormNotFoundException();
    }

    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}

const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}

