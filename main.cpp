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

int	main(int argc, char **argv)
{
  if (argc != 1 && argc != 3)
    {
      std::cout << "usage: snake [width] [height]" << std::endl;
      return (1);
    }
  else if (argc == 3)
    {
      std::cout << "the width is " << argv[1];
      std::cout << " and the height is " << argv[2] << std::endl;
      std::cout << "START LIB 1" << std::endl;
    }
  else
    {
      std::cout << "START LIB 1" << std::endl;
    }
}
