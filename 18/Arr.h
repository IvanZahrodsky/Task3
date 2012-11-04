/**
*@file		Arr.h
*@brief		This file contains interface of function according to task 7
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#ifndef  _ARR_H_
#define _ARR_H_

#include "stdafx.h"

typedef unsigned int UI;
typedef unsigned char UC;
/**
*@brief		This function is remove word from string
*@param		[void] 
*@return	void
*/
void Run (void);
/**
*@brief		This function generate array
*@param		[UI *& , UI] 
*@return	void
*/
void GenArr (UI *& , UI);

/**
*@brief		This function displays array
*@param		[UI * , UI] 
*@return	void
*/
void PrintArr (UI * , UI);

/**
*@brief		This function scaning umber
*@param		[const char * , UI &] 
*@return	void
*/
void Scan (const char * , UI &);

/**
*@brief		This function insert element to array
*@param		[UI *& , UI&, UI] 
*@return	void
*/
void Insert (UI *& , UI&, UI);

#endif //_ARR_H_