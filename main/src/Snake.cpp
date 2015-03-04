// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Snake.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 13:54:49 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/Snake.hpp"
#include	<iostream>

Snake::Snake(void)
{
}

Snake::~Snake(void)
{
}

Snake::Snake(Snake const & src)
{
	*this = src;
}

Snake &	Snake::operator=(Snake const & rhs)
{
	return *this;
}

void		Snake::display(void)
{
	std::cout << "future display of the snake" << std::endl;
}

