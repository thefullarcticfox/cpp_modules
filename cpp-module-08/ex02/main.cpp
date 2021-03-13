#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include "mutantstack.cpp"

int		main(void)
{
	std::srand(std::time(NULL));

	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>		s(mstack);

	std::cout << "----------------------------------------" << std::endl;

	MutantStack<long>	mstack2;
	while (distance(mstack2.rbegin(), mstack2.rend()) < 20)
		mstack2.push(distance(mstack2.rbegin(), mstack2.rend()));
	std::cout << "added " << distance(mstack2.begin(), mstack2.end()) <<
		" numbers" << std::endl;
	MutantStack<long>::iterator				it2 = mstack2.begin();
	while (it2 != mstack2.end())
	{
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << std::endl;
	std::cout << "reverse iterator test" << std::endl;
	MutantStack<long>::reverse_iterator		rit2 = mstack2.rbegin();
	while (rit2 != mstack2.rend())
	{
		std::cout << *rit2 << " ";
		rit2++;
	}
	std::cout << std::endl;
	std::cout << "const iterators test" << std::endl;
	MutantStack<long>::const_iterator			cit2 = mstack2.end() - 6;
	std::cout << *cit2 << std::endl;
	MutantStack<long>::const_reverse_iterator	crit2 = mstack2.rbegin() + 5;
	std::cout << *crit2 << std::endl;
	return (0);
}
