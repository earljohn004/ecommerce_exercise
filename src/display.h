/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* March 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
*
* Description: 
*	This class renders the Console application UI on the terminal
*	Utilizes only the basic input and output streams
* ----------------------------------------------------------
*/
#ifndef _H_DISPLAY_H
#define _H_DISPLAY_H

#include <iostream>
#include "order.h"

class Display{
	public:
		Display();
		~Display();
		void create_main_menu();
		void clear_screen();
		void transition( Order *order, const char &input );

	private:
		void show_add_screen( Order *order );
		void show_remove_screen( Order *order );
		void show_display_screen(Order *order );
		void pause_terminal();
};

#endif //H_DISPLAY_H
