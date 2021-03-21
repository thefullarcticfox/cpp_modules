#include <iostream>
#include <string>

class Awesome {
private:
	int		_n;
public:
	Awesome(int n) : _n(n) {}

	bool		operator==(const Awesome& rhs) { return (this->_n == rhs._n); }
	bool		operator!=(const Awesome& rhs) { return (this->_n != rhs._n); }
	bool		operator>(const Awesome& rhs) { return (this->_n > rhs._n); }
	bool		operator<(const Awesome& rhs) { return (this->_n < rhs._n); }
	bool		operator>=(const Awesome& rhs) { return (this->_n >= rhs._n); }
	bool		operator<=(const Awesome& rhs) { return (this->_n <= rhs._n); }

	int			getInt(void) const { return (this->_n); }
};

std::ostream&	operator<<(std::ostream& os, const Awesome& val)
{
	os << val.getInt();
	return (os);
}

template <class T>
void	swap(T& a, T& b)
{
	T	t = a;
	a = b;
	b = t;
}

template <class T>
T&		min(T& a, T& b)
{
	if (a < b)
		return (a);
	return (b);
}

template <class T>
T&		max(T& a, T& b)
{
	if (a > b)
		return (a);
	return (b);
}

int		main(void)
{
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string	c = "chaine1";
	std::string	d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << "----------------------------------------" << std::endl;

	Awesome		a2(2);
	Awesome		b2(3);
	::swap(a2, b2);
	std::cout << "a2 = " << a2 << ", b2 = " << b2 << std::endl;
	std::cout << "min( a2, b2 ) = " << ::min(a2, b2) << std::endl;
	std::cout << "max( a2, b2 ) = " << ::max(a2, b2) << std::endl;

	return (0);
}
