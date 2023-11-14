/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:39 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/14 11:43:01 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

// Constructor -----------------------------------------------------------------

ScalarConverter::ScalarConverter() : _i(0.0), _c(0), _d(0.0), _f(0.0f), _type(DEFAULT)
{
	// std::cout << "Scalar converter form target constructor called.\n";
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) : _i(src._i), _c(src._c), _d(src._d), _f(src._f), _type(src._type)
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
		std::cout << std::scientific << "double: " << this->_d << "\n";
	else
		std::cout << std::scientific << "double: " << this->_d << "\n";
}

void	ScalarConverter::printFloat(void)
{
	if (this->_f - this->_i != 0)
		std::cout << std::fixed << "float: " << this->_f << "f\n";
	else
		std::cout << std::fixed << "float: " << this->_f << "f\n";
}

int	ScalarConverter::checkIntOverflow(void)
{
	double tmp = static_cast<double>(this->_i);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (OVERFLOW);
	return (SUCCESS);
}

void	ScalarConverter::printInt(void)
{
	if (checkIntOverflow() == OVERFLOW)
		std::cout << "int: impossible\n";
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
		this->_d = strtod(value, NULL);
		this->_c = static_cast<char>(this->_d);
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
		this->_i = atoll(value);
		this->_c = static_cast<char>(this->_i);
		this->_d = static_cast<double>(this->_i);
		this->_f = static_cast<float>(this->_i);
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

int	ScalarConverter::isDisplayable(std::string string)
{
	int status = FALSE;

	if (checkSign(string) == FALSE)
		return (FALSE);

	if (string == "+inf" || string == "+inff")
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
	if (string[length - 1] == 'f')
		return (TRUE);
	return (FALSE);
}

void	ScalarConverter::findType(std::string string)
{
	int	length = string.length();

	if (length == 1)
	{
		std::cout << "IS CHAR !\n";
		this->_type = CHAR;
	}
	else if (isFloat(string, length) == TRUE)
	{
		std::cout << "IS FLOAT !\n";
		this->_type = FLOAT;
	}
	else if (isDouble(string) == TRUE)
	{
		std::cout << "IS DOUBLE !\n";
		this->_type = DOUBLE;
	}
	else
	{
		std::cout << "IS INT !\n";
		this->_type = INT;
	}
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
