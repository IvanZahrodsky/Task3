/**
*@file		Str.h
*@brief		This file contains interface of function according to task 7
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#ifndef _STR_H_
#define _STR_H_

#include "stdafx.h"

typedef unsigned char UC;

/**
*@brief		This function scaning string from keyboard
*@param		[cStr] 
*@return	void
*/
void ScanStr ( char *cStr ) ;

/**
*@brief		This function scaning number from keyboard
*@param		[void] 
*@return	UC   scaning number
*/
UC ScanNum ( void ) ;

/**
*@brief		This function is remove word from string
*@param		[cStr] 
*@return	void
*/

void Run ( char *cStr ) ;

/**
*@brief		This function find the word in string
*@param		[cStr , num , offset] 
*@return	char*
*/

char* FindWord ( char *cStr , UC num , UC &offset) ;

/**
*@brief		This is additional function
*@param		[void] 
*@return	bool
*/
bool Check ( void ) ;
/**
*@brief		This is implements interface
*@param		[void] 
*@return	void 
*/
void Running ( void ) ;

#endif //_STR_H_