#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <list>


class Notfound : public std::exception{
    public:
        virtual const char * what() const throw();

};

template<typename T>
int easyfind(T const &lst , int value);

#endif
