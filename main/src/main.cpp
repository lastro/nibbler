// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/04 19:10:31 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/main.hpp"
#include	<cstdlib>
#include	<signal.h>
#include	<dlfcn.h>

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
		if (std::atoi(argv[1]) == 0 || std::atoi(argv[2]) == 0)
		{
			std::cout << "usage: snake [width] [height]" << std::endl;
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

	if (check_arg(argc, argv))
		return (1);
	try
	{
        set_window(argc, argv, game);
	}
	catch(std::string const& chaine)
	{
		std::cout << chaine << std::endl;
		return (1);
	}
	return (0);
}
