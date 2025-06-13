/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:12:23 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/25 18:12:23 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/Data.hpp"

Data::Data(void) : id(0), name(""), value(0.0) {}

Data::Data(int id, const std::string& name, double value) : id(id), name(name), value(value) {}

Data::Data(const Data& other) : id(other.id), name(other.name), value(other.value) {}

Data::~Data(void) {}

Data& Data::operator=(const Data& other)
{
	if (this != &other) {
		this->id = other.id;
		this->name = other.name;
		this->value = other.value;
	}
	return *this;
}

int Data::getId(void) const
{
	return this->id;
}

const std::string& Data::getName(void) const
{
	return this->name;
}

double Data::getValue(void) const
{
	return this->value;
}

void Data::setId(int id) {
	this->id = id;
}

void Data::setName(const std::string& name)
{
	this->name = name;
}

void Data::setValue(double value)
{
	this->value = value;
}
