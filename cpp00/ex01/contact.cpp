/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:04:19 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/04/06 10:26:48 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mainheader.hpp"

Contact::Contact(){};

Contact::~Contact(){};

void Contact::setFirstName(str FirstName)
{
	this->FirstName = FirstName;
}
void Contact::setLastName(str LastName)
{
	this->LastName = LastName;
}
void Contact::setNickName(str NickName)
{
	this->NickName = NickName;
}
void Contact::setPhone(str Phone)
{
	this->Phone = Phone;
}

str Contact::getFirstName()
{
	return (this->FirstName);
}
str Contact::getLastName()
{
	return (this->LastName);
}
str Contact::getNickName()
{
	return (this->NickName);
}
str Contact::getPhone()
{
	return (this->Phone);
}