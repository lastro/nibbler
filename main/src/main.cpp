// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/04 20:00:51 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/main.hpp"
#include	<cstdlib>
#include	<signal.h>
#include	<dlfcn.h>
#include    <vector>
#include	<ctime>

void	display_map(std::vector< std::vector <int > > &map, int x, int y)
{
	for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; j++)
        {
			std::cout << map[i][j] << " ";
        }
		std::cout << std::endl;
    }
}

// partie INIT du snake sur la map a un endroit random (map rempli
// de 1 TETE et 1 QUEUE), le snake fait au debut 2 cases du tableau
void    init_snake(std::vector< std::vector <int > > &map, int x, int y)
{
	int	i;
	int	j;

	// je place la tete de maniere random
	i = std::rand() % (y - 4) + 1;
	j = std::rand() % (x - 2) + 1;
	std::cout << i << " " << j << std::endl;
	map[i][j] = 1;
	// puis je place la queue derriere :)
	map[i - 1][j] = 2;
}

// partie INIT de la map (double tableau rempli de 0 == empty)
void    init_map(std::vector< std::vector <int > > &map, int x, int y)
{
    map.resize(y);
    for (int i = 0; i < y; ++i)
    {
        map[i].resize(x);
        for (int j = 0; j < x; j++)
        {
            map[i][j] = 0;
        }
    }
}

// le jeu est lance, on place les pions et on les affiches dans les diff lib.
void    start_game(Element *game)
{
	std::vector< std::vector <int > > map;

    init_map(map, game->get_x(), game->get_y());
    init_snake(map, game->get_x(), game->get_y());
	display_map(map, game->get_x(), game->get_y());
}

// function qui check les options mis en argument
int	check_arg(int argc, char **argv)
{
  //  signal(SIGWINCH, resize);
	if (argc != 1 && argc != 3)
    {
		std::cout << "usage: snake [width] [height]" << std::endl;
		return (1);
    }
	else if (argc == 3)
    {
        if (std::atoi(argv[1]) < 5 || std::atoi(argv[2]) < 5)
		{
            if (std::atoi(argv[1]) == 0 || std::atoi(argv[2]) == 0)
				std::cout << "usage: snake [width] [height]" << std::endl;
            else
				std::cout << "usage: the minimum of the width and the height is 5 " << std::endl;
            return (1);
		}
		std::cout << "the width is " << std::atoi(argv[1]);
		std::cout << " and the height is " << std::atoi(argv[2]) << std::endl;
		std::cout << "START LIB 1 : " << graph[0]  << std::endl;
    }
	else
    {
		std::cout << "START LIB 1 : " << graph[0]  << std::endl;
    }
	return (0);
}

// function generique pour les open dl (lib static)
void *	error_dl(const char * lib)
{
    void    *hand;

	hand = dlopen(lib, RTLD_NOW);
	if (hand == NULL)
		throw std::string(dlerror());
   return hand;
}

void    set_window(int argc, char **argv, Element *game)
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
   {
	   game->set_x(std::atoi(argv[1]));
	   game->set_y(std::atoi(argv[2]));
   }
   f(game->get_x(), game->get_y());
   dlclose(hand);
}

int		main(int argc, char **argv)
{
    Element *game;

    game = new Element();
	srand(static_cast<unsigned int>(time( NULL )));

	if (check_arg(argc, argv))
		return (1);
	try
	{
        set_window(argc, argv, game);
		start_game(game);
	}
	catch(std::string const& chaine)
	{
		std::cout << chaine << std::endl;
		return (1);
	}
	return (0);
}
