#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<class T>
class MutantStack : public std::stack<T> {
public:
	MutantStack();
	virtual ~MutantStack();
	MutantStack(const MutantStack<T>& other);
	MutantStack<T>&	operator=(const MutantStack<T>& other);

	typedef typename std::stack<T>::container_type::iterator
		iterator;
	typedef typename std::stack<T>::container_type::const_iterator
		const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator
		reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator
		const_reverse_iterator;
	typedef typename std::stack<T>::container_type::difference_type
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
