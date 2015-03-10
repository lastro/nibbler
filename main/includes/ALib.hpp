// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ALib.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 19:43:13 by rnicolas          #+#    #+#             //
//   Updated: 2015/03/10 19:46:56 by rnicolas         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ALIB_HPP
# define ALIB_HPP

#include "GameState.hpp"

class ALib
{
public:
	virtual ~AFoo(void) {}

	virtual void	display(GameState game) = 0;
	virtual int		input(void) = 0;
	virtual	int		id(void) = 0;
};

#endif
