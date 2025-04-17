/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:08:44 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/04/05 10:27:34 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int i, j;
	i = 1;
	j = 0;
	if (argc == 1)
	{
		std ::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	}
	else
	{
		while (argv[i])
		{
			while (argv[i][j])
			{
				std ::cout << (char)toupper(argv[i][j]);
				j++;
			}
			std ::cout << " ";
			j = 0;
			i++;
		}
		std ::cout << std ::endl;
	}
	return (0);
}