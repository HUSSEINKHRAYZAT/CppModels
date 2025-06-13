/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:12:06 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/25 18:12:07 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

bool ScalarConverter::isChar(const std::string &input)
{
	if (input[0] == '\'' && input.length() == 3 && input[2] == '\'')
		return true;
	return false;
}

bool ScalarConverter::isInt(const std::string &input)
{
	std::size_t i = 0;

	if (input.empty())
		return false;
	if (input[0] == '-' || input[0] == '+')
		i++;
	while (i < input.length())
	{
		if (!isdigit(input[i]))
			return false;
		i++;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string &input)
{
	if (input.empty())
		return false;

	int ptr = 0;
	int i = 0;
	int length = input.length();

	if (input == "nanf" || input == "+inff" || input == "-inff")
		return true;

	if (input[length - 1] != 'f' || input[0] == '.')
		return false;

	while (i < length - 1)
	{
		if (input[i] == '.')
			ptr++;
		else if (!isdigit(input[i]))
			return false;
		i++;
	}

	if (ptr != 1)
		return false;

	return true;
}

bool ScalarConverter::isDouble(const std::string &input)
{
	if (input.empty())
		return false;

	if (input == "nan" || input == "+inf" || input == "-inf")
		return true;

	int dotCount = 0;
	int i = 0;
	int length = input.length();

	if (input[0] == '+' || input[0] == '-')
		i++;

	if (input[i] == '.' || input[length - 1] == '.')
		return false;

	while (i < length)
	{
		if (input[i] == '.')
			dotCount++;
		else if (!isdigit(input[i]))
			return false;
		i++;
	}

	return dotCount == 1;
}


int	ScalarConverter::isPseudoLiteral(const std::string& literal)
{
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (2);
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return (1);
	return (0);
}

void	 ScalarConverter::convChar(const std::string &input)
{
	std::cout << "char: ";
	if (ScalarConverter::isPseudoLiteral(input) != 0 || ScalarConverter::isChar(input) == false)
		std::cout << "impossible" << std::endl;
	else
		std::cout << input[1] << std::endl;
}

void ScalarConverter::convInt(const std::string &input)
{
	std::cout << "int: ";
	if (ScalarConverter::isPseudoLiteral(input) != 0 || ScalarConverter::isInt(input) == false)
		std::cout << "impossible" << std::endl;
	else
	{
		int i = atoi(input.c_str());
		std::cout << i << std::endl;
	}
}

void ScalarConverter::convFloat(const std::string &input)
{
	std::cout << "float: ";
	if (ScalarConverter::isPseudoLiteral(input) == 1|| ScalarConverter::isFloat(input) == false)
		std::cout << "impossible" << std::endl;
	else if (ScalarConverter::isPseudoLiteral(input) == 2)
		std::cout  << input << std::endl;
	else
	{
		float f = std::atof(input.c_str());
		std::cout << f << std::endl;
	}
}

void ScalarConverter::convDouble(const std::string &input)
{
	std::cout << "double: ";
	if (ScalarConverter::isPseudoLiteral(input) == 2 || ScalarConverter::isDouble(input) == false)
		std::cout << "impossible" << std::endl;
	else if (ScalarConverter::isPseudoLiteral(input) == 1)
		std::cout  << input << std::endl;
	else
	{
		double d = std::atof(input.c_str());
		std::cout << d << std::endl;
	}
}

void ScalarConverter::convert(const std::string &input)
{
    ScalarConverter::convChar(input);
    ScalarConverter::convInt(input);
    ScalarConverter::convFloat(input);
    ScalarConverter::convDouble(input);
}
