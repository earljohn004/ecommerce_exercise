/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* Copyright 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
* ----------------------------------------------------------
*/
#ifndef _H_ITEMS_H
#define _H_ITEMS_H

#include <string>
#include "common_defines.h"
#include "common_debug.h"

class Items{
	public:
		Items();
		Items( const std::string str_product_id, const std::string str_order_id, const int i_delivery_type, const double d_price );
		~Items();

		std::string	get_product_id();
		std::string get_order_id();
		int get_delivery_type();
		double get_price();

	private:
		std::string str_product_id_;
		std::string str_order_id_;
		int			i_delivery_type_;
		double		d_price_;
};
#endif //_H_ITEMS_H
