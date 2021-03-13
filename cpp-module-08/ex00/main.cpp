#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int		main(void)
{
	std::vector<int>			vect;
	std::vector<int>::iterator	it;

	it = easyfind(vect, 42);
	if (it == vect.end())
		std::cout << "Not Found" << std::endl;
	else
		std::cout << "Found " << *it << std::endl;
	vect.push_back(42);
	it = easyfind(vect, 42);
	if (it == vect.end())
		std::cout << "Not Found" << std::endl;
	else
		std::cout << "Found " << *it << std::endl;
	*it = 123;
	if (easyfind(vect, 42) == vect.end())
		std::cout << "Not Found" << std::endl;
	else
		std::cout << "Found " << *it << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	std::list<int>				list;
	std::list<int>::iterator	itlist;

	itlist = easyfind(list, 42);
	if (itlist == list.end())
		std::cout << "Not Found" << std::endl;
	else
		std::cout << "Found " << *itlist << std::endl;
	list.push_back(42);
	itlist = easyfind(list, 42);
	if (itlist == list.end())
		std::cout << "Not Found" << std::endl;
	else
		std::cout << "Found " << *itlist << std::endl;
	list.push_back(12);
	list.push_back(-1213135);
	itlist = easyfind(list, -1213135);
	if (itlist == list.end())
		std::cout << "Not Found" << std::endl;
	else
		std::cout << "Found " << *itlist << std::endl;
	itlist = easyfind(list, 12);
	if (itlist == list.end())
		std::cout << "Not Found" << std::endl;
	else
		std::cout << "Found " << *itlist << std::endl;
	return (0);
}
