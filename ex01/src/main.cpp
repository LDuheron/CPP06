/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:45:47 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/02 15:26:27 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int	main(void)
{
	// Data *data = new data;
	Serialization test;

	std::cout << test;
	test.serialize();
	test.deserialize();
	std::cout << test;
	return (0);
}