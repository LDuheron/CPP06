/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Methods.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:08:29 by lduheron          #+#    #+#             */
/*   Updated: 2023/11/03 12:14:01 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METHODS_HPP
# define METHODS_HPP

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base;

Base *	generate(void);
void	identify(Base* p);
void 	identify(Base& p);

#endif
