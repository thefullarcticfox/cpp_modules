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
	Converter(const std::string& value);
	virtual ~Converter();
	Converter(const Converter& other);
	Converter&		operator=(const Converter& other);

	std::string		getactualtype(void) const;
	char			getChar(void) const;
	int				getInt(void) const;
	float			getFloat(void) const;
	double			getDouble(void) const;

	class ImpossibleException : public std::exception {
	public:
		ImpossibleException();
		virtual ~ImpossibleException() throw();
		ImpossibleException(const ImpossibleException& other);
		ImpossibleException&		operator=(const ImpossibleException& other);

		virtual const char*			what() const throw();
	};
	class NonDisplayableException : public std::exception {
	public:
		NonDisplayableException();
		virtual ~NonDisplayableException() throw();
		NonDisplayableException(const NonDisplayableException& other);
		NonDisplayableException&	operator=(const NonDisplayableException& other);

		virtual const char*			what() const throw();
	};

	int				getprecision() const;

	static int		isFloat(const std::string& str);
	static char		getChar(const std::string& str);
	static int		ft_stoi(const std::string& str);
	static float	ft_stof(const std::string& str);
	static double	ft_stod(const std::string& str);
};

std::ostream&		operator<<(std::ostream& os, const Converter& val);

#endif
