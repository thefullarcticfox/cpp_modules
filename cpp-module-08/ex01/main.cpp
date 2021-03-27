#include <iostream>
#include <ctime>
#include <cstdlib>
#include "span.hpp"

int		main(void)
{
	Span						sp = Span(5);
	Span						sp2 = Span(25600);
	Span						sp3 = Span(2);
	std::vector<int>			vect;
	int							i = -1;

	std::srand(std::time(NULL));
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	vect.reserve(30000);
	while (++i != 25600)
		vect.push_back(std::rand());
	vect[0] = -2147483648;
	vect[25599] = 2147483647;
	sp2.addNumber(vect.begin(), vect.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	try
	{
		sp2.addNumber(0);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "----------------------------------------" << std::endl;
	sp3.addNumber(5);
	try
	{
		std::cout << sp3.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------------------------------------" << std::endl;
	sp3.addNumber(150);
	try
	{
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
		sp3.addNumber(1412784);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Span					sp4 = Span(0);
		sp4.addNumber(vect.begin(), vect.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		Span					sp5 = Span(2);
		sp5.addNumber(vect.end(), vect.end() - 2);
		std::cout << sp5.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
