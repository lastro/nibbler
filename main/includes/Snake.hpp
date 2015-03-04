// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Snake.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 13:56:12 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		SNAKE_HPP
# define	SNAKE_HPP

class		Snake
{
public:
	Snake(void);
	~Snake(void);
	Snake(Snake const & src);

	Snake &	operator=(Snake const & rhs);
	void		display(void);
};

#endif		/* SNAKE_HPP */ 
