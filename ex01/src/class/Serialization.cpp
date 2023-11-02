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
	this->_data->_i = 0;
	this->_data->_d = 0;
	if (DEBUG)
		std::cout << "Default constructor called.\n";
}

Serialization::Serialization(Serialization const & src)
{
	this->_data->_i = src._data->_i;
	this->_data->_d = src._data->_d;
	if (DEBUG)
		std::cout << "Copy constructor called.\n";
}

// Destructor ------------------------------------------------------------------

Serialization::~Serialization()
{
	if (DEBUG)
		std::cout << "Destructor called.\n";
}

// Accessors -------------------------------------------------------------------

int	& Serialization::getI(void) const
{
	return (this->_data->_i);
}

double	& Serialization::getD(void) const
{
	return (this->_data->_d);
}

// Overload --------------------------------------------------------------------

Serialization &	Serialization::operator=(Serialization const & rhs)
{
	this->_data = rhs._data;
	return *this;
}

std::ostream & operator<<(std::ostream & lhs, Serialization const & rhs)
{
	lhs << "i : " << rhs.getI() << "\nd : " << rhs.getD()<< ".\n";
	return lhs;
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
