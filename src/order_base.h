/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* Copyright 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
* ----------------------------------------------------------
*/
#ifndef _H_ORDER_BASE_H
#define _H_ORDER_BASE_H

class Order_Base {
	public:
		/*
		*		This function is called to add an order.
		*		
		*		- productId: uniquely indentifies a product
		*		- orderId: uniquely identifies an order
		*		- deliveryType: 0 for normal, 1 for fast
		*		- price: the order price
		*											
		*		Returns 0 on success, -1 in case of errros
		*/	
		virtual int addOrder(const std::string &productId, const std::string &orderId, int deliveryType, double price) = 0;

		/*
		 *		This function is called to remove an existing order.
		 *				
		 *		- productId: uniquely indentifies a product
		 *		- orderId: uniquely identifies an order
		 *							
		 *		Returns 0 on success, -1 in case of errros
		 */
		virtual int removeOrder(const std::string &productId, const std::string &orderId) = 0;

		/*
		 *		This function prints the orders according to the requirements.
		*/
		virtual void print() = 0;
};
#endif //_H_ORDER_BASE_H
