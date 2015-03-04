// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Food.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: gmangin <gmangin@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/04 13:45:04 by gmangin           #+#    #+#             //
//   Updated: 2015/03/04 13:58:49 by gmangin          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef		FOOD_HPP
# define	FOOD_HPP

class		Food
{
public:
	Food(void);
	~Food(void);
	Food(Food const & src);

	Food &	operator=(Food const & rhs);
	void		display(void);
};

#endif		/* FOOD_HPP */ 
