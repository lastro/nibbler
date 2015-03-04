// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Element.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 18:24:20 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		ELEMENT_HPP
# define	ELEMENT_HPP
# define    SIZE_X 10
# define    SIZE_Y 10
# define	HEAD	1
# define	QUEUE	2
# define	FOOD	3


class		Element
{
public:
	Element(void);
	Element(int, int);
	~Element(void);
	Element(Element const & src);

	Element &	operator=(Element const & rhs);
	void		display(void);
	int			get_x(void);
	void		set_x(int x);
	int			get_y(void);
	void		set_y(int y);
private:
	int		_x;
	int		_y;
};

#endif		/* ELEMENT_HPP */ 
