/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:45:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/02 17:45:10 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int	main(void)
{
	Data *data = new Data;
	Serialization	test;

	data->_i = 4;
	data->_d = 4.0;

	std::cout << "Before : i " << data->_i << " d " << data->_d << "\n";
	test.deserialize(test.serialize(data));
	std::cout << "After : i " << data->_i << " d " << data->_d << "\n";
	return (0);
}
