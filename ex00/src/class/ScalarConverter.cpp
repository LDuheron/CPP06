/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:39 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/28 16:40:22 by lduheron         ###   ########.fr       */
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
	return (*this);
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

void	ScalarConverter::converter(std::string string)
{
	if (is_diplayable == 0)
		return ;

	char	c;
	int		i;
	float	f;
	double	d;

	if (c < 32 || c == 126)
		std::cout<< "char: Non displayable\n";
}

// strtod
// atof