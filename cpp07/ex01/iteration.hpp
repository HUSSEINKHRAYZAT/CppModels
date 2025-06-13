#ifndef ITERATION_HPP
# define ITERATION_HPP


template<typename mytype>
void iter(mytype *address,int len,void (*func)(mytype &x));


template<typename mytype>
void printing(mytype x);
#endif