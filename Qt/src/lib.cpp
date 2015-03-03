// ************************************************************************** //
//                                                                            //
//                                                                            //
//   lib.cpp                                                                  //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/03 16:52:42 by gmangin                                  //
//   Updated: 2015/03/03 16:59:42 by gmangin                                  //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "../includes/window.hpp"

extern "C" void	start_game(int argc, char **argv)
{
	Window    window;

	if (argc == 3)
    {
		window.set_width(std::atoi(argv[1]));
		window.set_height(std::atoi(argv[2]));
    }

	std::cout << "the width registered is " << window.get_width();
	std::cout << " and the height registered is " << window.get_height() << std::endl;
}
