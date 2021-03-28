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
#include <algorithm>
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
	std::cout << "Product ID"	<< "\t"; 
	std::cout << "Order ID"		<< "\t";
	std::cout << "Delivery type"<< "\t";
	std::cout << "Price"		<< std::endl;

	//find the first occurence of Value_delivery::normal
	auto it = std::find_if(items_.begin(), items_.end(), 
		[](const Items& item) {
	   	return item.get_delivery_type() == static_cast<int>(Value_delivery::normal); 
	});

	auto index = ( it - items_.begin() );
	VAR_LOG(index);

	//Sort all fast delivery type items
	std::sort(items_.begin(), items_.begin()+index,
		[](const Items& x, const Items& y) {
		return x.get_price() > y.get_price();
	});

	//Sort all normal delivery type items
	std::sort(items_.begin()+index, items_.end(),
		[](const Items& x, const Items& y) {
		return x.get_price() < y.get_price();
	});

	for(auto itr: items_){
		std::cout << itr.get_product_id()	<< "\t"; 
		std::cout << itr.get_order_id()		<< "\t\t";
		std::cout << ( itr.get_delivery_type()==static_cast<int>(Value_delivery::normal )?"normal":"fast")<< "\t\t";
		std::cout << itr.get_price()		<< std::endl;
	}
}

int Order::push_item(Items *item)
{
	int ret = static_cast<int>(Retcode::ret_ng);
	// int insert_index;

	if( item ){

		// Insert item at the top of list when delivery_type is fast
		if( !items_.empty() && item->get_delivery_type() == static_cast<int>(Value_delivery::fast) ){
			items_.insert(items_.begin(),*item);
		}else { 
			//Insert item at the bottom of the list when delivery_type is normal
			items_.push_back(*item);
		}

		ret = static_cast<int>(Retcode::ret_ok);
	}else {/*Do nothing*/}

	return ret;
}
