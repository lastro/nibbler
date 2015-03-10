// ************************************************************************** //
//                                                                            //
//                                                                            //
//   window.cpp                                                               //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 17:09:43 by gmangin                                  //
//   Updated: 2015/03/10 18:08:45 by gmangin                                  //
//                                                                            //
// ************************************************************************** //

#include	"../includes/window.hpp"
#include	<iostream>

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
	int x = this->_x + 1;
	int y = this->_y + 1;

	std::cout << "display1" << std::endl;
	initscr();/* Start curses mode   */
	cbreak();
	keypad(stdscr, true);
	this->_win = newwin(x, y, 0, 0);
	refresh();

    for (int i = 0; i <= y; i++)
    {
        for (int j = 0; j <= x; j++)
        {
			if ((i == 0 && j != 0 && j != x) || (i == y && j != 0 && j != x))
				mvaddch(j,i,'#');
			else if ((j == 0 && i != 0 && i != y) || (j == x && i != 0 && i != y))
				mvaddch(j,i,'#');
			else if (i == y || i == 0 || j == 0 || j == x)
				mvaddch(j,i,'#');
			else if (this->_grid[i - 1][j - 1] == 2)
				mvaddch(j,i,'@');
			else if (this->_grid[i - 1][j - 1] == 1)
				mvaddch(j,i,'o');
			else if (this->_grid[i - 1][j - 1] == 3)
				mvaddch(j,i,'x');
        }
	}
	refresh();
	getch();
	std::cout << "display2" << std::endl;
}

int		Window::input(void)
{
	int ch;

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
}
