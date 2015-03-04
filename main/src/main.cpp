// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/04 11:40:32 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "../includes/main.hpp"
#include <cstdlib>
#include <signal.h>
#include <dlfcn.h>

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

int	main(int argc, char **argv)
{
    void    *hand;
    void    (*f)(int, char **);
	
	if (check_arg(argc, argv))
		return (1);
	
	hand = dlopen("./lib.so", RTLD_NOW);
	if (hand == NULL)
	{
		std::cout << dlerror() << std::endl;
		return (1);
	}
	f = reinterpret_cast<void (*)(int, char **)>(dlsym(hand, "start_game"));
	f(argc, argv);
	dlclose(hand);
	return (0);
}
