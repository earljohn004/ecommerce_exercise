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
#include <string>
#include "common_debug.h"
#include "common_defines.h"

#include "order.h"
#include "items.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#ifndef TEST_MODE
int main(){

	return static_cast<int>(Retcode::ret_ok);
}
#endif
#ifdef TEST_MODE

TEST( order_add_items ){
	Order* order = new Order();
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("test1","test2",static_cast<int>(Value_delivery::normal),10.50));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("test3","test4",static_cast<int>(Value_delivery::fast),15.00));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("test5","test6",static_cast<int>(Value_delivery::normal),15.00));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("test7","test8",static_cast<int>(Value_delivery::fast),15.00));
	order->print();
}


//Do not delete below code
TEST_MAIN()

#endif
