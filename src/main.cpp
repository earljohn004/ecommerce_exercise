/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* March 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
*
* Description: 
*	Contains the main function
*	Also contains the unit test macro
*	To perform unit tests below, Please uncomment -DTEST_MODE in Makefile
*	Program can load an existing input file as an input parameter
*	bin/ECommerce_Exercise inputs.txt
* ----------------------------------------------------------
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "common_debug.h"
#include "common_defines.h"

#include "order.h"
#include "items.h"
#include "display.h"

#ifdef TEST_MODE
#include "unit_test_framework.h"
#endif

#ifndef TEST_MODE
int main( int argc, char *argv[])
{
	char input;
	bool quitkey_pressed = false;
	Display *display = new Display();
	Order	*order = new Order();

	//Initialize the terminal, clear screen
	display->clear_screen();

	// Check if executable has one parameter
	// Assumption of a comma separated value as parameter
	// When no parameter is inputted, program starts with blank value
	if( argc > 1 ){
		//Load file contents into order object
		std::string parameter_str(argv[1]);
		std::ifstream file(parameter_str);
		std::string line_str;
		int ret = static_cast<int>(Retcode::ret_ok);

		while( std::getline(file,line_str) ){
			std::stringstream ss(line_str);

			std::string product_id;
			std::string order_id;
			std::string delivery_type;
			std::string price;

			std::getline(ss,product_id, DEF_COMMA_SEP);
			VAR_LOG(product_id);

			std::getline(ss,order_id, DEF_COMMA_SEP);
			VAR_LOG(order_id);

			std::getline(ss,delivery_type, DEF_COMMA_SEP);
			VAR_LOG(delivery_type);

			std::getline(ss,price, DEF_COMMA_SEP);
			VAR_LOG(price);

			try{
				ret = order->addOrder(product_id, order_id, std::stoi(delivery_type), static_cast<double>(std::stoi(price)));

				if( ret == static_cast<int>(Retcode::ret_ng)){
					ERROR_LOG("Cannot add item, invalid params");
				}else { /* Do nothing */ }
			}catch(const std::invalid_argument &ia){
				ERROR_LOG("skipping item, invalid parameter");
			}
		}
		MESSAGE_LOG("finished importing items from file...");

	}else {/* Do nothing */}

	while ( quitkey_pressed == false ){

		display->create_main_menu();

		std::cin >> input;
		if( input == DEF_QUIT_KEY ){
			quitkey_pressed = true;
		}else{ 
			display->transition( order, input);
		}

		display->clear_screen();
	};

	return static_cast<int>(Retcode::ret_ok);
}
#endif
/*
 * To perform unit tests below, Please uncomment -DTEST_MODE in Makefile
 */
#ifdef TEST_MODE

TEST( order_add_items )
{
	MESSAGE_LOG("------------------------");
	MESSAGE_LOG("start of add items unit testing");
	Order* order = new Order();
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG11",static_cast<int>(Value_delivery::fast),20));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus2",static_cast<int>(Value_delivery::fast),8));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus11",static_cast<int>(Value_delivery::normal),1));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus4",static_cast<int>(Value_delivery::fast),9));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG1",static_cast<int>(Value_delivery::fast),5));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus1",static_cast<int>(Value_delivery::normal),10));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG2",static_cast<int>(Value_delivery::fast),4));
	//Duplicate Exist return NG
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->addOrder("computer","asus4",static_cast<int>(Value_delivery::normal),15));

	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus5",static_cast<int>(Value_delivery::normal),11));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG12",static_cast<int>(Value_delivery::fast),3));
	order->print();
	MESSAGE_LOG("end of add items unit testing");
	MESSAGE_LOG("------------------------");
}

TEST ( order_remove_items)
{
	MESSAGE_LOG("------------------------");
	MESSAGE_LOG("start of remove items unit testing");
	Order* order = new Order();
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG11",static_cast<int>(Value_delivery::fast),20));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus2",static_cast<int>(Value_delivery::fast),8));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus11",static_cast<int>(Value_delivery::normal),1));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus4",static_cast<int>(Value_delivery::fast),9));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG1",static_cast<int>(Value_delivery::fast),5));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus1",static_cast<int>(Value_delivery::normal),10));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG2",static_cast<int>(Value_delivery::fast),4));
	//Duplicate Exist return NG
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->addOrder("computer","asus4",static_cast<int>(Value_delivery::normal),15));

	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus5",static_cast<int>(Value_delivery::normal),11));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG12",static_cast<int>(Value_delivery::fast),3));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->removeOrder("television","LG2"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->removeOrder("computer","asus4"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->removeOrder("computer","asus5"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->removeOrder("television","LG12"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("test","LG12"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("test2","asus4"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("test2","asus5"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("television","asus1"));

	//Remove item that does not exist
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("test","test"));

	order->print();
	MESSAGE_LOG("end of remove_items unit testing");
	MESSAGE_LOG("------------------------");
}

TEST ( order_adding_new_after_removing )
{
	MESSAGE_LOG("------------------------");
	MESSAGE_LOG("start of add after remove unit testing");
	Order* order = new Order();
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG11",static_cast<int>(Value_delivery::fast),20));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus2",static_cast<int>(Value_delivery::fast),8));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus11",static_cast<int>(Value_delivery::normal),1));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus4",static_cast<int>(Value_delivery::fast),9));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG1",static_cast<int>(Value_delivery::fast),5));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus1",static_cast<int>(Value_delivery::normal),10));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG2",static_cast<int>(Value_delivery::fast),4));
	//Duplicate item
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->addOrder("computer","asus4",static_cast<int>(Value_delivery::normal),15));

	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus5",static_cast<int>(Value_delivery::normal),11));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG12",static_cast<int>(Value_delivery::fast),3));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->removeOrder("television","LG2"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->removeOrder("computer","asus4"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->removeOrder("computer","asus5"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->removeOrder("television","LG12"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("test","LG12"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("test2","asus4"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("test2","asus5"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->removeOrder("television","asus1"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("mobile_phone","iphone",static_cast<int>(Value_delivery::fast),1000));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("mobile_phone","iphone12",static_cast<int>(Value_delivery::normal),1500));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("mobile_phone","iphone13",static_cast<int>(Value_delivery::normal),1123));
	order->print();
	MESSAGE_LOG("end of add after remove_items unit testing");
	MESSAGE_LOG("------------------------");
}

TEST ( order_check_duplicates )
{
	MESSAGE_LOG("------------------------");
	MESSAGE_LOG("start of check duplicates unit testing");
	Order* order = new Order();
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("television","LG11",static_cast<int>(Value_delivery::fast),20));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->addOrder("computer","asus2",static_cast<int>(Value_delivery::normal),8));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ng) , order->check_duplicates("computer","asus2"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->check_duplicates("television","asus2"));
	ASSERT_EQUAL( static_cast<int>(Retcode::ret_ok) , order->check_duplicates("test","test"));

	order->print();
	MESSAGE_LOG("end of check duplicates unit testing");
	MESSAGE_LOG("------------------------");
}

//Do not delete below code
TEST_MAIN()

#endif
