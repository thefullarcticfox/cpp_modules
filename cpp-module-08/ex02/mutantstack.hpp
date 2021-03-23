#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template< class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	MutantStack(const Container& ctnr = Container());
	virtual ~MutantStack();
	MutantStack(const MutantStack<T, Container>& other);
	MutantStack<T, Container>&	operator=(const MutantStack<T, Container>& other);

	typedef typename std::stack<T, Container>::container_type::iterator
		iterator;
	typedef typename std::stack<T, Container>::container_type::const_iterator
		const_iterator;
	typedef typename std::stack<T, Container>::container_type::reverse_iterator
		reverse_iterator;
    typedef typename std::stack<T, Container>::container_type::const_reverse_iterator
		const_reverse_iterator;
	typedef typename std::stack<T, Container>::container_type::difference_type
		difference_type;

	iterator				begin(void);
	iterator				end(void);
	const_iterator			begin(void) const;
	const_iterator			end(void) const;
	reverse_iterator		rbegin(void);
	reverse_iterator		rend(void);
	const_reverse_iterator	rbegin(void) const;
	const_reverse_iterator	rend(void) const;
};

#endif
