/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:39 by ldu heron          #+#    #+#             */
/*   Updated: 2023/11/14 13:02:31 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

// Constructor -----------------------------------------------------------------

ScalarConverter::ScalarConverter() : _i(0.0), _c(0), _d(0.0), _f(0.0f), _type(DEFAULT), _isOverflow(FALSE)
{
	// std::cout << "Scalar converter form target constructor called.\n";
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) : _i(src._i), _c(src._c), _d(src._d), _f(src._f), _type(src._type), _isOverflow(src._isOverflow)
{
	// std::cout << "Scalar converter copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

ScalarConverter::~ScalarConverter()
{
	// std::cout << "Scalar converter form destructor called.\n";
}

// Overload --------------------------------------------------------------------

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &src)
{
	this->_i = src._i;
	this->_c = src._c;
	this->_d = src._d;
	this->_f = src._f;
	this->_type = src._type;
	this->_isOverflow = src._isOverflow;
	return (*this);
}

// Exceptions ------------------------------------------------------------------

const char* ScalarConverter::ParseFailException::what() const throw()
{
	return ("Isstream failed to parse.\n");
}

// Functions -------------------------------------------------------------------

void	ScalarConverter::printChar(void)
{
	if (this->_c < 32 || this->_c > 127)
		std::cout << "char: non displayable\n";
	else
		std::cout << "char: '" << this->_c << "'\n";
}

void	ScalarConverter::printDouble(void)
{
	if (this->_d - this->_i != 0)
		std::cout << std::scientific << std::setprecision(5) << "double: " << this->_d << "\n";
	else
		std::cout << std::scientific << std::setprecision(5) << "double: " << this->_d << "\n";
}

void	ScalarConverter::printFloat(void)
{
	if (this->_f - this->_i != 0)
		std::cout << std::fixed << std::setprecision(2) << "float: " << this->_f << "f\n";
	else
		std::cout << std::fixed << std::setprecision(2) << "float: " << this->_f << "f\n";
}

void	ScalarConverter::printInt(void)
{
	if (this->_isOverflow == TRUE)
		std::cout << "int: overflow\n";
	else
		std::cout << std::fixed << "int: " << this->_i << ".0\n";
}

void	ScalarConverter::printAll(void)
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////


void	ScalarConverter::fromChar(std::string const string)
{	
	this->_c = string[0];
	this->_i = static_cast<int>(this->_c);
	this->_d = static_cast<double>(this->_c);
	this->_f = static_cast<float>(this->_c);
	printAll();
}

void	ScalarConverter::fromDouble(std::string const string)
{
	std::istringstream	iss(string);
	char				*value = new char[string.length() + 1];

	std::strcpy(value, string.c_str());
	if (iss >> value)
	{
		this->_d = atof(value);
		this->_c = static_cast<char>(this->_d);
		if (this->_d < INT_MIN || this->_d > INT_MAX)
			this->_isOverflow = TRUE;
		else
			this->_i = static_cast<int>(this->_d);
		this->_f = static_cast<float>(this->_d);
		printAll();
		delete[] value;
	}
	else
	{
		delete[] value;
		throw(ParseFailException());
	}
}

void	ScalarConverter::fromFloat(std::string const string)
{
	std::istringstream	iss(string);
	char				*value = new char[string.length() + 1];

	std::strcpy(value, string.c_str());
	if (iss >> value)
	{
		this->_f = atof(value);
		this->_c = static_cast<char>(this->_f);
		this->_d = static_cast<double>(this->_f);
		if (this->_d < INT_MIN || this->_d > INT_MAX)
			this->_isOverflow = TRUE;
		else
			this->_i = static_cast<int>(this->_f);
		printAll();
		delete[] value;
	}
	else
	{
		delete[] value;
		throw(ParseFailException());
	}
}

void	ScalarConverter::fromInt(std::string const string)
{
	std::istringstream	iss(string);
	char				*value = new char[string.length() + 1];

	std::strcpy(value, string.c_str());
	if (iss >> value)
	{
		double tmp = static_cast<double>(atof(value));
		if (tmp < INT_MIN || tmp > INT_MAX)
			this->_isOverflow = TRUE;
		else
			this->_i = atoi(value);
		this->_c = static_cast<char>(tmp);
		this->_d = static_cast<double>(tmp);
		this->_f = static_cast<float>(tmp);
		printAll();
		delete[] value;
	}
	else
	{
		delete[] value;
		throw(ParseFailException());
	}
}

/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////

int	ScalarConverter::checkSign(std::string string)
{
	int cpt = 0;
	for (int i = 0; i < (int)string.size(); i++)
	{
		if (string[i] == '-' || string[i] == '+')
			cpt++;
		if (cpt > 1)
		{
			std::cerr << "Error: wrong scalar.\n";
			return (FALSE);
		}
	}
	return (TRUE);
}

int ScalarConverter::isWrongScalar(std::string string)
{
	int cptDot = 0;
	int	length = string.length();

	for (int i = 0; i < (int)string.size(); i++)
	{
		if (string[i] == '.')
		{
			cptDot++;
			if (cptDot > 1)
				return (TRUE);
		}
		else if (!(isdigit(string[i]) != 0 || string[i] == '-' || string[i] == '+'))
		{
			if (!(i == (length - 1) && isFloat(string, length) == TRUE))
				return (TRUE);
		}	
	}
	return (FALSE);
}

int	ScalarConverter::isDisplayable(std::string string)
{
	int status = FALSE;

	if (checkSign(string) == FALSE)
		std::cerr << "Error: not a scalar.\n";
	else if (string == "+inf" || string == "+inff")
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	else if (string == "-inf" || string == "-inff")
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	else if (string == "nan" || string == "nanf")
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
	else
		status = TRUE;
	return (status);
}

void	ScalarConverter::isImpossible(std::string string)
{
	(void) string;
	if (this->_type == IMPOSSIBLE)
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

int	ScalarConverter::isDouble(std::string string)
{
	if (string.find('.') != std::string::npos)
		return (TRUE);
	return (FALSE);
}

int	ScalarConverter::isFloat(std::string string, int length)
{
	if (length > 2 && string[length - 1] == 'f')
		return (TRUE);
	return (FALSE);
}

void	ScalarConverter::findType(std::string string)
{
	int	length = string.length();

	if (length == 0)
		this->_type = IMPOSSIBLE;
	else if (length == 1)
		this->_type = CHAR;
	else if (isWrongScalar(string) == TRUE)
	{
		std::cerr << "Error: not a scalar.\n";
		return  ;
	}
	else if (isFloat(string, length) == TRUE)
		this->_type = FLOAT;
	else if (isDouble(string) == TRUE)
		this->_type = DOUBLE;
	else
		this->_type = INT;
}

void	ScalarConverter::converter(std::string string)
{
	if (isDisplayable(string) == FALSE)
		return  ;

	findType(string);
	void	(ScalarConverter::*ptr[])(std::string) = {&ScalarConverter::fromChar, &ScalarConverter::fromDouble, &ScalarConverter::fromInt, &ScalarConverter::fromFloat, &ScalarConverter::isImpossible};
	int		inputType[] = {CHAR, DOUBLE, INT, FLOAT, IMPOSSIBLE};
	try
	{
		for (int i = 0; i < 5; i++)
		{
			if (this->_type == inputType[i])
				(this->*ptr[i])(string);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
}
