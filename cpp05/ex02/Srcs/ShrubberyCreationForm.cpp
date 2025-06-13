/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:59:33 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 18:59:34 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("Unknown")
{
	std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
}



ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target)
{
    std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file(target.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open the file." << std::endl;
        return;
    }

    file << "       _-_\n"
         << "    /~~   ~~\\\n"
         << " /~~         ~~\\\n"
         << "{               }\n"
         << " \\  _-     -_  /\n"
         << "   ~  \\\\ //  ~\n"
         << "_- -   | | _- _\n"
         << "  _ -  | |   -_\n"
         << "      // \\\\\n";
    file.close();
}
