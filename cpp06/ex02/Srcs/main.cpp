/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkhrayza <hkhrayza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:13:09 by hkhrayza          #+#    #+#             */
/*   Updated: 2025/05/25 18:13:10 by hkhrayza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include <ctime>
#include "../Include/Base.hpp"
#include "../Include/A.hpp"
#include "../Include/B.hpp"
#include "../Include/C.hpp"

Base* generate(void) {
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}

	int random = std::rand() % 3;

	switch (random) {
		case 0:
			std::cout << "Generated class A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated class B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated class C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (const std::bad_cast&) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (const std::bad_cast&) {
		std::cout << "Unknown type" << std::endl;
	}
}

int main(void) {
	std::cout << "=== Testing generate() function ===" << std::endl;
	Base* obj1 = generate();
	Base* obj2 = generate();
	Base* obj3 = generate();

	std::cout << std::endl;

	// Test the identify function with pointer
	std::cout << "=== Testing identify(Base* p) function ===" << std::endl;
	std::cout << "Object 1 type: ";
	identify(obj1);
	std::cout << "Object 2 type: ";
	identify(obj2);
	std::cout << "Object 3 type: ";
	identify(obj3);

	std::cout << std::endl;

	// Test the identify function with reference
	std::cout << "=== Testing identify(Base& p) function ===" << std::endl;
	std::cout << "Object 1 type: ";
	identify(*obj1);
	std::cout << "Object 2 type: ";
	identify(*obj2);
	std::cout << "Object 3 type: ";
	identify(*obj3);

	// Clean up
	delete obj1;
	delete obj2;
	delete obj3;

	return 0;
}
