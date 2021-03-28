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
#include <string>
#include "common_debug.h"
#include "common_defines.h"

#include "order.h"
#include "items.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#ifndef TEST_MODE
int main( int argc, char* argv[])
{
	return static_cast<int>(Retcode::ret_ok);
}
#endif
#ifdef TEST_MODE

TEST( order_add_items )
{
	Order* order = new Order();
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG11",static_cast<int>(Value_delivery::fast),20));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus2",static_cast<int>(Value_delivery::fast),8));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus11",static_cast<int>(Value_delivery::normal),1));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus4",static_cast<int>(Value_delivery::fast),9));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG1",static_cast<int>(Value_delivery::fast),5));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus1",static_cast<int>(Value_delivery::normal),10));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG2",static_cast<int>(Value_delivery::fast),4));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus4",static_cast<int>(Value_delivery::normal),15));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus5",static_cast<int>(Value_delivery::normal),11));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG12",static_cast<int>(Value_delivery::fast),3));
	order->print();
}


//Do not delete below code
TEST_MAIN()

#endif
