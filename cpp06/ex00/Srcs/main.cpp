/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:12:00 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/25 18:12:01 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
        ScalarConverter::convert(av[1]);
    else
        std::cout << "bad arguments!" << std::endl;
}
