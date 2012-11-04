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
*@brief		This function implements interface
*@param		[void] 
*@return	void
*/
void Run ( void )
{
	srand ( UC (time (NULL ) ) );
	UC * arr = (UC*) malloc (20);
	if ( !arr )
	{
		printf ( "\nError in allocate memory\n" );
		return;
	}
	printf ( "\nAutomatic generated array\n" );
	for ( register UC i = 0; i < 20 ; ++i)
	{
		arr [ i ] = (rand () % 90) + 10;
		printf ( "%u  " , arr[i]);
	}
	printf ( "\nResult:\n" );
	for ( register UC i = 0; i < 20 ; ++i)
	{
		Cnvrt ( arr[i] );
	}

	
}
/**
*@brief		This function print int in str
*@param		[void] 
*@return	void
*/
void Cnvrt ( UC tmp )
{
	UC tmp1[10][9] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seven", "eighteen","nineteen" };
	UC tmp2[8][7] = { "twenty", "thirty", "forty","fifty","sixty","sevety","eighty","ninety" };
	UC tmp3[9][6] = { "one","two","three","four","five","six","seven","eight","nine"};
	if ( tmp < 20 )
	{
		printf ( "\n%u  -  %s\n", tmp , tmp1 [tmp - 10]);
	}
	else
	{
		UC t1,t2;
		t2 = tmp % 10;
		t1 = (tmp/10) % 10;
		printf ( "\n%u  -  %s" , tmp, tmp2[t1 - 2]);
		if ( t2 > 0 )
		{
			printf ( "  %s" , tmp3[t2 - 1]);
		}
		printf ("\n");

	}

}