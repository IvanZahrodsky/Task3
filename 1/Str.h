/**
*@file		Str.h
*@brief		This file contains interface of function according to task 1
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#ifndef _STR_H_
#define _STR_H_

#include "stdafx.h"

typedef unsigned char UC;
typedef unsigned long UL;


/**
*@brief		This function scaning string from keyboard
*@param		[UC*] 
*@return	void
*/
void ScanStr ( UC* ) ;

/**
*@brief		This function implements interface 
*@param		[void] 
*@return	void
*/
void Run ( void );
/**
*@brief		This function search max lenght word
*@param		[UC*] 
*@return	UL
*/
UL MaxWordLen ( UC* );
#endif //_STR_H_