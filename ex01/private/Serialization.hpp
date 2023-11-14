/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:12:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/10/27 15:37:58 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <limits.h>
# include <stdint.h>

#define DEBUG 0

#define SUCCESS 0
#define ERROR 1

// uintptr_t : unsigned integer type that is capable of storing a pointer.

struct Data
{
	int		_i;
	double	_d;
};

class Serialization
{
	private:

	public:
		Serialization();
		Serialization(Serialization const & src);
		~Serialization();

		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);

		Serialization &	operator=(Serialization const & rhs);

};

#endif
