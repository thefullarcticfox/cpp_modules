#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>

class Span {
private:
	std::vector<int>	numbers;
	size_t				_size;
	Span();
public:
	Span(unsigned int n);
	~Span();
	Span(const Span& other);
	Span&	operator=(const Span& other);

	void				addNumber(int num);
	template<typename Iter>
	void				addNumberRange(Iter first, Iter last)
	{
		if (std::distance(first, last) < 0)
			throw (Span::BadIteratorRangeException());
		if (std::distance(first, last) >
			static_cast<long>(this->_size - this->numbers.size()))
			throw (Span::NotEnoughSpaceException());
		while (first != last)
			this->numbers.push_back(*(first++));
	}

	unsigned int		shortestSpan(void);
	unsigned int		longestSpan(void);

	class NoSpanToFindException : public std::exception {
	public:
		NoSpanToFindException();
		virtual ~NoSpanToFindException() throw();
		NoSpanToFindException(const NoSpanToFindException& other);
		NoSpanToFindException&	operator=(const NoSpanToFindException& other);

		virtual const char*		what() const throw();
	};
	class NotEnoughSpaceException : public std::exception {
	public:
		NotEnoughSpaceException();
		virtual ~NotEnoughSpaceException() throw();
		NotEnoughSpaceException(const NotEnoughSpaceException& other);
		NotEnoughSpaceException&	operator=(const NotEnoughSpaceException& other);

		virtual const char*		what() const throw();
	};
	class BadIteratorRangeException : public std::exception {
	public:
		BadIteratorRangeException();
		virtual ~BadIteratorRangeException() throw();
		BadIteratorRangeException(const BadIteratorRangeException& other);
		BadIteratorRangeException&	operator=(const BadIteratorRangeException& other);

		virtual const char*		what() const throw();
	};
};

#endif
