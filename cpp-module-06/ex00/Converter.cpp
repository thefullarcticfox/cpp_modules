#include "Converter.hpp"

Converter::Converter() {}

int			Converter::isFloat(const std::string& str)
{
	if (str == "nanf" || str == "-nanf" || str == "+nanf" ||
		str == "inff" || str == "-inff" || str == "+inff")
		return (1);
	if (str == "nan" || str == "-nan" || str == "+nan" ||
		str == "inf" || str == "-inf" || str == "+inf")
		return (2);

	std::string::const_iterator	it = str.begin();

	if (str.find_first_of(".eE") == std::string::npos)
		return (0);
	if (it != str.end() && (*it == '-' || *it == '+'))
		++it;

	if (it == str.end() || (*it != '.' && !isdigit(*it)))
		return (0);

	while (it != str.end() && isdigit(*it))
		++it;

	if (it != str.end() && *it == '.')
	{
		++it;
		if (it != str.end() && !(isdigit(*it) || *it == 'f' ||
			*it == 'e' || *it == 'E'))
			return (0);
	}

	while (it != str.end() && isdigit(*it))
		++it;

	if (it != str.end() && (*it == 'e' || *it == 'E'))
	{
		++it;
		if (it != str.end() && (*it == '+' || *it == '-'))
		{
			++it;
			if (it == str.end() || !isdigit(*it))
				return (0);
		}
		else if (it == str.end() || !isdigit(*it))
			return (0);
	}

	while (it != str.end() && isdigit(*it))
		++it;

	if (it == str.end())
		return (2);
	if (*it == 'f' && ++it == str.end())
		return (1);
	return (0);
}

Converter::Converter(const std::string& value)
{
	this->actualtype = 0;

	if (value.length() == 0 || (value.length() == 1 && !isdigit(value[0])))
		this->actualtype = 1;
	else if ((isdigit(value[0]) &&
		value.find_first_not_of("0123456789") == std::string::npos) ||
		((value[0] == '-' || value[0] == '+') && value.length() > 1 &&
		value.substr(1).find_first_not_of("0123456789") == std::string::npos))
		this->actualtype = 2;
	else	//	check floats
	{
		int res = isFloat(value);
		if (res == 1)
			this->actualtype = 3;
		if (res == 2)
			this->actualtype = 4;
	}

	try
	{
		if (value.length() == 0)
			this->charvalue = '\0';
		else if (this->actualtype == 1)
			this->charvalue = value[0];
		else if (this->actualtype == 2)
			this->intvalue = Converter::ft_stoi(value);
		else if (this->actualtype == 3)
			this->floatvalue = Converter::ft_stof(value);
		else if (this->actualtype == 4)
			this->doublevalue = Converter::ft_stod(value);
		if (this->actualtype == 3 || this->actualtype == 4)
		{
			if (value.find_first_of('e') == std::string::npos)
				this->precision = value.find_last_of("123456789") - value.find_first_of('.');
			else
				this->precision = -1;
		}
		else
			this->precision = 0;
	}
	catch (std::exception& e)
	{
		(void)e;
		this->actualtype = 0;
	}
}

Converter::~Converter()
{
}

Converter::Converter(const Converter& other)
{
	*this = other;
}

Converter&	Converter::operator=(const Converter& other)
{
	this->actualtype = other.actualtype;
	this->charvalue = other.charvalue;
	this->intvalue = other.intvalue;
	this->floatvalue = other.floatvalue;
	this->doublevalue = other.doublevalue;
	return (*this);
}

std::string		Converter::getactualtype(void) const
{
	if (this->actualtype == 1)
		return ("char");
	else if (this->actualtype == 2)
		return ("int");
	else if (this->actualtype == 3)
		return ("float");
	else if (this->actualtype == 4)
		return ("double");
	return ("unhandled literal type or overflows actual type");
}

char			Converter::getChar(void) const
{
	int		tmp = -1;

	if (!this->actualtype)
		throw (Converter::ImpossibleException());
	if (this->actualtype == 1)
		tmp = static_cast<int>(charvalue);
	else if (this->actualtype == 2)
		tmp = static_cast<int>(intvalue);
	else if (this->actualtype == 3)
		tmp = static_cast<int>(floatvalue);
	else if (this->actualtype == 4)
		tmp = static_cast<int>(doublevalue);
	if (tmp < -128 || tmp > 127)
		throw (Converter::ImpossibleException());
	if (tmp < 32 || tmp > 126)
		throw (Converter::NonDisplayableException());
	return (static_cast<char>(tmp));
}

int				Converter::getInt(void) const
{
	if (!this->actualtype)
		throw (Converter::ImpossibleException());
	if (this->actualtype == 1)
		return (static_cast<int>(charvalue));
	else if (this->actualtype == 3)
	{
		if (floatvalue < static_cast<float>(std::numeric_limits<int>::min()) ||
			floatvalue > static_cast<float>(std::numeric_limits<int>::max()) ||
			floatvalue != floatvalue)		// isnan(floatvalue))
			throw (Converter::ImpossibleException());
		return (static_cast<int>(floatvalue));
	}
	else if (this->actualtype == 4)
	{
		if (doublevalue < static_cast<double>(std::numeric_limits<int>::min()) ||
			doublevalue > static_cast<double>(std::numeric_limits<int>::max()) ||
			doublevalue != doublevalue)		// isnan(doublevalue))
			throw (Converter::ImpossibleException());
		return (static_cast<int>(doublevalue));
	}
	return (this->intvalue);
}

float			Converter::getFloat(void) const
{
	if (!this->actualtype)
		throw (Converter::ImpossibleException());
	if (this->actualtype == 1)
		return (static_cast<float>(charvalue));
	else if (this->actualtype == 2)
		return (static_cast<float>(intvalue));
	else if (this->actualtype == 4)
	{
		if (doublevalue != 0.0 &&
			doublevalue != std::numeric_limits<float>::infinity() &&
			doublevalue != -std::numeric_limits<float>::infinity() &&
			(fabs(doublevalue) < std::numeric_limits<float>::min() ||
			fabs(doublevalue) > std::numeric_limits<float>::max()))
			throw (Converter::ImpossibleException());
		return (static_cast<float>(doublevalue));
	}
	return (this->floatvalue);
}

double			Converter::getDouble(void) const
{
	if (!this->actualtype)
		throw (Converter::ImpossibleException());
	if (this->actualtype == 1)
		return (static_cast<double>(charvalue));
	else if (this->actualtype == 2)
		return (static_cast<double>(intvalue));
	else if (this->actualtype == 3)
		return (static_cast<double>(floatvalue));
	return (this->doublevalue);
}

int				Converter::getprecision() const
{
	return (this->precision);
}

std::ostream&	operator<<(std::ostream& os, const Converter& val)
{
	char	tmp;

	os << "literal type: " << val.getactualtype() << std::endl;
	os << "char: ";
	try
	{
		tmp = val.getChar();
		os << "\'" << tmp << "\'" << std::endl;
	}
	catch (std::exception& e)
	{
		os << e.what() << std::endl;
	}
	os << "int: ";
	try
	{
		os << val.getInt() << std::endl;
	}
	catch (std::exception& e)
	{
		os << e.what() << std::endl;
	}
	os << "float: ";
	try
	{
		if (val.getFloat() != std::numeric_limits<float>::quiet_NaN() &&
			val.getFloat() != std::numeric_limits<float>::infinity() &&
			val.getFloat() != -std::numeric_limits<float>::infinity() &&
			val.getFloat() == floorf(val.getFloat()))
			os << std::fixed << std::setprecision(1);
		else if (val.getprecision() > 0)
			os << std::fixed << std::setprecision(val.getprecision());
		os << val.getFloat();
		os << "f" << std::endl;
	}
	catch (std::exception& e)
	{
		os << e.what() << std::endl;
	}
	os << "double: ";
	try
	{
		os << val.getDouble();
		os << std::endl;
	}
	catch (std::exception& e)
	{
		os << e.what() << std::endl;
	}
	return (os);
}

const char*	Converter::ImpossibleException::what()
	const throw()
{
	return ("impossible");
}

const char*	Converter::NonDisplayableException::what()
	const throw()
{
	return ("Non displayable");
}

Converter::ImpossibleException::ImpossibleException() {}

Converter::ImpossibleException::~ImpossibleException() throw() {}

Converter::ImpossibleException::ImpossibleException(
	const Converter::ImpossibleException& other)
{
	*this = other;
}

Converter::ImpossibleException&	Converter::ImpossibleException::operator=(
	const Converter::ImpossibleException& other)
{
	(void)other;
	return (*this);
}

Converter::NonDisplayableException::NonDisplayableException() {}

Converter::NonDisplayableException::~NonDisplayableException() throw() {}

Converter::NonDisplayableException::NonDisplayableException(
	const Converter::NonDisplayableException& other)
{
	*this = other;
}

Converter::NonDisplayableException&	Converter::NonDisplayableException::operator=(
	const Converter::NonDisplayableException& other)
{
	(void)other;
	return (*this);
}

int					Converter::ft_stoi(const std::string& str)
{
	std::istringstream	iss(str);
	int					val = 0;

	if (!(iss >> val))
		throw (std::out_of_range("stoi"));
	return (val);
}

float				Converter::ft_stof(const std::string& str)
{
	if (str == "-nan" || str == "-nanf")
		return (-std::numeric_limits<float>::quiet_NaN());
	if (str == "nan" || str == "nanf" || str == "+nan" || str == "+nanf")
		return (std::numeric_limits<float>::quiet_NaN());
	if (str == "-inff" || str == "-inf")
		return (-std::numeric_limits<float>::infinity());
	if (str == "+inff" || str == "inff" || str == "+inf" || str == "inf")
		return (std::numeric_limits<float>::infinity());

	std::stringstream	iss;
	if (str.size() > 0 && str.at(str.size() - 1) == 'f')
		iss << str.substr(0, str.size() - 1);
	else
		iss << str;
	float				val = 0;

	if (!(iss >> val))	//	this fails on macOS for some reason if string contains f
		throw (std::out_of_range("stof"));
	return (val);
}

double				Converter::ft_stod(const std::string& str)
{
	if (str == "-nan" || str == "-nanf")
		return (-std::numeric_limits<double>::quiet_NaN());
	if (str == "nan" || str == "nanf" || str == "+nan" || str == "+nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	if (str == "-inff" || str == "-inf")
		return (-std::numeric_limits<double>::infinity());
	if (str == "+inff" || str == "inff" || str == "+inf" || str == "inf")
		return (std::numeric_limits<double>::infinity());

	std::istringstream	iss(str);
	double				val = 0;

	if (!(iss >> val))
		throw (std::out_of_range("stod"));
	return (val);
}
