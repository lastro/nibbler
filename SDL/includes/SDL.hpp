// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SDL.hpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tlepetit <tlepetit@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/09 14:55:48 by tlepetit          #+#    #+#             //
//   Updated: 2015/03/11 19:41:57 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SDL_HPP
# define SDL_HPP

# include <SDL.h>
# include <iostream>
# include <SDL_image.h>
# include "ILib.hpp"
# include <vector>
# include "GameState.hpp"

class	SDLLib: public ILib
{
public:
	SDLLib(void);
	~SDLLib(void);
	SDLLib(SDLLib const & src);
	SDLLib &	operator=(SDLLib const & rhs);
	bool		init(int x, int y);
	int			input(void);
	SDL_Window	*getWindow(void) const;
	SDL_Renderer	*getRenderer(void) const;
	void		setWindow(SDL_Window *window);
	void		setRenderer(SDL_Renderer *renderer);
	void		display(int x, int y, std::vector<std::vector<int> > grid);

private:
	SDL_Window	*_window;
	SDL_Renderer	*_renderer;
};

#endif
