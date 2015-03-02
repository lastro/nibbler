// ************************************************************************** //
//                                                                            //
//                                                                            //
//   main.cpp                                                                 //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/02 12:55:28 by gmangin                                  //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int		main(int argc, char **argv)
{
	if (argc != 1 || argc != 2)
	{
		std::cout << "usage: snake [width] [height]" << std::endl;
		return (1);
	}
	else if (argc == 2)
	{
		std::cout << "the width is " + argv[1];
		std::cout << " and the height is :" + argv[2] << std::endl;
		//go lib
	}
	else
	{
		//go lib
	}
}
