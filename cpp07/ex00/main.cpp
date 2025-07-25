#include <iostream>
#include "whatever.hpp"

template<typename mytype>
void	swap(mytype &a, mytype &b)
{
	mytype	c;

	c = a;
	a = b;
	b = c;
}
template<typename mytype>
mytype	min(mytype a, mytype b)
{
	if (a >= b)
		return (b);
	else
		return (a);
}
template<typename mytype>
mytype	max(mytype a, mytype b)
{
	if (a <= b)
		return (b);
	else
		return (a);
}

int	main(void)
{
	int a = 3;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	return (0);
}