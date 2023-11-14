/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Methods.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/14 15:58:42 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Methods.hpp"

Base * generate(void)
{
	int r = rand();

	if (r % 3 == 0)
	{
		std::cout << "Class type : A\n";
		return (new A);
	}
	else if (r % 2 == 0)
	{	
		std::cout << "Class type : B\n";
		return (new B);
	}
	std::cout << "Class type : C\n";
	return (new C);
}

void	identify(Base* p)
{
	identify(*p);
}

void 	identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Class type : A\n";
	}
	catch (const std::exception& e) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Class type : B\n";
	}
	catch (const std::exception& e) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Class type : C\n";
	}
	catch (const std::exception& e) {}
}
