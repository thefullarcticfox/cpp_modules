#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <string>
# include <sstream>
# include <exception>

template <typename T>
class Array {
private:
	T				*array;
	unsigned int	_size;
public:
	Array()
	{
		this->array = new T[0];
		this->_size = 0;
	}

	Array(unsigned int const &n)
	{
		this->_size = n;
		this->array = new T[this->_size];
	}

	virtual ~Array()
	{
		delete[] (array);
	}

	Array(Array const &other)
	{
		this->array = new T[0];
		this->_size = 0;
		*this = other;
	}

	Array			&operator=(Array const &other)
	{
		unsigned int	i = 0;

		if (this == &other)
			return (*this);
		delete[] (this->array);
		this->_size = other._size;
		this->array = new T[this->_size];
		while (i < this->_size)
		{
			this->array[i] = other.array[i];
			i++;
		}
		return (*this);
	}

	T				&operator[](unsigned int const &index)
	{
		std::stringstream	errmsg;

		if (index >= this->_size)
		{
			errmsg << "no element with index " << index;
			throw (std::out_of_range(errmsg.str()));
		}
		return (this->array[index]);
	}

	unsigned int	size(void)
	{
		return (this->_size);
	}
};

#endif
