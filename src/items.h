/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* March 2021 
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

		auto get_product_id() const { return str_product_id_;}
		auto get_order_id() const { return str_order_id_;}
		auto get_delivery_type() const { return i_delivery_type_ ;}
		auto get_price() const { return d_price_; }

	private:
		std::string str_product_id_;
		std::string str_order_id_;
		int			i_delivery_type_;
		double		d_price_;
};
#endif //_H_ITEMS_H
