#include "span.hpp"

// constractors and oper

Span ::Span() : size(0),maxsize(0)
{
}

Span ::Span(unsigned int N) : size(0),maxsize(N)
{
}

Span::Span(Span const &src)
{
	this->array = src.array;
	this->maxsize = src.maxsize;
	this->size = src.size;
}

Span::~Span()
{
}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->maxsize = src.maxsize;
		this->size = src.maxsize;
		this->array = src.array;
	}
	return (*this);
}

// error exeptions

const char *Span::MaxNumb::what() const throw()
{
	return ("maximum nuber error \n");
};
const char *Span::OneNumb::what() const throw()
{
	return ("One nuber error \n");
};
const char *Span::NoNumb::what() const throw()
{
	return ("maximum nuber error \n");
};
// functions
int Span::addNumber(unsigned int a)
{
	if (this->size == maxsize)
		throw Span::MaxNumb();
	this->array.push_back(a);
	this->size++;
	return (0);
}
int Span::shortestSpan() const
{
	if (array.size() < 2)
	{
		if (array.empty())
			throw(Span::NoNumb());
		else
			throw(Span::OneNumb());
	}
	std::vector<int> sortedArray(array);
	std::sort(sortedArray.begin(), sortedArray.end());

	int minSpan = std::numeric_limits<int>::max();

	for (size_t i = 0; i < sortedArray.size() - 1; ++i)
	{
		int diff = sortedArray[i + 1] - sortedArray[i];
		if (diff < minSpan)
			minSpan = diff;
	}

	return (minSpan);
}
int Span::longestSpan() const
{
	if (!this->array.size())
		throw Span::NoNumb();
	if (this->array.size() == 1)
		throw Span::OneNumb();

	int max = *std::max_element(this->array.begin(), this->array.end());
	int min = *std::min_element(this->array.begin(), this->array.end());

	return (max - min);
}
int Span::MultiNum(unsigned int a)
{
    for (int i =0 ;i < a ;i++)
        
	
	return (0);
}