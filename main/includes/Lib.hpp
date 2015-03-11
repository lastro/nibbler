// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lib.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/11 19:23:35 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		LIB_HPP
# define	LIB_HPP

# include	<vector>
# include "GameState.hpp"
# include "ILib.hpp"
# include <dlfcn.h>

class		Lib
{
public:
	Lib(void);
	Lib(GameState const & game);
	~Lib(void);
	Lib(Lib const & src);

	Lib &	operator=(Lib const & rhs);

	int		getInput(void);
	void	display(GameState const & game);

	enum	id {none = -1, ncurses, SDL, SFML};

	void	loadLib(id myid, GameState const & game);
	void	unloadLib(void);

	static const	char libs[3][20];
	class loadLibException: public std::exception {
		const char *what(void) const throw () { return dlerror() ;}
	};

private:
	id		_current;
	void	*_hand;
	ILib	*_lib;
};

#endif		/* LIB_HPP */ 
