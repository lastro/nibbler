// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   algo.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/10 17:07:21 by rnicolas          #+#    #+#             //
//   Updated: 2015/03/10 17:38:30 by rnicolas         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include "../includes/GameState.hpp"
#include "../includes/ALib.hpp"

// La classe ALib est une interface qui permet d'avoir les memes methodes dans les librairie dynamique
// on a besoin de la methode int input(void) qui renvoie des events sous forme d'int,
// de la methode void display(Gamestate) qui affiche le plateau
// et la methode int id(void) qui indique dans quelle lib on est actuellement.

void	treat_event(int event, GameState game, ALib *lib)
{
	if ((event & 0b11) == KUP)
		game.setDir(GameState::UP)
	else if ((event & 0b11) == KRIGHT)
		game.setDir(GameState::RIGHT)
	else if ((event & 0b11) == KDOWN)
		game.setDir(GameState::DOWN)
	else if ((event & 0b11) == KLEFT)
		game.setDir(GameState::LEFT)
	if ((event & 0b1100) == KF1 && lib.id() != 0)// si on demande ncurses et que c'est pas ncurses
		;//decharge la lib actuelle et charge ncurses
	else if ((event & 0b1100) == KF2 &&lib.id() != 1)// openGL
		;
	else if ((event & 0b1100) == KF3 && lib.id() != 2)// SFML
		;
//	else if ((event & 0b1100) == KF4 && lib.id() != 3)// QT
//		;
	if (event & QUIT)
	{
//		decharge la lib en cours
		exit(0);
	}
}

int		play(GameState game, Alib *lib)
{
	int		ret;
	int		count_frame;
	int		event;

	count_frame = 10;
	while (1)
	{
		//on recupere les touches, les deux bits les plus faibles c'est les touches directionelles (00 = UP, 01 = RIGHT, 10 = DOWN, 11 = LEFT)
		//les deux suivants c'est libs (00 = Ncurses, 01 = OpenGL, 10 = SFML, 11 = QT (si on le fait))
		//le suivant c'est escape (1 = on quitte, 0 on quitte pas)
		event = lib.input();
		treat_event(event);
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
		usleep(16666);
	}
	return (0);
}
