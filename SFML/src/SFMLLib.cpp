// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SFMLLib.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/16 16:41:30 by rnicolas          #+#    #+#             //
//   Updated: 2015/03/18 15:35:39 by rnicolas         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <SFML/graphics.hpp>
#include "SFMLLib.hpp"
#include "Gamestate.hpp"

SFMLLib::SFMLLib(int x, int y): _window(sf::VideoMode(20 * x, 20 * y), "nibbler")
{
}

SFMLLib::~SFMLLib()
{
}

void	SFMLLib::display(int x, int y, std::vector<std::vector<int> > grid)
{
	int					i, j;
	sf::CircleShape		circle = sf::CircleShape(10, 50);

	this->_window.clear(sf::Color::Black);
	for (i = 0;i < x;i++)
	for (j = 0;j < y;j++)
	{
		if (grid[i][j] == 1)
			circle.setFillColor(sf::Color(0, 127, 0, 255));
		else if (grid[i][j] == 2)
			circle.setFillColor(sf::Color(0, 255, 0, 255));
		else if (grid[i][j] == 3)
			circle.setFillColor(sf::Color(255, 0, 0, 255));
		if (grid[i][j] != 0)
		{
			circle.setPosition(20 * i, 20 * j);
			this->_window.draw(circle);
		}
	}
	this->_window.display();
}

int		SFMLLib::input(void)
{
	int			ret;
	sf::Event	e;

	ret = 0;
	while (this->_window.pollEvent(e))
	{
		if (e.type == sf::Event::Closed)
			ret = ret | QUIT;
		if (e.type == sf::Event::KeyPressed)
		{
			switch (e.key.code)
			{
				case sf::Keyboard::Up:
				ret = (ret & ~0b111) | KUP;
				break ;
				case sf::Keyboard::Right:
				ret = (ret & ~0b111) | KRIGHT;
				break ;
				case sf::Keyboard::Down:
				ret = (ret & ~0b111) | KDOWN;
				break ;
				case sf::Keyboard::Left:
				ret = (ret & ~0b111) | KLEFT;
				break ;
				case sf::Keyboard::F1:
				ret = (ret & ~0b11000) | KF1;
				break ;
				case sf::Keyboard::F2:
				ret = (ret & ~0b11000) | KF2;
				break ;
				case sf::Keyboard::F3:
				ret = (ret & ~0b11000) | KF3;
				break ;
				default:
				break ;
			} 
		}
	}
	return (ret);
}


void	SFMLLib::closeWindow(void)
{
	this->_window.clear();
	this->_window.close();
}

extern "C" ILib		*init(int x, int y)
{
	return (new SFMLLib(x, y));
}

extern "C" void		close(ILib *lib)
{
	SFMLLib		*sfmllib = dynamic_cast<SFMLLib *>(lib);

	sfmllib->closeWindow();
	delete (sfmllib);
}
