// ************************************************************************** //
//                                                                            //
//                                                                            //
//   lib.cpp                                                                  //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/03 16:52:42 by gmangin                                  //
//   Updated: 2015/03/04 17:16:58 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cstdlib>
#include "../includes/window.hpp"

extern "C" void	window_size(int width, int height)
{
	Window    window;

	window.set_width(width);
	window.set_height(height);

	std::cout << "the width registered is " << window.get_width();
	std::cout << " and the height registered is " << window.get_height() << std::endl;
}
