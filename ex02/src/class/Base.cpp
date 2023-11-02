/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:12:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:30 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
# include <stdlib.h>

// Constructor -----------------------------------------------------------------

Base::Base()
{
	if (DEBUG)
		std::cout << "Base default constructor called.\n";
}

// Destructor ------------------------------------------------------------------

Base::~Base()
{
	if (DEBUG)
		std::cout << "Base destructor called.\n";
}

// Accessors -------------------------------------------------------------------

// Overload --------------------------------------------------------------------

// Functions -------------------------------------------------------------------

Base * Base::generate(void)
{
	int r = rand();

	if (r % 3 == 0)
		return (new A);
	else if (r % 2 == 0)
		return (new B);
	return (new C);
}
