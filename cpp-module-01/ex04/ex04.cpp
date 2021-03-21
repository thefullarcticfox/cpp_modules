#include <iostream>
#include <iomanip>
#include <string>

int		main(void)
{
	std::string		s = "HI THIS IS BRAIN";
	std::string*	s_ptr = &s;
	std::string&	s_ref = s;

	std::cout << std::setw(33) << "initial string: " << s << std::endl;
	std::cout << std::setw(33) << "string via pointer to string: " <<
		*s_ptr << std::endl;
	std::cout << std::setw(33) << "pointer to string address: " <<
		s_ptr << std::endl;
	std::cout << std::setw(33) << "string via reference to string: " <<
		s_ref << std::endl;
	std::cout << std::setw(33) << "pointer to string reference: " <<
		&s_ref << std::endl;
	return (0);
}
