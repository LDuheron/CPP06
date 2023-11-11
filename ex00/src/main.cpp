/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/11 11:10:14 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage is ./ScalarConverter <scalar_number>\n";
		return (ERROR);
	}
	std::cout << "int max : " << INT_MAX << "\nDOUBLE MAX : " << DBL_MAX << "\nINT_MAX : " << FLT_MAX << "\n\n";

	ScalarConverter	sConverter;
	sConverter.converter(argv[1]);

	return (SUCCESS);
}
