// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lib.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 21:57:24 by gmangin          ###   ########.fr       //
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
	void    window(int argc, char **argv);
	void	move(std::vector< std::vector <int > > &map);
};

#endif		/* LIB_HPP */ 
