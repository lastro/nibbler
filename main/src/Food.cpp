// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Food.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 13:56:55 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/Food.hpp"
#include	<iostream>

Food::Food(void)
{
}

Food::~Food(void)
{
}

Food::Food(Food const & src)
{
	*this = src;
}

Food &	Food::operator=(Food const & rhs)
{
	return *this;
}

void		Food::display(void)
{
	std::cout << "future display of the food" << std::endl;
}

