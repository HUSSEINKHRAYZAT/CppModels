#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <climits>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unistd.h>

class Span
{
  private:
        unsigned int size;
        unsigned int maxsize;
        std::vector<int>     array;
        std::vector<int>     Allsize() const;

  public:
	Span();
	Span(unsigned int N);
	Span(Span const &src);
	~Span();

    Span& operator=(Span const &src);

    int addNumber(unsigned int a);
    int shortestSpan() const;
    int longestSpan() const;

    class MaxNumb:public std::exception
    {
        public:
                virtual const char *	what() const throw();
    };
    class NoNumb:public std::exception
    {
        public:
                virtual const char *	what() const throw();
    };
    class OneNumb:public std::exception
    {
        public:
                virtual const char *	what() const throw();
    };

};

#endif