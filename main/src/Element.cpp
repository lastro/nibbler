// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Element.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 17:52:58 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/Element.hpp"
#include	<iostream>

Element::Element(void) : _x(SIZE_X), _y(SIZE_Y)
{
}

Element::Element(int x, int y) : _x(x), _y(y)
{
}

Element::~Element(void)
{
}

Element::Element(Element const & src)
{
	*this = src;
}

Element &	Element::operator=(Element const & rhs)
{
	return *this;
}

void		Element::display(void)
{
	std::cout << "future display" << std::endl;
}

int			Element::get_x(void)
{
	return this->_x;
}

void		Element::set_x(int x)
{
	this->_x = x;
}

int			Element::get_y(void)
{
	return this->_y;
}

void		Element::set_y(int y)
{
	this->_y = y;
}

