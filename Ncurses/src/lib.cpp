// ************************************************************************** //
//                                                                            //
//                                                                            //
//   lib.cpp                                                                  //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/03 16:52:42 by gmangin                                  //
//   Updated: 2015/03/10 02:58:30 by gmangin                                  //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "../includes/window.hpp"
#include	<vector>

extern "C" void	display(std::vector<std::vector<int> > grid, int x, int y)
{
	std::cout << "START window_size" << std::endl;

	Window    window(grid, x, y);

	window.test();
	window.display();

	std::cout << "the x registered is " << window.getX();
	std::cout << " and the y registered is " << window.getY() << std::endl;
	std::cout << "END window_size" << std::endl;
}
