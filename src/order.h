/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* March 2021 
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
		int addOrder(const std::string &productId, const std::string &orderId, int deliveryType, double price);
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
		int removeOrder(const std::string &productId, const std::string &orderId);
		/* ----------------------------------------------------------
		* Description: 
		*	Prints all the items on standard output
		*
		* Parameters:
		*	none
		* Return: 
		*	void 
		* ----------------------------------------------------------*/
		void print();
		/* ----------------------------------------------------------
		* Description: 
		*	Check for a duplicate of orderID
		*	
		* Parameters:
		*	Items
		*
		* Return: int Retcode::ret_ng(-1) or Retcode::ret_ok(0)
		* ----------------------------------------------------------*/
		int check_duplicates( const std::string &productId, const std::string &orderId);

	private:
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
		int push_item(Items *item);


	private:
		std::vector<Items> items_;

};
#endif //_H_ORDER_H
