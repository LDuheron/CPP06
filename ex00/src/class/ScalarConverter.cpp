/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:39 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/30 17:47:31 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructor -----------------------------------------------------------------

ScalarConverter::ScalarConverter()
{
	// std::cout << "Scalar converter form target constructor called.\n";
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void)src;
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
	(void)src;
	return (*this);
}

// Exceptions ------------------------------------------------------------------

const char* ScalarConverter::ParseFailException::what() const throw()
{
	return ("Isstream failed to parse.\n");
}

// Functions -------------------------------------------------------------------

// IS_DISPLAYABLE : This function returns 1 if the string is displayable, else 0.
int	ScalarConverter::is_diplayable(std::string string)
{
	int status = 0;

	if (string == "+inf" || string == "+inff")
		std::cout<< "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	else if (string == "-inf" || string == "-inff")
		std::cout<< "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
	else if (string == "nan" || string == "nanf")
		std::cout<< "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
	else
		status = 1; // displayable
	return (status);
}

void	ScalarConverter::displayChar(std::string string)
{
	std::istringstream	iss(string);
	char				value;

	if (iss >> value)
	{
		if (value >= 32 && value <= 122)
			std::cout << "char: " << value << "\n";
		else if (value >= 0 && value <= 126)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: impossible\n";
	}
	else
		throw(ParseFailException());
	// handle overflow and negative value.
	// isalpha ???
}

void	ScalarConverter::displayDouble(std::string string)
{
	std::istringstream	iss(string);
	double				value;

	if (iss >> value)
	{
		if (value < DBL_MIN || value > DBL_MAX)
			std::cout << "Double: impossible\n";
		else
			std::cout << "Double: "<< value << "\n";
	}
	else
		throw(ParseFailException());
}

void	ScalarConverter::displayFloat(std::string string)
{
	std::istringstream	iss(string);
	float				value;

	if (iss >> value)
	{
		if (value < FLT_MIN || value > FLT_MAX)
			std::cout << "Float: impossible\n";
		else
			std::cout << "Float: "<< value << "\n";
	}
	else
		throw(ParseFailException());
}

void	ScalarConverter::displayInt(std::string string)
{
	std::istringstream	iss(string);
	int					value;

	if (iss >> value)
	{
		if (value < INT_MIN || value > INT_MAX)
			std::cout << "int: impossible\n";
		else
			std::cout << "int: "<< value << "\n";
	}
	else
		throw(ParseFailException());	
}



void	ScalarConverter::converter(std::string string)
{
	if (is_diplayable(string) == 0)
		return ;
	try
	{
		displayChar(string);
		displayDouble(string);
		displayFloat(string);
		displayInt(string);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// find f for float
}

// strtod