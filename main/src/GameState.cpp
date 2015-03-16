// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameState.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/07 16:22:30 by tlepetit          #+#    #+#             //
//   Updated: 2015/03/16 19:31:24 by rnicolas         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/GameState.hpp"
#include	<iostream>

GameState::GameState(void): _x(50), _y(50), _dir(UP), _lastDir(UP)
{
	this->_grid = std::vector<std::vector<int> >(50, std::vector<int>(50, 0));
	this->_grid[25][23] = 2;
	this->_grid[25][24] = 1;
	this->_grid[25][25] = 1;
	this->_grid[25][26] = 1;
	this->_snake = std::list<std::array<int, 2> >(4, std::array<int, 2>());
	std::list<std::array<int, 2> >::iterator it = this->_snake.begin();
	(*it)[0] = 25;
	(*it)[1] = 23;
	it++;
	(*it)[0] = 25;
	(*it)[1] = 24;
	it++;
	(*it)[0] = 25;
	(*it)[1] = 25;
	it++;
	(*it)[0] = 25;
	(*it)[1] = 26;
	this->_food = std::array<int, 2>();
	this->createFood();
}


GameState::GameState(int x, int y): _x(x), _y(y), _dir(UP), _lastDir(UP)
{
	this->_grid = std::vector<std::vector<int> >(x, std::vector<int>(y, 0));
	this->_grid[x/2][y/2 - 2] = 2;
	this->_grid[x/2][y/2 - 1] = 1;
	this->_grid[x/2][y/2] = 1;
	this->_grid[x/2][y/2 + 1] = 1;
	this->_snake = std::list<std::array<int, 2> >(4, std::array<int, 2>());
	std::list<std::array<int, 2> >::iterator it = this->_snake.begin();
	(*it)[0] = x/2;
	(*it)[1] = y/2 - 2;
	it++;
	(*it)[0] = x/2;
	(*it)[1] = y/2 - 1;
	it++;
	(*it)[0] = x/2;
	(*it)[1] = y/2;
	it++;
	(*it)[0] = x/2;
	(*it)[1] = y/2 + 1;
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
	this->_lastDir = rhs._lastDir;
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

int			GameState::getId(void) const
{
	return (this->_id);
}

std::vector<std::vector<int> >	GameState::getGrid(void) const
{
	return (this->_grid);
}

std::array<int, 2>		GameState::getFood(void) const
{
	return (this->_food);
}

GameState::dir			GameState::getDir(void) const
{
	return (this->_dir);
}

void				GameState::setDir(dir dir)
{
	this->_dir = dir;
}

GameState::dir			GameState::getLastDir(void) const
{
	return (this->_lastDir);
}

void				GameState::setLastDir(dir lastDir)
{
	this->_lastDir = lastDir;
}

void				GameState::setId(int id)
{
	this->_id = id;
}

void				GameState::createFood(void)
{
	int		size = this->_x * this->_y - this->_snake.size();
	int		pos = rand() % size;
	int		n = 0;
	int		i = 0;
	int		j = 0;

	while (this->_grid[i][j] != 0)
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
	this->_grid[i][j] = 3;
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
	if (next[0] < 0 || next[0] >= this->_x || next[1] < 0 || next[1] >= this->_y || this->_grid[next[0]][next[1]] == 1 || this->_grid[next[0]][next[1]] == 2)
	{
		if (!(this->_snake.back()[0] == next[0] && this->_snake.back()[1] ==next[1]))
			  return (1);
	}
	this->_grid[this->_snake.front()[0]][this->_snake.front()[1]] = 1;
	this->_snake.push_front(next);
	if (next[0] != this->_food[0] || next[1] != this->_food[1])
	{
		this->_grid[this->_snake.back()[0]][this->_snake.back()[1]] = 0;
		this->_snake.pop_back();
		this->_grid[this->_snake.front()[0]][this->_snake.front()[1]] = 2;
	}
	else
	{
		this->_grid[this->_snake.front()[0]][this->_snake.front()[1]] = 2;
		if (this->_snake.size() == static_cast<unsigned long>(this->_x * this->_y))
			return (2);
		this->createFood();
	}
	this->_lastDir = this->_dir;
	return(0);
}

void        GameState::display(void)
{
	std::cout << std::endl << "DISPLAY: " << std::endl;
    for (int i = 0; i < this->_y; ++i)
    {
        for (int j = 0; j < this->_x; j++)
        {
			std::cout << this->_grid[j][i] << " ";
        }
		std::cout << std::endl;
    }
	std::cout << "tlp:" << this->_x << " " << this->_y << std::endl;
}
