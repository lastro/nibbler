// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ILib.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 19:43:13 by rnicolas          #+#    #+#             //
//   Updated: 2015/03/11 19:33:11 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ILIB_HPP
# define ILIB_HPP

#include <vector>

class ILib
{
public:
	virtual ~ILib(void) {}

	virtual void	display(int x, int y, std::vector<std::vector<int> > grid) = 0;
	virtual int		input(void) = 0;
//	virtual	int		id(void) = 0;
};

#endif
