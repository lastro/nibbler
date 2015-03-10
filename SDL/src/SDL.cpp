// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SDL.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/09 14:55:12 by tlepetit          #+#    #+#             //
//   Updated: 2015/03/10 20:01:41 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "SDL.hpp"

SDLLib::SDLLib(void): _window(NULL), _renderer(NULL)
{
}

SDLLib::~SDLLib(void)
{
}

SDLLib::SDLLib(SDLLib const & src)
{
	*this = src;
}

SDL_Window	*SDLLib::getWindow(void) const
{
	return (this->_window);
}

SDL_Renderer	*SDLLib::getRenderer(void) const
{
	return (this->_renderer);
}

void			SDLLib::setWindow(SDL_Window *window)
{
	this->_window = window;
}

void			SDLLib::setRenderer(SDL_Renderer *renderer)
{
	this->_renderer = renderer;
}

SDLLib &	SDLLib::operator=(SDLLib const & rhs)
{
	(void)rhs;
	return (*this);
}

extern "C" SDLLib	*init(GameState const & game)
{
	SDLLib	*lib = new SDLLib;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		delete (lib);
		return (NULL);
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	lib->setWindow(SDL_CreateWindow("nibbler", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 10 * game.getX(), 10 * game.getY(), SDL_WINDOW_SHOWN));
	if (lib->getWindow() == NULL)
	{
		std::cout << "erreur de creation de fenetre SDL: " << SDL_GetError() << std::endl;
		delete (lib);
		return (NULL);
	}
	lib->setRenderer(SDL_CreateRenderer(lib->getWindow(), -1, SDL_RENDERER_ACCELERATED));
	if (lib->getRenderer() == NULL)
	{
		std::cout << "erreur de renderer SDL: " << SDL_GetError() << std::endl;
		delete (lib);
		return (NULL);
	}
	SDL_SetRenderDrawColor(lib->getRenderer(), 0xff, 0xff, 0xff, 0xff);
	int	flag = IMG_INIT_PNG;
	if (!(IMG_Init(flag) & flag))
	{
		std::cout << "erreur init SDL_image: " << IMG_GetError() << std::endl;
		delete (lib);
		return (NULL);
	}
	return (lib);
}

extern "C" void		close(SDLLib *lib)
{
	SDL_DestroyRenderer(lib->getRenderer());
	SDL_DestroyWindow(lib->getWindow());
	IMG_Quit();
	SDL_Quit();
	delete (lib);
}

int			SDLLib::input(void)
{
	int		flag = 0;
	SDL_Event	e;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			flag = flag | QUIT;
		if (e.type == SDLK_DOWN)
		{
			switch (e.key.keysym.sym)
			{
				case SDLK_UP:
				flag = (flag & ~3) | KUP;
				break ;
				case SDLK_RIGHT:
				flag = (flag & ~3) | KRIGHT;
				break ;
				case SDLK_DOWN:
				flag = (flag & ~3) | KDOWN;
				break ;
				case SDLK_LEFT:
				flag = (flag & ~3) | KLEFT;
				break ;
				case SDLK_F1:
				flag = (flag & ~12) | KF1;
				break ;
				case SDLK_F2:
				flag = (flag & ~12) | KF2;
				break ;
				case SDLK_F3:
				flag = (flag & ~12) | KF3;
				break ;
			} 
		}
	}
	return (flag);
}

void		SDLLib::display(GameState const & game)
{
	(void)game;
}
