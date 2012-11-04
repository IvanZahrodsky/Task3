/**
*@file		Date.h
*@brief		This file contains interface of function according to task 16
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#ifndef _DATE_H_
#define _DATE_H_

#include "stdafx.h"

typedef unsigned char UC;
typedef unsigned int UI;


typedef struct DayMonthYear
{
	UI year  : 14 ;
	UI month : 4 ;
	UI day   : 5 ;
	UI dnum  : 9 ;
} Date ;

union MyDate
{
	Date d;
	UI	 uiDate;
};
/**
*@brief		This function allocates memory
*@param		[uiPtr,cCnt] 
*@return	bool 
*/
bool Init ( UI* &uiPtr , UC &cCnt ) ;
/**
*@brief		This function scaning date from keyboard
*@param		[uiPtr , cCNt] 
*@return	void
*/
void ScanDate ( UI *uiPtr , UI cCnt ) ;
/**
*@brief		This function calculates res
*@param		[uiPtr , cCNt] 
*@return	void
*/
void CalcRes ( UI *uiPtr , UI cCnt ) ;
/**
*@brief		This function print res
*@param		[uiPtr , cCNt] 
*@return	void
*/
void PrintRes ( UI *uiPtr , UI cCnt ) ;
/**
*@brief		This function check is the year leap
*@param		[UI] 
*@return	bool
*/
bool IsLeap ( UI temp );

#endif //_DATE_H_