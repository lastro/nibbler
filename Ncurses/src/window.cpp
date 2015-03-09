// ************************************************************************** //
//                                                                            //
//                                                                            //
//   window.cpp                                                               //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 17:09:43 by gmangin                                  //
//   Updated: 2015/03/09 12:32:18 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	"../includes/window.hpp"
#include	<iostream>
#include	<ncurses.h>
#include	<curses.h>

Window::Window(void):_width(1), _height(1)
{
}

Window::Window(Window const & src)
{
  *this = src;
}

Window::~Window(void)
{
}

Window const &	Window::operator=(Window const & rhs)
{
  this->_width = rhs.get_width();
  this->_height = rhs.get_height();
  return *this;
}

int	Window::get_width(void) const
{
  return (this->_width);
}

int	Window::get_height(void) const
{
  return (this->_height);
}

void	Window::set_width(int width)
{
  this->_width = width;
}

void	Window::set_height(int height)
{
  this->_height = height;
}

void	Window::display(void)
{
	std::cout << "display1" << std::endl;
	initscr();/* Start curses mode   */
	printw("Hello World !!!");/* Print Hello World  */
	refresh();/* Print it on to the real screen */
	getch();/* Wait for user input */
	endwin();
	std::cout << "display2" << std::endl;
}
