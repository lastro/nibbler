// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/04 16:15:33 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	<iostream>
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

void	set_window(int argc, char **argv)
{
    void    *hand;
    void    (*f)(int, char **);

    if (argc == 3)
    {
        window.set_width(std::atoi(argv[1]));
        window.set_height(std::atoi(argv[2]));
    }
		hand = error_dl("./lb.so");
	}
	f = reinterpret_cast<void (*)(int, char **)>(dlsym(hand, "start_game"));
	f(argc, argv);
	dlclose(hand);
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

int		main(int argc, char **argv)
{
	if (check_arg(argc, argv))
		return (1);
	try
	{
		set_window(argc, argv);
	}
	catch(std::string const& chaine)
	{
		std::cout << chaine << std::endl;
		return (1);
	}
	return (0);
}
