// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   SFMLLib.hpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/16 16:32:15 by rnicolas          #+#    #+#             //
//   Updated: 2015/03/16 16:41:13 by rnicolas         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SFMLLIB_HPP
# define SFMLLIB_HPP

# include <SFML/window.hpp>
# include <vector>
# include "ILib.hpp"

class SFMLLib: public ILib
{
public:
	SFMLLib(int x, int y);
	~SFMLLib(void);

	void	display(int x, int y, std::vector<std::vector<int> > grid);
	int		input(void);

	void	closeWindow(void);
private:

	sf::RenderWindow	_window;
};

#endif
