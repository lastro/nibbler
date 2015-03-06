// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/06 16:39:02 by amusic           ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include   "../includes/Element.hpp"
#include   "../includes/Lib.hpp"
#include	<cstdlib>
#include	<signal.h>
#include	<iostream>

std::string     graph[3] = { "QT", "OpenGl", "Autre" };

// function qui check les options mis en argument
void	check_arg(int argc, char **argv, Lib *lib, Element *game)
{
	if (argc != 1 && argc != 3)
		throw std::string("usage: snake [width] [height]");
	else if (argc == 3)
    {
        if (std::atoi(argv[1]) < 5 || std::atoi(argv[2]) < 5)
		{
            if (std::atoi(argv[1]) == 0 || std::atoi(argv[2]) == 0)
				throw std::string("usage: snake [width] [height]");
            else
				throw std::string("usage: the minimum of the width and the height is 5 ");
		}
		game->set_x(std::atoi(argv[1]));
		game->set_y(std::atoi(argv[2]));
		std::cout << "the width is " << game->get_x();
		std::cout << " and the height is " << game->get_x() << std::endl;
	}
	std::cout << "START LIB 1 : " << graph[0]  << std::endl;
	try
	{
		lib->window(argc, argv);
	}
	catch(std::string const& chaine)
	{
		throw std::string(chaine);
	}
}

void	play(std::vector< std::vector <int > > &map, Element *game, Lib *lib)
{
	// a ameliorer quand on controlera bien QT, OpenGl et le 3e !
	// on pourra mettre en place le temps ... :)
	std::cout << "Rules : " << std::endl;
	std::cout << " - Play with UP RIGHT LEFT DOWN " << std::endl;
	std::cout << " - Escape to quit" << std::endl;
//	while (1)
//	{
	lib->move(map);
	    if (!(game->get_life()))
		{
			lib->gameOver();
			return;
		}

	//thomas notre script du rush00 c++
/*        duration = usecClock(begin, end);
        if (1000 > duration)
		usleep(1000 - duration);*/
//	}
}

// le jeu est lance, on place les pions et on les affiches dans les diff lib.
void    start_game(Element *game, Lib *lib)
{
	std::vector< std::vector <int > > map;

    game->init_map(map);
    game->init_snake(map);
	game->display(map);
	play(map, game, lib);
}

void	exit_game(Lib *lib, Element *game)
{
	lib->gameOver();
	delete game;
	delete lib;
}

int		main(int argc, char **argv)
{
    Element *game;
	Lib		*lib;

    game = new Element();
	lib = new Lib();
	//  signal(SIGWINCH, resize); SOON
	srand(static_cast<unsigned int>(time( NULL )));
	try
	{
		check_arg(argc, argv, lib, game);
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
