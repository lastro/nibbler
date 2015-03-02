// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/02 14:48:07 by tlepetit         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "../includes/main.hpp"
#include <signal.h>

void	start_game(int argc, char **argv)
{
  Window	window;

  if (argc == 3)
    {
      window.set_width(std::atoi(argv[1]));
      window.set_height(std::atoi(argv[2]));
    }
  
  std::cout << "the width registered is " << window.get_width();
  std::cout << " and the height registered is " << window.get_height() << std::endl;
}

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
  if (check_arg(argc, argv))
    return (1);
  start_game(argc, argv);
}
