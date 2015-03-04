// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Element.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 13:47:00 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		ELEMENT_HPP
# define	ELEMENT_HPP

class		Element
{
public:
	Element(void);
	~Element(void);
	Element(Element const & src);

	Element &	operator=(Element const & rhs);
	void		display(void);
};

#endif		/* ELEMENT_HPP */ 
