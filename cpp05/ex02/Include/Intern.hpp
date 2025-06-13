/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:57:50 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/23 18:57:51 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include <string>

class Intern {
public:
    Intern(void);
    Intern(const Intern &src);
    ~Intern(void);
    Intern &operator=(const Intern &rhs);

    Form *makeForm(std::string formName, std::string target) const;

    class FormNotFoundException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

private:
    Form *createShrubberyForm(std::string target) const;
    Form *createRobotomyForm(std::string target) const;
    Form *createPresidentialForm(std::string target) const;
};

#endif
