#include <iostream>
#include "iteration.hpp"


template<typename mytype>
void iter(mytype *address,int len,void (*func)(mytype &x))
{
    for (int i =0; i < len; i++ )
    {
        func(address[i]);
    }

}


template<typename mytype>
void printing(mytype &x)
{
    std::cout << "the value is " << x << "\n";
}

int main()
{
    char var[]={'H','U','S','S','E','I','N'};
    iter(var ,7,printing<char>);
    return 0;
}