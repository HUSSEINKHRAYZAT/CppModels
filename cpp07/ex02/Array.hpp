#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

typedef std::string str;

template<typename mytype>
class Array {
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &ref);
		~Array();

		Array &	operator=(Array const &ref);
		mytype		operator[](int n) const;
		mytype &		operator[](int n);
		int		size() const;
		
		class OutOfBoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
	private:
		mytype *	a_array;
		int	s_size;
};

#endif