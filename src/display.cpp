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

#include <iostream>
#include <algorithm>
#include <limits>
#include "display.h"
#include "order.h"

Display::Display()
{
}

Display::~Display()
{
}

void Display::create_main_menu()
{
	std::cout <<  "Simple E-Commerce Order Application" << std::endl;
	std::cout <<  "-----------------------------------" << std::endl;
	std::cout <<  " [1] Add Order " << std::endl;
	std::cout <<  " [2] Remove Order " << std::endl;
	std::cout <<  " [3] Print Order " << std::endl;
	std::cout <<  " [q] quit " << std::endl;
	std::cout <<  "-----------------------------------" << std::endl;
	std::cout <<  "Input key:  ";
}

void Display::clear_screen()
{
	std::cout << "\033[2J\033[1;1H";
}

void Display::transition( Order *order, const char &input )
{
	switch(input){
		case '1':
			show_add_screen(order);
			break;
		case '2':
			show_remove_screen(order);
			break;
		case '3':
			show_display_screen(order);
			break;
		default:
			ERROR_LOG("Key is invalid");
			pause_terminal();
			break;
	}
}

void Display::show_add_screen(Order *order)
{
	int ret = static_cast<int>(Retcode::ret_ok);
	std::string product_id;
	std::string	order_id;
	int			delivery_type;
	double		price;


	std::cout <<  "Add Order:" << std::endl;
	std::cout <<  "-----------------------------------" << std::endl;

	std::cout <<  " Input Product ID : "; 
	std::cin  >>  product_id;

	std::cout <<  " Input Order ID : "; 
	std::cin  >>  order_id;

	std::cout <<  " Input Delivery Type ( 0:normal / 1:fast ) : ";
	while( !( std::cin >> delivery_type )){
		std::cout << "invalid value!\nInput Delivery Type ( 0:normal / 1:fast ) :  ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout <<  " Input Price : ";
	while(!( std::cin >> price )){
		std::cout << "invalid value!\n Input Price : ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	ret = order->addOrder( product_id, order_id, delivery_type, price );
	if( ret == static_cast<int>(Retcode::ret_ng)){
		ERROR_LOG("duplicate order ID exist cannot add!");
		pause_terminal();
	}else { /* Do nothing */ }

	std::cout <<  "-----------------------------------" << std::endl;
	clear_screen();
}


void Display::show_remove_screen(Order *order)
{
	int ret = static_cast<int>(Retcode::ret_ok);
	std::string product_id;
	std::string	order_id;

	std::cout <<  "Add Order:" << std::endl;
	std::cout <<  "-----------------------------------" << std::endl;
	std::cout <<  " Input Product ID : "; 
	std::cin  >>  product_id;
	std::cout <<  " Input Order ID : "; 
	std::cin  >>  order_id;

	ret = order->removeOrder( product_id, order_id );

	if( ret == static_cast<int>(Retcode::ret_ng) ){
		ERROR_LOG("item does not exist, cannot delete");
		pause_terminal();
	}else { /* Do nothing */ }
}

void Display::show_display_screen(Order *order)
{
	clear_screen();
	order->print();
	pause_terminal();
}

void Display::pause_terminal()
{
	std::cin.ignore().get();
}
