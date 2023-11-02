/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:12:32 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:30 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

// Constructor -----------------------------------------------------------------

Serialization::Serialization()
{
	if (DEBUG)
		std::cout << "Default constructor called.\n";
}

Serialization::Serialization(Serialization const & src)
{
	(void)src;
	if (DEBUG)
		std::cout << "Copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

Serialization::~Serialization()
{
	if (DEBUG)
		std::cout << "Destructor called.\n";
}

// Overload --------------------------------------------------------------------

Serialization &	Serialization::operator=(Serialization const & rhs)
{
	(void)rhs;
	return *this;
}

// Functions -------------------------------------------------------------------

uintptr_t Serialization::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
