// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameState.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/07 16:22:30 by tlepetit          #+#    #+#             //
//   Updated: 2015/03/07 17:59:58 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "GameState.hpp"

GameState::GameState(void): _x(50), _y(50), _dir(UP)
{
	this->_grid = std::vector<std::vector<int> >(50, std::vector<int>(50, 0));
	this->_grid[25][25] = 1;
	this->_grid[25][26] = 1;
	this->_grid[25][27] = 1;
	this->_grid[25][28] = 1;
	this->_snake = std::list<std::array<int, 2> >(4, std::array<int, 2>());
	std::list<std::array<int, 2> >::iterator it = this->_snake.begin();
	(*it)[0] = 25;
	(*it)[1] = 25;
	it++;
	(*it)[0] = 25;
	(*it)[1] = 26;
	it++;
	(*it)[0] = 25;
	(*it)[1] = 27;
	it++;
	(*it)[0] = 25;
	(*it)[1] = 28;
	this->_food = std::array<int, 2>();
	this->createFood();
}


GameState::GameState(int x, int y): _x(x), _y(y), _dir(UP)
{
	this->_grid = std::vector<std::vector<int> >(x, std::vector<int>(y, 0));
	this->_grid[x/2][y/2] = 1;
	this->_grid[x/2][y/2 + 1] = 1;
	this->_grid[x/2][y/2 + 2] = 1;
	this->_grid[x/2][y/2 + 3] = 1;
	this->_snake = std::list<std::array<int, 2> >(4, std::array<int, 2>());
	std::list<std::array<int, 2> >::iterator it = this->_snake.begin();
	(*it)[0] = x/2;
	(*it)[1] = y/2;
	it++;
	(*it)[0] = x/2;
	(*it)[1] = y/2 + 1;
	it++;
	(*it)[0] = x/2;
	(*it)[1] = y/2 + 2;
	it++;
	(*it)[0] = x/2;
	(*it)[1] = y/2 + 3;
	this->_food = std::array<int, 2>();
	this->createFood();
}

GameState::~GameState(void)
{
}

GameState::GameState(GameState const & src)
{
	*this = src;
}

GameState & GameState::operator=(GameState const & rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_snake = rhs._snake;
	this->_grid = rhs._grid;
	this->_dir = rhs._dir;
	return (*this);
}

int			GameState::getX(void) const
{
	return (this->_x);
}

int			GameState::getY(void) const
{
	return (this->_y);
}

std::vector<std::vector<int> >	GameState::getGrid(void) const
{
	return (this->_grid);
}

std::array<int, 2>		GameState::getFood(void) const
{
	return (this->_food);
}

void				GameState::setDir(dir & dir)
{
	this->_dir = dir;
}

void				GameState::createFood(void)
{
	int		size = this->_x * this->_y - this->_snake.size();
	int		pos = rand() % size;
	int		n = 0;
	int		i = 0;
	int		j = 0;

	while (this->_grid[i][j] == 0)
	{
		i++;
		if (i >= this->_x)
		{
			i = 0;
			j++;
		}
	}
	while (n < pos)
	{
		i++;
		if (i >= this->_x)
		{
			i = 0;
			j++;
		}
		if (this->_grid[i][j] == 0)
			n++;
	}
	this->_food[0] = i;
	this->_food[1] = j;
}
