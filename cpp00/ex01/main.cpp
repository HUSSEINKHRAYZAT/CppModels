/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:04:06 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/04/06 11:38:18 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainheader.hpp"

int	main()
{
	PhoneBook	PhoneBook;

	str			line;
	str			add = "ADD";
	str			search = "SEARCH";
	str			exit = "EXIT";

	
	system("clear");
	std::cout << "Hello ! Welcome to your new contact manager." << std::endl;
	while (1)
	{
		std::cout << "Type ADD, SEARCH or EXIT : \n";
		std::getline(std::cin, line);
		if (!line.compare(add))
			PhoneBook.addContact();
		else if (!line.compare(search))
			PhoneBook.searchContact();
		else if (!line.compare(exit))
		{
			std::cout << "Goodbye !" << std::endl;
			break;
		}
		system("clear");
	}
	return 0;
}