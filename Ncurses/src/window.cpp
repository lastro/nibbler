// ************************************************************************** //
//                                                                            //
//                                                                            //
//   window.cpp                                                               //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 17:09:43 by gmangin                                  //
//   Updated: 2015/03/10 03:35:07 by gmangin                                  //
//                                                                            //
// ************************************************************************** //

#include	"../includes/window.hpp"
#include	<iostream>
#include	<ncurses.h>
#include	<curses.h>

Window::Window(std::vector<std::vector<int> > grid, int x, int y):_x(x), _y(y), _grid(grid)
{
}

Window::Window(void):_x(1), _y(1)
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
  this->_x = rhs.getX();
  this->_y = rhs.getY();
  return *this;
}

int	Window::getX(void) const
{
  return (this->_x);
}

int	Window::getY(void) const
{
  return (this->_y);
}

std::vector<std::vector<int> >	Window::getGrid(void) const
{
  return (this->_grid);
}

void	Window::setX(int x)
{
  this->_x = x;
}

void	Window::setY(int y)
{
  this->_y = y;
}

//!!ERASE
void	Window::test(void)
{
	std::cout << "DISPLAY: " << std::endl;
    for (int i = 0; i < this->_y; ++i)
    {
        for (int j = 0; j < this->_x; j++)
        {
			std::cout << this->_grid[j][i] << " ";
        }
		std::cout << std::endl;
    }
}

void	Window::display(void)
{
	int ch;
	int x = this->_x + 2;
	int y = this->_y + 2;
	std::cout << "display1" << std::endl;
	initscr();/* Start curses mode   */
	cbreak();
	keypad(stdscr, true);
//	start_color();
	WINDOW	*win;
	win = newwin(x, y, 0, 0);
	refresh();/* Print it on to the real screen */
	mvaddch(0,0, '+');
	mvaddch(x,0, '+');
	mvaddch(0,y, '+');
	mvaddch(x,y, '+');
    for (int i = 1; i < y - 1; ++i)
    {
        for (int j = 1; j < x - 1; j++)
        {
			mvaddch(j,i,'o');			
        }
	}
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	mvprintw(x + 1, y + 1, "Hello World !!!");/* Print Hello World  */
	attroff(COLOR_PAIR(1));
	refresh();/* Print it on to the real screen */
	while ((ch = getch()) != KEY_LEFT)/* Wait for user input */
	{
		switch (ch)
		{
		case	KEY_RIGHT:
			std::cout << "KEY_RIGHT:" << std::endl;
			break;
		case	KEY_LEFT:
			std::cout << "KEY_LEFT:" << std::endl;
			break;
		case	KEY_UP:
			std::cout << "KEY_UP:" << std::endl;
			break;
		case	KEY_DOWN:
			std::cout << "KEY_DOWN:" << std::endl;
			break;
		}
	}
	endwin();
	std::cout << "display2" << std::endl;
}
