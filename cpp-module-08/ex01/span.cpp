#include "span.hpp"

Span::Span()
{
	this->_size = 0;
	this->numbers.reserve(0);
}

Span::Span(unsigned int const &n)
{
	this->_size = n;
	this->numbers.reserve(n);
}

Span::~Span()
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span			&Span::operator=(Span const &other)
{
	this->_size = other._size;
	this->numbers = other.numbers;
	return (*this);
}

void			Span::addNumber(int const &num)
{
	if (this->_size == this->numbers.size())
		throw (Span::NotEnoughSpaceException());
	this->numbers.push_back(num);
}

unsigned int	Span::shortestSpan(void)
{
	std::vector<int>			tmp = this->numbers;
	std::vector<int>::iterator	begin = tmp.begin();
	unsigned int				span = -1;

	if (this->_size < 2 || this->numbers.size() < 2)
		throw (Span::NoSpanToFindException());
	std::sort(tmp.begin(), tmp.end());
	while (++begin != tmp.end())
		if (span > static_cast<unsigned int>(std::abs(*begin - *(begin - 1))))
			span = static_cast<unsigned int>(std::abs(*begin - *(begin - 1)));
	return (span);
}

unsigned int	Span::longestSpan(void)
{
	long int	max;
	long int	min;

	if (this->_size < 2 || this->numbers.size() < 2)
		throw (Span::NoSpanToFindException());
	max = *std::max_element(this->numbers.begin(), this->numbers.end());
	min = *std::min_element(this->numbers.begin(), this->numbers.end());
	return (static_cast<unsigned int>(std::abs(max - min)));
}

const char		*Span::NoSpanToFindException::what() const throw()
{
	return ("No span to find (vector is too short)");
}

const char		*Span::NotEnoughSpaceException::what() const throw()
{
	return ("Can't store numbers (vector is full)");
}

const char		*Span::BadIteratorRangeException::what() const throw()
{
	return ("Bad iterator range");
}

Span::NoSpanToFindException::NoSpanToFindException() {}

Span::NoSpanToFindException::~NoSpanToFindException() throw() {}

Span::NoSpanToFindException::NoSpanToFindException(
	Span::NoSpanToFindException const &other)
{
	*this = other;
}

Span::NoSpanToFindException &Span::NoSpanToFindException::operator=(
	Span::NoSpanToFindException const &other)
{
	(void)other;
	return (*this);
}

Span::NotEnoughSpaceException::NotEnoughSpaceException() {}

Span::NotEnoughSpaceException::~NotEnoughSpaceException() throw() {}

Span::NotEnoughSpaceException::NotEnoughSpaceException(
	Span::NotEnoughSpaceException const &other)
{
	*this = other;
}

Span::NotEnoughSpaceException &Span::NotEnoughSpaceException::operator=(
	Span::NotEnoughSpaceException const &other)
{
	(void)other;
	return (*this);
}

Span::BadIteratorRangeException::BadIteratorRangeException() {}

Span::BadIteratorRangeException::~BadIteratorRangeException() throw() {}

Span::BadIteratorRangeException::BadIteratorRangeException(
	Span::BadIteratorRangeException const &other)
{
	*this = other;
}

Span::BadIteratorRangeException &Span::BadIteratorRangeException::operator=(
	Span::BadIteratorRangeException const &other)
{
	(void)other;
	return (*this);
}
