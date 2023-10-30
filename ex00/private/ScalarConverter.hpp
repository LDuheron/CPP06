/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:37 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/30 17:44:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# define SUCCESS 0
# define ERROR 1

# include <climits>
# include <cfloat>
# include <iostream>
# include <sstream>
# include <stdio.h> 
# include <stdlib.h> 
# include <string>

class ScalarConverter
{
	private:
		
	public:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter();

		static void		converter(std::string string);
		static void		displayChar(std::string string);
		static void		displayDouble(std::string string);
		static void		displayFloat(std::string string);
		static void		displayInt(std::string string);
		static int		is_diplayable(std::string string);

		class ParseFailException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

		ScalarConverter	&operator=(ScalarConverter const &src);

};

#endif