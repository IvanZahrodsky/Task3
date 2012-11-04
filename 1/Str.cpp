/**
*@file		Str.cpp
*@brief		This file contains implementations of function according to task 7
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/

#include "stdafx.h"

/**
*@brief		This function scaning string from keyboard
*@param		[cStr] 
*@return	void
*/
void ScanStr ( UC *cStr ) 
{
	printf ( "Enter string:\n" ) ;
	if ( ! cStr )
	{
		printf ( "Error!" );
		return;
	}
	while ( !scanf ( "%511[^\n]s" , cStr ))
	{
		fflush(stdin);
	}
	fflush(stdin);
}

/**
*@brief		This function implements interface 
*@param		[void] 
*@return	void
*/
void Run ( void )
{
	UC * str = (UC*) malloc ( 512 );
	if ( !str )
	{
		printf ( "\nError in allocate memory!\n" );
		return;
	}
	ScanStr ( str ) ;
	UL length = MaxWordLen ( str );
	printf ( "\nThe max word legth - %u \n\n" , length );
	free ( str );
}
/**
*@brief		This function search max lenght word
*@param		[str] 
*@return	UL
*/
UL MaxWordLen ( UC *cStr )
{
	register UL i = -1;
	UC tmp ;
	tmp = 0;
	UL max = 0;
	do
	{
		++i;
		if (cStr [i] == 32 || cStr [ i ] == '\0' )
		{
			if ( tmp > max )
			{
				max = tmp;
			}
			tmp = 0 ;
			continue ;
		}
		++tmp ;
	}
	while ( cStr [ i ] != '\0') ;
	return max;
}