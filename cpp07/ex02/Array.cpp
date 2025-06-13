#include <iostream>
#include "Array.hpp"


template<typename mytype>
Array<mytype>::Array() : a_array(new mytype[0]), s_size(0) {}

template<typename mytype>
Array<mytype>::Array(unsigned int n) {
	this->a_array = new mytype[n];
	for (unsigned int i = 0; i < n; i++)
		this->a_array[n] = 0;
	this->s_size = n;
}

template<typename mytype>
Array<mytype>::Array(Array const &src) {
	*this = src;
}

template<typename mytype>
Array<mytype>::~Array() {
	delete [] this->a_array;
}

template<typename mytype>
Array<mytype> &	Array<mytype>::operator=(Array<mytype> const &rSym) {
	if (this != &rSym) {
		delete [] this->a_array;
		this->a_array = new mytype[rSym.s_size];
		this->s_size = rSym.s_size;
		for (int i = 0; i < rSym.s_size; i++)
			this->a_array[i] = rSym.a_array[i];
	}
	return *this;
}

template<typename mytype>
mytype		Array<mytype>::operator[](int n) const {
	mytype	instance;

	if (n > this->s_size - 1)
		throw Array::OutOfBoundException();
	instance = this->a_array[n];
	return instance;
}

template<typename mytype>
mytype &		Array<mytype>::operator[](int n) {
	if (n > this->s_size - 1)
		throw Array::OutOfBoundException();
	return this->a_array[n];
}

template <class mytype>
const char* Array<mytype>::OutOfBoundException::what() const throw()
{
	return ("Value is out of bound.");
}

template<typename mytype>
int		Array<mytype>::size() const {
	return this->s_size;
}
