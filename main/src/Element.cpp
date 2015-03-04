// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Element.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 13:52:06 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/Element.hpp"
#include	<iostream>

Element::Element(void)
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

#endif		/* ELEMENT_HPP */ 
