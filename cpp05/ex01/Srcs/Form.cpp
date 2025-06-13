/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:57:25 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 18:57:25 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Form.hpp"

Form::Form()
{
    name = "Default Form";
    isSigned = false;
    gradeToSign = 150;
    gradeToExecute = 150;
    std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string name, int gradeTosign, int gradeToexecute)
{
    this->name = name;
    this->gradeToSign = gradeTosign;
    this->gradeToExecute = gradeToexecute;
    isSigned = false;
    std::cout << "Form Constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form &other)
{
    this->name = other.name;
    this->gradeToSign = other.gradeToSign;
    this->gradeToExecute = other.gradeToExecute;
    this->isSigned = other.isSigned;
    std::cout << "Form Copy Constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->name = other.name;
    return *this;
}

const std::string &Form::getName() const
{
    return name;
}

bool Form::getisSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::besigned(const Bureaucrat &b)
{
    if (b.getGrade() < this->gradeToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName()
	   << ", signed: " << (form.getisSigned() ? "true" : "false")
	   << ", sign grade: " << form.getGradeToSign()
	   << ", exec grade: " << form.getGradeToExecute();
	return os;
}


