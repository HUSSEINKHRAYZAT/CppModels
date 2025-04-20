/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:04:13 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/04/06 11:29:59 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainheader.hpp"

PhoneBook :: PhoneBook() : id(0),i(0)
{} 
PhoneBook :: ~PhoneBook()
{}

void PhoneBook :: addContact()
{
        str FirstName;
        str LastName;
        str NickName;
        str Phone;
        if (this->id == 8)
                this->id = 0;
        std :: cout << "Enter the first name \n";
        std :: getline(std::cin, FirstName);
        std :: cout << "Enter the last name \n";
        std :: getline(std::cin, LastName);
        std :: cout << "Enter the Nick name \n";
        std :: getline(std::cin, NickName);
        std :: cout << "Enter the Phone number \n";
        std :: cin >> Phone;
        this->array[id].setFirstName(FirstName);
        this->array[id].setLastName(LastName);
        this->array[id].setNickName(NickName);
        this->array[id].setPhone(Phone);
        this->id++;
	if (i < 8)
		i++;
        return;
} 

void	PhoneBook::searchContact()
{
	int	b = 0;
	str	name;
	str	last;
	str	nick;
	str	phone;
	str	ret;
	int	index;
	
	system("clear");
	if (this->i == 0) {
		std::cout << "No contact avalaible ! Abort..." << std::endl; sleep(2); return;
	}
	std::cout << std::setw(5) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (b < i) {
		std::cout << std::setw(5) << b << "|";
		name = this->array[b].getFirstName();
		last = this->array[b].getLastName();
		nick = this->array[b].getNickName();
		phone = this->array[b].getPhone();
		if (name.length() > 9)
			name = name.substr(0, 9) + ".";
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
		std::cout << std::setw(10) << name << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << std::endl;
		b++;
	}
	std::cout << std::endl << "Type a contact's index to obtain personal informations : ";
	std:: cin >> ret; 
	index = atoi(ret.c_str());
	if ((index == 0 && ret[0] != '0') || (index > 7 || index < 0)) {
		std::cout << "Please enter a valid digit ! Abort..." << std::endl;
                return;
	}
	if (index >= this->id) {
		std::cout << "No contact found ! Abort..." << std::endl;
                return;
	}
	std::cout << "Name : " << this->array[index].getFirstName() << std::endl;
	std::cout << "Lastname : " << this->array[index].getLastName() << std::endl;
	std::cout << "Nickname : " << this->array[index].getNickName() << std::endl;
	std::cout << "Phone number : " << this->array[index].getPhone() << std::endl;
	std::cout << std::endl << "Press a key to continue..." << std::endl;
	getchar();
	getchar();
}