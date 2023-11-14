/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:37 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/14 13:43:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# define SUCCESS 0
# define ERROR 1

# define FALSE 0
# define TRUE 1

# include <climits>
# include <cfloat>
# include <iostream>
# include <sstream>
# include <stdio.h> 
# include <stdlib.h> 
# include <string>
# include <cstring>
#include <iostream>
#include <fstream>
#include <limits>
#include <iomanip>

#define INT 0
#define CHAR 1
#define DOUBLE 2
#define FLOAT 3
#define DEFAULT 4
#define IMPOSSIBLE 5
#define OVERFLOW 6

class ScalarConverter
{
	private:
		int 		_i;
		char		_c;
		double		_d;
		float		_f;
		int			_type;
		bool		_isOverflow;
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();

		void		converter(std::string string);

		void		printChar(void);
		void		printDouble(void);
		void		printFloat(void);
		void		printInt(void);
		void		printAll(void);

		void		fromChar(std::string const string);
		void		fromDouble(std::string const string);
		void		fromFloat(std::string const string);
		void		fromInt(std::string const string);

		int			checkIntOverflow(void);
		int			checkSign(std::string string);

		int			isDouble(std::string string);
		int			isFloat(std::string string, int length);

		int			isDisplayable(std::string string);
		void		isImpossible(std::string string);

		int 		isWrongScalar(std::string string);


		void		findType(std::string string);

		class ParseFailException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

		ScalarConverter	&operator=(ScalarConverter const &src);
};

#endif