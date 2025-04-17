#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &val) {
	std::cout << "Copy constructor called" << std::endl;
	*this = val;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &sval) {
	std::cout << "Copy assignement operator called" << std::endl;
	this->value = sval.getRawBits();
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}