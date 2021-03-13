#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>

// my tests
template <typename T>
void			iter(T *array, size_t size, void (*f)(T const &arg))
{
	size_t	i = 0;

	while (i < size)
		f(array[i++]);
}

template<typename T>
void			printelement(T const &element)
{
	std::cout << element << " ";
}


// checklist tests
class Awesome {
private:
	int		_n;
public:
	Awesome(void) : _n(42) { return ; }
	int		get(void) const { return (this->_n); }
};

std::ostream	&operator<<(std::ostream &o, Awesome const &rhs)
{
	o << rhs.get();
	return (o);
}

template<typename T>
void			print(T const &x)
{
	std::cout << x << std::endl;
	return ;
}

int				main(void)
{
	char	bytes[42];
	int		numbers[10];
	size_t	size_ts[5];
	float	floats[10];
	double	doubles[10];
	char	alphanum[63] =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	size_t	i = 0;

	std::srand(std::time(NULL));
	while (i < 42)
		bytes[i++] = alphanum[std::rand() % 62];
	i = 0;
	while (i < 10)
		numbers[i++] = std::rand();
	i = 0;
	while (i < 5)
		size_ts[i++] = -(static_cast<size_t>(std::rand()));
	i = 0;
	while (i < 10)
		floats[i++] = static_cast<float>(std::rand()) /
			static_cast<float>(RAND_MAX);
	i = 0;
	while (i < 10)
		doubles[i++] = static_cast<double>(std::rand()) /
			static_cast<double>(RAND_MAX);
	iter(bytes, 42, printelement);
	std::cout << std::endl;
	iter(numbers, 10, printelement);
	std::cout << std::endl;
	iter(size_ts, 5, printelement);
	std::cout << std::endl;
	iter(floats, 10, printelement);
	std::cout << std::endl;
	iter(doubles, 10, printelement);
	std::cout << std::endl;
	iter(alphanum + 10, 53, printelement);
	std::cout << std::endl;
	iter(alphanum, 10, printelement);
	std::cout << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	// checklist tests
	int		tab[] = {0, 1, 2, 3, 4};
	Awesome	tab2[5];

	iter(tab, 5, print);
	iter(tab2, 5, print);

	return (0);
}
