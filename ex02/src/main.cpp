/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:47:39 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/03 12:42:29 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Methods.hpp"

int main(void)
{
	{
		Base* test = generate();
		
		identify(test);
		identify(*test);
		delete test;
		std::cout << "\n";
	}

	{
		Base* test = generate();
		
		identify(test);
		identify(*test);
		delete test;
		std::cout << "\n";
	}

	{
		Base* test = generate();
		
		identify(test);
		identify(*test);
		delete test;
		std::cout << "\n";
	}
		{
		Base* test = generate();
		
		identify(test);
		identify(*test);
		delete test;
		std::cout << "\n";
	}

	{
		Base* test = generate();
		
		identify(test);
		identify(*test);
		delete test;
		std::cout << "\n";
	}

	{
		Base* test = generate();
		
		identify(test);
		identify(*test);
		delete test;
		std::cout << "\n";
	}


	return (SUCCESS);
}
