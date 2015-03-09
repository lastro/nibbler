// ************************************************************************** //
//                                                                            //
//                                                                            //
//   lib.cpp                                                                  //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/03 16:52:42 by gmangin                                  //
//   Updated: 2015/03/09 16:33:12 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "../includes/window.hpp"
#include	<vector>

extern "C" void	display(std::vector<std::vector<int> > grid, int width, int height)
{
	Window    window;

	std::cout << "window_size" << std::endl;
	window.set_width(width);
	window.set_height(height);
//	window.display();

	std::cout << "the width registered is " << window.get_width();
	std::cout << " and the height registered is " << window.get_height() << std::endl;
}
