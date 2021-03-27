/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* Copyright 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
* ----------------------------------------------------------
*/

#include <iostream>
#include "order.h"

Order::Order():
	items_(0)
{
}


Order::~Order()
{
}

int Order::addOrder(const std::string &productId, const std::string &orderId, int deliveryType, double price)
{
	int ret = static_cast<int>(Retcode::ret_ng);

	Items *item = new Items( productId, orderId, deliveryType, price );

	ret = push_item(item);

	if( static_cast<Retcode>(ret) == Retcode::ret_ng )
	{
		ERROR_LOG("push_item was not successful");
	}
	else { /* Do nothing */}

	return ret;
}

int Order::removeOrder(const std::string &productId, const std::string &orderId)
{

	return static_cast<int>(Retcode::ret_ok);
}

void Order::print()
{
	for(auto itr: items_){
		std::cout << itr.get_product_id() <<std::endl;
		std::cout << itr.get_order_id() <<std::endl;
		std::cout << itr.get_delivery_type() <<std::endl;
		std::cout << itr.get_price() <<std::endl;
	}
}

int Order::push_item(Items *item)
{
	int ret = static_cast<int>(Retcode::ret_ng);

	if(item){

		items_.push_back(*item);
		ret = static_cast<int>(Retcode::ret_ok);

	}else { /*Do nothing */}

	return ret;
}
