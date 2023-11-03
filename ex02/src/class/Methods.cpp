/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Methods.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/03 12:14:05 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Methods.hpp"

Base * generate(void)
{
	int r = rand();

	if (r % 3 == 0)
		return (new A);
	else if (r % 2 == 0)
		return (new B);
	return (new C);
}


// void	identify(Base* p);
// void 	identify(Base& p);
