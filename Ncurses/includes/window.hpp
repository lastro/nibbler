// ************************************************************************** //
//                                                                            //
//                                                                            //
//   window.hpp                                                               //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/10 17:12:57 by gmangin                                  //
//                                                                            //
// ************************************************************************** //

#ifndef		WINDOW_HPP
# define	WINDOW_HPP

# include	<vector>
# include	<ncurses.h>
# include	<curses.h>

class		Window
{
public:
	Window(std::vector<std::vector<int> > grid, int x, int y);
	Window(Window const & src);
	~Window(void);
	Window const &	operator=(Window const & rhs);
	
	int		getX(void) const;
	int		getY(void) const;
	std::vector<std::vector<int> >	getGrid(void) const;
	void	setX(int);
	void	setY(int);
	void	test(void);
	void	display(void);
	int		input(void);
	
private:
	Window(void);
	int	_x;
	int	_y;
    WINDOW  *_win;
	std::vector<std::vector<int> > _grid;
};

#endif		/* WINDOW_HPP */
