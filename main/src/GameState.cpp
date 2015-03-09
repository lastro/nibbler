// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameState.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/07 16:22:30 by tlepetit          #+#    #+#             //
//   Updated: 2015/03/09 16:40:02 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/GameState.hpp"
#include	<iostream>

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

int					GameState::update(void)
{
	std::array<int, 2>	next = this->_snake.front();

	if (this->_dir == UP)
		next[1]--;
	if (this->_dir == RIGHT)
		next[0]++;
	if (this->_dir == DOWN)
		next[1]++;
	if (this->_dir == LEFT)
		next[0]--;
	if (next[0] < 0 || next[0] >= this->_x || next[1] < 0 || next[1] >= this->_y || this->_grid[next[0]][next[1]])
		return (1);
	this->_snake.push_front(next);
	if (next[0] != this->_food[0] || next[1] != this->_food[1])
		this->_snake.pop_back();
	else
	{
		if (this->_snake.size() == static_cast<unsigned long>(this->_x * this->_y))
			return (2);
		this->createFood();
	}
	return(0);
}

void        GameState::display(void)
{
	std::cout << std::endl << "DISPLAY: " << std::endl;
    for (int i = 0; i < this->_y; ++i)
    {
        for (int j = 0; j < this->_x; j++)
        {
			std::cout << this->_grid[i][j] << " ";
        }
		std::cout << std::endl;
    }
}
