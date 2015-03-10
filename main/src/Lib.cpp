// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lib.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/10 02:40:44 by gmangin                                  //
//                                                                            //
// ************************************************************************** //

#include	"../includes/Lib.hpp"
#include    <dlfcn.h>
#include    <iostream>

const char      graph[3][20] = { "./ncurses.so", "./opengl.so", "./autre.so" };

Lib::Lib(void) : _current(0)
{
	std::cout << "START LIB : " << graph[this->_current]  << std::endl;
}

Lib::~Lib(void)
{
	std::cout << "END LIB : " << graph[this->_current]  << std::endl;
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

// function generique pour les open dl (lib static)
void *  error_dl(const char * lib)
{
    void    *hand;

    hand = dlopen(lib, RTLD_NOW);
    if (hand == NULL)
        throw std::string(dlerror());
	return hand;
}

void	Lib::gameOver(void)
{
}

void    Lib::window(std::vector<std::vector<int> > grid, int x, int y)
{
    void    *hand;
    void    (*f)(std::vector<std::vector<int> >, int, int);

   try
   {
       hand = error_dl(graph[this->_current]);
   }
   catch(std::string const& chaine)
   {
       throw std::string(chaine);
   }

   f = reinterpret_cast<void (*)(std::vector<std::vector<int> >, int, int)>(dlsym(hand, "display"));
   f(grid, x, y);
   dlclose(hand);
}

void	Lib::chooseLib(int i)
{
	std::cout << "CHANGE LIB from " << graph[this->_current];
	this->_current = i;
	std::cout << " to : " << graph[this->_current]  << std::endl;
}

void	Lib::getInput(void)
{
//recup 
}
