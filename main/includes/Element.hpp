// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Element.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 21:12:49 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		ELEMENT_HPP
# define	ELEMENT_HPP

# define    SIZE_X 10
# define    SIZE_Y 10
# define	HEAD	1
# define	QUEUE	2
# define	FOOD	3
# include    <vector>

class		Element
{
public:
	Element(void);
	Element(int, int);
	~Element(void);
	Element(Element const & src);

	Element &	operator=(Element const & rhs);

	void		display(std::vector< std::vector <int > > &map);
	void		init_snake(std::vector< std::vector <int > > &map);
	void		init_map(std::vector< std::vector <int > > &map);
	int			get_x(void) const;
	int			get_y(void) const;
	int         get_life(void) const;
	void		set_x(int x);
	void		set_y(int y);
	void		set_life(int life);
	


private:
	int		_x;
	int		_y;
	int		_life;
};

#endif		/* ELEMENT_HPP */ 
