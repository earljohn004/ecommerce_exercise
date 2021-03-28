/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* March 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
*
* Description: 
*	The derived class from the virtual class Order_Base
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

/* ----------------------------------------------------------
* Description: 
*	Adds an order
*
* Parameters:
* IN product_Id		-> std::string
* IN orderId		-> std::string
* IN deliveryType	-> int
* IN price			-> double
*
* Return: int Retcode::ret_ng or Retcode::ret_ok
*
* ----------------------------------------------------------*/
int Order::addOrder(const std::string &productId, const std::string &orderId, int deliveryType, double price)
{
	int ret = static_cast<int>(Retcode::ret_ng);

	ret = check_duplicates( productId, orderId );

	if( static_cast<Retcode>(ret) == Retcode::ret_ok ){
		Items *item = new Items( productId, orderId, deliveryType, price );

		ret = push_item(item);

		if( static_cast<Retcode>(ret) == Retcode::ret_ng )
		{
			ERROR_LOG("push_item was not successful");
		}
		else { /* Do nothing */}
	} else { 
		ERROR_LOG("duplicate exist cannot add");
	}

	return ret;
}

/* ----------------------------------------------------------
* Description: 
*	Removes an order
*
* Parameters:
* IN product_Id		-> std::string
* IN orderId		-> std::string
*
* Return: int Retcode::ret_ng(-1) or Retcode::ret_ok(0)
*
* ----------------------------------------------------------*/
int Order::removeOrder(const std::string &productId, const std::string &orderId)
{
	//find the first occurence of Value_delivery::normal
	auto it = std::find_if(items_.begin(), items_.end(), 
		[&]( const Items& item ) {
	   	return ((item.get_product_id() == productId) && (item.get_order_id() == orderId)); 
	});

	// get the index of the matched item above
	auto index = ( it - items_.begin() );

	if( it == items_.end() )
	{
		return static_cast<int>(Retcode::ret_ng);
	}
	else 
	{
		//delete item in vector
		items_.erase( items_.begin()+index );
	}

	return static_cast<int>(Retcode::ret_ok);
}

/* ----------------------------------------------------------
* Description: 
*	Prints all the items on standard output
*
* Parameters:
*	none
* Return: 
*	void 
* ----------------------------------------------------------*/
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

	// Get the index of the matched item
	auto index = ( it - items_.begin() );

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
		std::cout << itr.get_product_id()	<< "\t\t"; 
		std::cout << itr.get_order_id()		<< "\t\t";
		std::cout << ( itr.get_delivery_type() == static_cast<int>(Value_delivery::normal )?"normal":"fast")<< "\t\t";
		std::cout << itr.get_price()		<< std::endl;
	}
}


/* ----------------------------------------------------------
* Description: 
*	appends new items either on the front or the back
*	When delivery type is fast, insert on front
*	When delivery type is normal, push at the back
*	
* Parameters:
*	Items
*
* Return: int Retcode::ret_ng(-1) or Retcode::ret_ok(0)
* ----------------------------------------------------------*/
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

/* ----------------------------------------------------------
* Description: 
*	Check for a duplicate of orderID
*	
* Parameters:
*	Items
*
* Return: int Retcode::ret_ng(-1) or Retcode::ret_ok(0)
* ----------------------------------------------------------*/
int Order::check_duplicates( const std::string &productId, const std::string &orderId )
{
	int ret = static_cast<int>(Retcode::ret_ok);

	//find the first occurence of Value_delivery::normal
	auto it = std::find_if(items_.begin(), items_.end(), 
		[&]( const Items& item ) {
	   	return ((item.get_product_id() == productId) && (item.get_order_id() == orderId)); 
	});

	if( it != items_.end() ){
		// When item exist, returns NG
		ret = static_cast<int>(Retcode::ret_ng);
	}else{ /*Do nothing*/ }

	return ret;
}
