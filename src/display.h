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
		/* ----------------------------------------------------------
		* Description: 
		*	Displays the main menu terminal GUI
		*
		* Parameters:
		* Return: void 
		*
		* ----------------------------------------------------------*/
		void create_main_menu();

		/* ----------------------------------------------------------
		* Description: 
		*	Clears the contents of the terminal
		*
		* Parameters:
		* Return: void 
		*
		* ----------------------------------------------------------*/
		void clear_screen();
		/* ----------------------------------------------------------
		* Description: 
		*	Transition logic
		*	Press 1 will show add order screen
		*	Press 2 will show remove order screen
		*	Press 3 will show all orders
		*
		* Parameters:
		*	Order order
		*	input -> const char
		* Return: void 
		*
		* ----------------------------------------------------------*/
		void transition( Order *order, const char &input );

	private:
		/* ----------------------------------------------------------
		* Description: 
		*	Displays the add order terminal GUI
		*
		* Parameters:
		*	Order *order
		* Return: void 
		*
		* ----------------------------------------------------------*/
		void show_add_screen( Order *order );
		/* ----------------------------------------------------------
		* Description: 
		*	Displays the remove order terminal GUI
		*
		* Parameters:
		*	Order *order
		* Return: void 
		*
		* ----------------------------------------------------------*/
		void show_remove_screen( Order *order );
		/* ----------------------------------------------------------
		* Description: 
		*	Displays all orders terminal GUI
		*
		* Parameters:
		*	Order *order
		* Return: void 
		*
		* ----------------------------------------------------------*/
		void show_display_screen(Order *order );
		/* ----------------------------------------------------------
		* Description: 
		*	Pauses terminal input
		*
		* Parameters:
		* Return: void 
		*
		* ----------------------------------------------------------*/
		void pause_terminal();
};

#endif //H_DISPLAY_H
