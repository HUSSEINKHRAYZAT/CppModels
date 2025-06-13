/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:12:15 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/25 18:12:15 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>

class Data {
private:
	int id;
	std::string name;
	double value;

public:
	Data(void);
	Data(int id, const std::string& name, double value);
	Data(const Data& other);
	~Data(void);

	Data& operator=(const Data& other);

	int getId(void) const;
	const std::string& getName(void) const;
	double getValue(void) const;

	void setId(int id);
	void setName(const std::string& name);
	void setValue(double value);
};

#endif
