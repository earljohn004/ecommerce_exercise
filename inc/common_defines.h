/*
* ---------------------------------------------------------
* Ecommerce Application Amarula Excercise
*
* March 2021 
*
* author:	Earl John Abaquita <earl.abaquita@outlook.com>
* ----------------------------------------------------------
*/
#ifndef _H_COMMON_DEFINES_H
#define _H_COMMON_DEFINES_H

#define DEF_QUIT_KEY 'q'
#define DEF_COMMA_SEP ','
#define DEF_DELIVERY_MAX 2

enum class Retcode : int 
{
	ret_ng = -1,
	ret_ok = 0
};

enum class Value_delivery : int 
{
	normal	 = 0,
	fast	 = 1,
};

#endif //_H_COMMON_DEFINES_H
