/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:40:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/30 16:37:28 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage is ./ScalarConverter <scalar_number>\n";
		return (ERROR);
	}

	ScalarConverter	sConverter;
	sConverter.converter(argv[1]);

	return (SUCCESS);
}
