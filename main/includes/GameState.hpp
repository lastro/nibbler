// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameState.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/07 16:23:11 by tlepetit          #+#    #+#             //
//   Updated: 2015/03/10 18:04:35 by rnicolas         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMESTATE_HPP
# define GAMESTATE_HPP

# include <list>
# include <vector>
# include <array>
# include <stdlib.h>

class	GameState
{
public:
	GameState(void);
	GameState(int x, int y);
	~GameState(void);
	GameState(GameState const & src);
	GameState &	operator=(GameState const & rhs);
	enum	dir {UP, RIGHT, DOWN, LEFT};
	int		getX(void) const;
	int		getY(void) const;
	std::vector<std::vector<int> >		getGrid(void) const;
	std::array<int, 2>		getFood(void) const;
	void	setDir(dir dir);
	void	createFood(void);
	int		update(void);
	void	display(void);

private:
	int		_x;
	int		_y;
	std::list<std::array<int, 2> >		_snake;
	std::vector<std::vector<int> >	_grid;
	dir		_dir;
	std::array<int, 2>	_food;
};

#endif
