/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 19:00:08 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 19:00:08 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/AForm.hpp"

AForm::AForm()
{
    name = "Default AForm";
    isSigned = false;
    gradeToSign = 150;
    gradeToExecute = 150;
    std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeTosign, int gradeToexecute)
{
    this->name = name;
    this->gradeToSign = gradeTosign;
    this->gradeToExecute = gradeToexecute;
    isSigned = false;
    std::cout << "AForm Constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const AForm &other)
{
    this->name = other.name;
    this->gradeToSign = other.gradeToSign;
    this->gradeToExecute = other.gradeToExecute;
    this->isSigned = other.isSigned;
    std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->name = other.name;
    return *this;
}

const std::string &AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() < this->gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "This form is not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << "AForm " << AForm.getName()
	   << ", signed: " << (AForm.getIsSigned() ? "true" : "false")
	   << ", sign grade: " << AForm.getGradeToSign()
	   << ", exec grade: " << AForm.getGradeToExecute();
	return os;
}


