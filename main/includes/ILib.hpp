// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ILib.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 19:43:13 by rnicolas          #+#    #+#             //
//   Updated: 2015/03/11 17:52:54 by rnicolas         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ILIB_HPP
# define ILIB_HPP

#include "GameState.hpp"

class ILib
{
public:
	virtual ~ILib(void) {}

	virtual void	display(GameState game) = 0;
	virtual int		input(void) = 0;
	virtual	int		id(void) = 0;
};

#endif
