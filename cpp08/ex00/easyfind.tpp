#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

const char *  Notfound::what() const throw(){
    return " VALUE NOT FOUND";
}


template<typename T>
int easyfind(T const &lst , int value)
{
    typename T::const_iterator it;
    typename T::const_iterator iter;

    it=lst.begin();
    iter=lst.end();
    for(;it!=iter;it++)
    {
        if(*it==value)
            return *it;
    }
    Notfound();
    return (0);
}


#endif
