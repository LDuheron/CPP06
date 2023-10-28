/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:37 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/28 16:37:06 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <string>
# include <cfloat>

class ScalarConverter
{
	private:
		
	public:
		ScalarConverter();
		~ScalarConverter();

		int	is_diplayable(std::string string);
		static void	ScalarConverter::converter(std::string string);
	
		ScalarConverter	&operator=(ScalarConverter const &src);

};

#endif