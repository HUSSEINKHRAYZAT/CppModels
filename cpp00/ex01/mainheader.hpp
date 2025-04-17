/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainheader.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:03:58 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/04/06 10:31:40 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAINHEADER_H
#define MAINHEADER_H

#include <iostream>
#include <cctype>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>
#include <cstdio>

typedef std::string str;

class Contact
{
  public:
	Contact();
	~Contact();

	void setFirstName(str FirstName);
	void setLastName(str LastName);
	void setNickName(str NickName);
	void setPhone(str Phone);
	str getFirstName();
	str getLastName();
	str getNickName();
	str getPhone();
  private:
	str FirstName;
	str LastName;
	str NickName;
	str Phone;
};

class PhoneBook
{
  public:
	PhoneBook();
	~PhoneBook();
	void addContact();
	void searchContact();

  private:
	int id;
	int i;
	Contact array[8];
};
#endif