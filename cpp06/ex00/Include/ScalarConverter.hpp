/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:11:50 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/25 18:11:51 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class ScalarConverter
{
public:
    static bool isChar(const std::string &input);
    static bool isInt(const std::string &input);
    static bool isFloat(const std::string &input);
    static bool isDouble(const std::string &input);
    static int	isPseudoLiteral(const std::string& literal);

    static void convChar(const std::string &input);
    static void convInt(const std::string &input);
    static void convFloat(const std::string &input);
    static void convDouble(const std::string &input);

    static void convert(const std::string &input);

    ScalarConverter();
    ScalarConverter(const ScalarConverter& src);
    ScalarConverter& operator=(const ScalarConverter& src);
    ~ScalarConverter();
};


#endif
