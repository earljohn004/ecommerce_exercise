/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* March 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
* ----------------------------------------------------------
*/
#include <iostream>
#include "items.h"

Items::Items():
	str_product_id_(""),
	str_order_id_(""),
	i_delivery_type_(0),
	d_price_(0)
{
}

Items::Items( const std::string str_product_id, const std::string str_order_id, const int i_delivery_type, const double d_price ):
	str_product_id_( str_product_id ),
	str_order_id_( str_order_id ),
	i_delivery_type_( i_delivery_type ),
	d_price_( d_price )
{
}

Items::~Items()
{
}
