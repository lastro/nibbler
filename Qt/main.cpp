// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: root </var/mail/root>                      +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/01/22 16:48:33 by root              #+#    #+#             //
//   Updated: 2015/01/22 16:50:20 by root             ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include	<QApplication>
#include	<QWidget>
#include	<QLabel>

int		main(int argc, char **argv)
{
	QApplication	app(argc, argv);
	QLabel	Hello("<center> WELCOME HERE </center>");

	Hello.show();
	return (app.exec());
}
