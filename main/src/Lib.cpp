// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lib.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/16 19:00:29 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/Lib.hpp"
#include    <iostream>
#include <dlfcn.h>

const char      Lib::libs[3][20] = { "./ncurses.dylib", "SDL.dylib", "./SFML.dylib" };

Lib::Lib(void)
{
	this->_current = none;
}

Lib::Lib(GameState const & game)
{
	this->loadLib(SFML, game);
}

Lib::~Lib(void)
{
}

Lib::Lib(Lib const & src)
{
	*this = src;
}

Lib &	Lib::operator=(Lib const & rhs)
{
  (void)rhs;
	return *this;
}

Lib::id	Lib::getCurrent(void) const
{
	return (this->_current);
}

int		Lib::getInput(void)
{
	return (this->_lib->input());
}

void	Lib::display(GameState const & game)
{
	this->_lib->display(game.getX(), game.getY(), game.getGrid());
}

void	Lib::loadLib(id myid, GameState const & game)
{
	ILib	*(*create_lib)(int, int);

	this->_hand = dlopen(libs[myid], RTLD_NOW);
	if (this->_hand == 0)
	{
		throw (Lib::loadLibException());
	}
	this->_current = myid;
	create_lib = reinterpret_cast<ILib *(*)(int, int)>(dlsym(this->_hand, "init"));
	if (create_lib == NULL)
		throw (Lib::loadLibException());
	this->_lib = create_lib(game.getX(), game.getY());
}

void	Lib::unloadLib(void)
{
	void	(*delete_lib)(ILib *);

	delete_lib = reinterpret_cast<void (*)(ILib *)>(dlsym(this->_hand, "close"));
	if (delete_lib == NULL)
		throw (Lib::loadLibException());
	delete_lib(this->_lib);
	this->_lib = NULL;
	this->_current = none;
}
