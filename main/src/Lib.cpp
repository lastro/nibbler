// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lib.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 21:11:57 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/Lib.hpp"
#include    <dlfcn.h>
#include    <iostream>

Lib::Lib(void)
{
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
	std::cout << "!!! PERDU !!! " << std::endl;
}

void    Lib::window(int argc, char **argv)
{
    void    *hand;
    void    (*f)(int, int);

   try
   {
       hand = error_dl("./lib.so");
   }
   catch(std::string const& chaine)
   {
       throw std::string(chaine);
   }
   f = reinterpret_cast<void (*)(int, int)>(dlsym(hand, "window_size"));
   if (argc == 3)
	   f(std::atoi(argv[1]), std::atoi(argv[2]));
   else
	   f(0, 0);
   dlclose(hand);
}
