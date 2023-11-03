/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:47:39 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/03 12:04:18 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void);
void	identify(Base* p);
void 	identify(Base& p);

Base * Base::generate(void)
{
	int r = rand();

	if (r % 3 == 0)
		return (new A);
	else if (r % 2 == 0)
		return (new B);
	return (new C);
}


int main()
{
	Base base;

	return (SUCCESS);
}
