/**
*@file		Task3_16.cpp
*@brief		This file contains the main function that implementing tasks.
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	UI *date;
	UC cCnt;
	if ( Init(date , cCnt) )
	{
		ScanDate ( date, cCnt ) ;
		CalcRes ( date, cCnt ) ;
		PrintRes ( date , cCnt ) ;
		free ( date ) ;
	}
	return 0;
}

