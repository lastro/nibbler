// ************************************************************************** //
//                                                                            //
//                                                                            //
//   window.hpp                                                               //
//                                                                            //
//   By: gmangin <gaelle.mangin@hotmail.fr>                                   //
//                                                                            //
//   Created: 2015/03/02 12:39:27 by gmangin                                  //
//   Updated: 2015/03/09 11:36:57 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		WINDOW_HPP
# define	WINDOW_HPP

class		Window
{
public:
	Window(void);
	Window(Window const & src);
	~Window(void);
	Window const &	operator=(Window const & rhs);
	
	int		get_width(void) const;
	int		get_height(void) const;
	void	set_width(int);
	void	set_height(int);
	void	display(void);
	
private:
	int	_width;
	int	_height;
};

#endif		/* WINDOW_HPP */
