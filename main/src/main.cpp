// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/09 16:59:45 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include   "../includes/GameState.hpp"
#include   "../includes/Lib.hpp"
#include	<cstdlib>
#include	<signal.h>
#include	<iostream>

// function qui check les options mis en argument
void	check_arg(int argc, char **argv, GameState **game)
{
	if (argc != 1 && argc != 3)
		throw std::string("usage: snake [width] [height]");
	else if (argc == 3)
    {
        if (std::atoi(argv[1]) < 10 || std::atoi(argv[2]) < 10)
		{
            if (std::atoi(argv[1]) == 0 || std::atoi(argv[2]) == 0)
				throw std::string("usage: snake [width] [height]");
            else
				throw std::string("usage: the minimum of the width and the height is 10 ");
		}
		std::cout << "test" << std::endl;
		*game = new GameState(std::atoi(argv[1]), std::atoi(argv[2]));
		std::cout << "the width is " << (*game)->getX();
		std::cout << " and the height is " << (*game)->getX() << std::endl;
	}
	else
		*game = new GameState(10, 10);
}

void	play(GameState *game, Lib *lib)
{
	// a ameliorer quand on controlera bien QT, OpenGl et le 3e !
	// on pourra mettre en place le temps ... :)
	std::cout << "Rules : " << std::endl;
	std::cout << " - Play with UP RIGHT LEFT DOWN " << std::endl;
	std::cout << " - Escape to quit" << std::endl;
//	while (1)
//	{
/*	lib->move();
	    if (!(game->get_life()))
		{
			lib->gameOver();
			return;
			}*/

	//thomas notre script du rush00 c++
/*        duration = usecClock(begin, end);
        if (1000 > duration)
		usleep(1000 - duration);*/
//	}
}

// le jeu est lance, on place les pions et on les affiches dans les diff lib.
void    start_game(GameState *game, Lib *lib)
{
	try
	{
		lib->window(game->getGrid(), game->getX(), game->getY());
	}
	catch(std::string const& chaine)
	{
		throw std::string(chaine);
	}
	game->display();
	play(game, lib);
}

void	exit_game(Lib *lib, GameState *game)
{
	lib->gameOver();
	delete game;
	delete lib;
}

int		main(int argc, char **argv)
{
    GameState *game;
	Lib		*lib;

	//  signal(SIGWINCH, resize);
	srand(static_cast<unsigned int>(time( NULL )));
	try
	{
		check_arg(argc, argv, &game);
		lib = new Lib();
		start_game(game, lib);
	}
	catch(std::string const& chaine)
	{
		std::cout << chaine << std::endl;
		exit_game(lib, game);
		return (1);
	}
	
	exit_game(lib, game);
	return (0);
}
