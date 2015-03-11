// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/11 19:23:50 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include   "../includes/GameState.hpp"
#include   "../includes/Lib.hpp"
#include	<cstdlib>
#include	<signal.h>
#include	<iostream>

int		play(GameState & game, Lib & lib);

// function qui check les options mis en argument
GameState	*check_arg(int argc, char **argv)
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
		std::cout << "the width is " << std::atoi(argv[1]) << std::endl;
		std::cout << " and the height is " << std::atoi(argv[2]) << std::endl;
		return (new GameState(std::atoi(argv[1]), std::atoi(argv[2])));
	}
	else
		return (new GameState(10, 10));
}

void	exit_game(Lib *lib, GameState *game)
{
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
		game = check_arg(argc, argv);
		lib = new Lib(*game);
		play(*game, *lib);
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
