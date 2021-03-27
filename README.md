# ecommerce_exercise
This repository contains my solution to the test 2 problem below

## Test 2 Problem

Write a C++ container class in which e-commerce orders for products are stored.
For each product a list of orders are stored. Each order is composed of:
	
	* The product identifier;
	* The order identifier;
	* The order priority: fast delivery, normal delivery;
	* The order price.

	All orders have to be printed on the standard output using a dedicated function. The output requirements are:

	* Print the fast delivery order first;
	* Fast delivery orders have to be printed in descending order of price;
	* Normal delivery orders have to be printed in ascending order of price.

	```c++
	class Order_Base {
		public:
		/*
		This function is called to add an order.

		- productId: uniquely indentifies a product
		- orderId: uniquely identifies an order
		- deliveryType: 0 for normal, 1 for fast
		- price: the order price

		Returns 0 on success, -1 in case of errros
		*/
		virtual int addOrder(const std::string &productId, const std::string &orderId, int deliveryType, double price) = 0;

		/*
		This function is called to remove an existing order.

		- productId: uniquely indentifies a product
		- orderId: uniquely identifies an order

		Returns 0 on success, -1 in case of errros
		*/
		virtual int removeOrder(const std::string &productId, const std::string &orderId) = 0;

		/*
		This function prints the orders according to the requirements.
		*/
		virtual void print() = 0;
	};
	```

## Information on other github repos used in current project
- https://github.com/earljohn004/cppgenericmakefile		= folder structure and Makefile
- https://github.com/eecs280staff/unit_test_framework	= unit_test_framework used in project
