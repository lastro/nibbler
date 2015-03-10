// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   GameState.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/07 16:23:11 by tlepetit          #+#    #+#             //
//   Updated: 2015/03/10 19:25:01 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef GAMESTATE_HPP
# define GAMESTATE_HPP

# include <list>
# include <vector>
# include <array>
# include <stdlib.h>
# define KUP	0b0
# define KRIGHT	0b1
# define KDOWN	0b10
# define KLEFT	0b11
# define KF1	0b0100
# define KF2	0b1000
# define KF3	0b1100
# define QUIT	0b10000

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
	void	setDir(dir & dir);
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
