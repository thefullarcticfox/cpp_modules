#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <string>
# include <cstdlib>
# include <cctype>
# include <cmath>
# include <sstream>
# include <exception>

class Converter {
private:
	int				actualtype;
	char			charvalue;
	int				intvalue;
	float			floatvalue;
	double			doublevalue;
	int				precision;
	Converter();
public:
	Converter(std::string const &value);
	virtual ~Converter();
	Converter(Converter const &other);
	Converter &operator=(Converter const &other);

	std::string		getactualtype(void) const;
	char			getChar(void) const;
	int				getInt(void) const;
	float			getFloat(void) const;
	double			getDouble(void) const;

	class ImpossibleException : public std::exception {
	public:
		ImpossibleException();
		virtual ~ImpossibleException() throw();
		ImpossibleException(ImpossibleException const &other);
		ImpossibleException &operator=(ImpossibleException const &other);

		virtual const char	*what() const throw();
	};
	class NonDisplayableException : public std::exception {
	public:
		NonDisplayableException();
		virtual ~NonDisplayableException() throw();
		NonDisplayableException(NonDisplayableException const &other);
		NonDisplayableException &operator=(NonDisplayableException const &other);

		virtual const char	*what() const throw();
	};

	int				getprecision() const;

	static int		isFloat(std::string const &str);
	static int		ft_stoi(std::string const &str);
	static float	ft_stof(std::string const &str);
	static double	ft_stod(std::string const &str);
};

std::ostream		&operator<<(std::ostream &os, Converter const &val);

#endif
