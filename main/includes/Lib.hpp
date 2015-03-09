// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lib.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/09 16:37:57 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		LIB_HPP
# define	LIB_HPP

# include	<vector>

class		Lib
{
public:
	Lib(void);
	~Lib(void);
	Lib(Lib const & src);

	Lib &	operator=(Lib const & rhs);

	void	gameOver(void);
	void    window(std::vector<std::vector<int> > grid, int x, int y);
	void    getInput(void);
	void	chooseLib(int i);

private:
	int		_current;
};

#endif		/* LIB_HPP */ 
