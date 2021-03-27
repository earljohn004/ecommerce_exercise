/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* Copyright 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
* ----------------------------------------------------------
*/
#ifndef _H_ORDER_H
#define _H_ORDER_H

#include <vector>
#include "common_defines.h"
#include "common_debug.h"
#include "order_base.h"
#include "items.h"


class Order : public Order_Base {

	public:
		Order();
		~Order();

		int addOrder(const std::string &productId, const std::string &orderId, int deliveryType, double price);
		int removeOrder(const std::string &productId, const std::string &orderId);
		void print();

	private:
		int push_item(Items *item);


	private:
		std::vector<Items> items_;

};
#endif //_H_ORDER_H
