// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   algo.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 17:07:21 by rnicolas          #+#    #+#             //
//   Updated: 2015/03/18 16:29:42 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <unistd.h>
#include "GameState.hpp"
#include "ILib.hpp"
#include "Lib.hpp"
#include <sys/time.h>

static long int	usecClock(struct timeval start, struct timeval end)
{
	long int		tot;

	tot = end.tv_sec - start.tv_sec;
	tot *= 1000000;
	tot += end.tv_usec - start.tv_usec;
	return (tot);
}

// La classe ILib est une interface qui permet d'avoir les memes methodes dans les librairie dynamique
// on a besoin de la methode int input(void) qui renvoie des events sous forme d'int,
// de la methode void display(Gamestate) qui affiche le plateau
// et la methode int id(void) qui indique dans quelle lib on est actuellement.

static void	treat_event(GameState  & game, Lib & lib)
{
	int	event;

	event = lib.getInput();
	if (event & QUIT)
	{
		lib.unloadLib();
		exit(0);
	}
	if ((event & 0b111) == KUP && game.getLastDir() != GameState::DOWN)
		game.setDir(GameState::UP);
	else if ((event & 0b111) == KRIGHT && game.getLastDir() != GameState::LEFT)
		game.setDir(GameState::RIGHT);
	else if ((event & 0b111) == KDOWN && game.getLastDir() != GameState::UP)
		game.setDir(GameState::DOWN);
	else if ((event & 0b111) == KLEFT && game.getLastDir() != GameState::RIGHT)
		game.setDir(GameState::LEFT);
	if ((event & 0b11000) == KF1 && lib.getCurrent() != Lib::ncurses)
	{
		lib.unloadLib();
		lib.loadLib(Lib::ncurses, game);
	}
	else if ((event & 0b11000) == KF2 &&lib.getCurrent() != Lib::SDL)
	{
		lib.unloadLib();
		lib.loadLib(Lib::SDL, game);
	}
	else if ((event & 0b11000) == KF3 && lib.getCurrent() != Lib::SFML)
	{
		lib.unloadLib();
		lib.loadLib(Lib::SFML, game);
	}
}

int		play(GameState & game, Lib & lib)
{
	int		ret;
	int		count_frame;
	struct timeval	start;
	struct timeval	end_loop;
	struct timeval	begin_loop;
	long int		duration;

	count_frame = 10;
	gettimeofday(&start, NULL);
	while (1)
	{
		//on recupere les touches, les deux bits les plus faibles c'est les touches directionelles (00 = UP, 01 = RIGHT, 10 = DOWN, 11 = LEFT)
		//les deux suivants c'est libs (00 = Ncurses, 01 = OpenGL, 10 = SFML, 11 = QT (si on le fait))
		//le suivant c'est escape (1 = on quitte, 0 on quitte pas)
		gettimeofday(&begin_loop, NULL);
		treat_event(game, lib);
		if (count_frame == 10)
		{
			ret = game.update();
			if (ret == 1)
			{
				std::cout << "Defeat" << std::endl;
				return(0);
			}
			if (ret == 2)
			{
				std::cout << "Victory" << std::endl;
				return(0);
			}
			count_frame = 0;
		}
		else
			count_frame++;
		lib.display(game);
		gettimeofday(&end_loop, NULL);
		duration = usecClock(begin_loop, end_loop);
		if (duration < FRAME)
			usleep(FRAME - duration);
	}
	return (0);
}
