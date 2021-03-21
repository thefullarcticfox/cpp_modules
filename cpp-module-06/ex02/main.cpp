#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"

Base*	generate(void)
{
	Base*	p = NULL;
	int		i = std::rand() % 3;

	if (i == 0)
	{
		std::cout << "new A" << std::endl;
		p = new A();
	}
	else if (i == 1)
	{
		std::cout << "new B" << std::endl;
		p = new B();
	}
	else
	{
		std::cout << "new C" << std::endl;
		p = new C();
	}
	return (p);
}

void	identify_from_pointer(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}


// easy identify_from_reference implementation
/*
void	identify_from_reference(Base& p)
{
	identify_from_pointer(&p);
}
*/

// harder identify_from_reference implementation
void	identify_from_reference(Base& p)
{
	try
	{
		A		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& bc)
	{
		try
		{
			B	b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (const std::exception& bc)
		{
			C	c = dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
		}
	}
}

int		main(void)
{
	Base*	base = NULL;
	int		i = -1;

	std::srand(std::time(NULL));
	try
	{
		while (++i < 10)
		{
			std::cout << "Test " << i << std::endl;
			base = generate();
			std::cout << "Ptr test: ";
			identify_from_pointer(base);
			std::cout << "Ref test: ";
			identify_from_reference(*base);
			delete (base);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << " at test " << i << std::endl;
	}
	return (0);
}
