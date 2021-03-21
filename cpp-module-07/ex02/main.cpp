#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>
#include "Array.tpp"

int		main(void)
{
	Array<int>		a(10);
	Array<int>*		b = new Array<int>();
	Array<char>		c(42);
	int				i = 0;

	std::srand(time(NULL));
	try
	{
		std::cout << "a (random generated ints): " << std::endl;
		while (i < 11)
		{
			a[i] = std::rand() % 1000000;
			std::cout << a[i++] << " ";
		}
	}
	catch (const std::exception& e)
	{
		std::cout << std::endl << e.what() << std::endl;
		try
		{
			std::cout << "b (empty array check)" << std::endl;
			(*b)[0] = 0;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "a size: " << a.size() << "; " <<
		"b size: " << b->size() << std::endl;

	std::cout << "----------------------------------------" << std::endl;
	*b = a;
	*b = *b;
	std::cout << "b size after a assign: " << b->size() << std::endl;
	(*b)[1] = 100000;
	(*b)[4] = 400000;
	(*b)[9] = 900000;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "b (modified copy of a):" << std::endl;
	i = 0;
	while (i < 10)
		std::cout << (*b)[i++] << " ";
	std::cout << std::endl;

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "a (check for unmodified):" << std::endl;
	i = 0;
	while (i < 10)
		std::cout << a[i++] << " ";
	std::cout << std::endl;
	delete (b);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "c (random generated chars): " << std::endl;
	i = 0;
	while (i < 42)
		c[i++] = char(97 + (std::rand() % 26));
	i = 0;
	while (i < 42)
		std::cout << c[i++] << "";
	std::cout << std::endl;

	std::cout << "----------------------------------------" << std::endl;
	Array<int>			cpy(a);
	std::cout << "cpy(a) (cpy constructor check):" << std::endl;
	i = 0;
	while (i < 10)
		std::cout << cpy[i++] << " ";
	std::cout << std::endl;

	// empty array test
	Array<std::string>*	empty = new Array<std::string>();
	delete (empty);

	return (0);
}
