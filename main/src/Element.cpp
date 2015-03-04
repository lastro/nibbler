// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Element.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 21:13:01 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/Element.hpp"
#include	<iostream>
#include    <cstdlib>
#include    <ctime>

Element::Element(void) : _x(SIZE_X), _y(SIZE_Y), _life(3)
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

int			Element::get_life(void)
{
	return this->_life;
}

void		Element::set_life(int life)
{
	this->_life = life;
}

void		Element::display(std::vector< std::vector <int > > &map)
{
    for (int i = 0; i < this->_y; ++i)
    {
		for (int j = 0; j < this->_x; j++)
		{
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
    }
}

// partie INIT du snake sur la map a un endroit random (map rempli
// de 1 TETE et 1 QUEUE), le snake fait au debut 2 cases du tableau
void		Element::init_snake(std::vector< std::vector <int > > &map)
{
    int i;
    int j;

    // je place la tete de maniere random
    i = std::rand() % (this->_y - 4) + 1;
    j = std::rand() % (this->_x - 2) + 1;
	std::cout << i << " " << j << std::endl;
    map[i][j] = 1;
    // puis je place la queue derriere :)
    map[i - 1][j] = 2;
}

// partie INIT de la map (double tableau rempli de 0 == empty)
void		Element::init_map(std::vector< std::vector <int > > &map)
{
    map.resize(this->_y);
    for (int i = 0; i < this->_y; ++i)
    {
		map[i].resize(this->_x);
		for (int j = 0; j < this->_x; j++)
		{
            map[i][j] = 0;
		}
    }
}
