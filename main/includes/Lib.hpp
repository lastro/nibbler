// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Lib.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 21:11:18 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		LIB_HPP
# define	LIB_HPP

class		Lib
{
public:
	Lib(void);
	~Lib(void);
	Lib(Lib const & src);

	Lib &	operator=(Lib const & rhs);

	void	gameOver(void);
	void    window(int argc, char **argv);
};

#endif		/* LIB_HPP */ 
