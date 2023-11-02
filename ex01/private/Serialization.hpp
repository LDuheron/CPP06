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

struct Data
{
	int		_i;
	double	_d;
};

class Serialization
{
	private:
		Data *_data;

	public:
		Serialization();
		Serialization(Serialization const & src);
		~Serialization();

		int		&getI(void) const;
		double	&getD(void) const;

		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);

		Serialization &	operator=(Serialization const & rhs);

};

std::ostream & operator<<(std::ostream & lhs, Serialization const & rhs);

#endif
