/**
*@file		Arr.cpp
*@brief		This file contains implementations of function according to task 7
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/

#include "stdafx.h"

/**
*@brief		This function is remove word from string
*@param		[void] 
*@return	void
*/
void Run ( void )
{
	srand ( UI ( time ( NULL ) ) );
	UI *arr = NULL;
	UI num, count,tmp;
	
	while (true)
	{
		printf ( "\n1 - Generate array\
				  \n2 - Print Array\
				  \n3 - Insert element to array\
				  \n0 - Exit\n" );
		Scan ( "%1[0-9]s" , num );
		switch ( num )
		{
			case 1:
				printf ( "\nEnter count - " );
				Scan ( "%3[0-9]s" , count );
				GenArr ( arr, count );
				break;
			case 2:
				PrintArr ( arr , count );
				break;
			case 3:
				printf ( "\nEnter element\n" );
				Scan ( "%11[0-9]s" , tmp );
				Insert ( arr, count, tmp );
				break;
			case 0:
				if ( !arr )
				{
					free ( arr );
				}
				return;
		}
	}
}
/**
*@brief		This function scaning umber
*@param		[void] 
*@return	void
*/
void Scan (const char * frmt , UI &temp)
{
	UC *buf = ( UC* ) malloc ( 15 );
	while ( !scanf(frmt,buf) )
	{
		printf ( "\nError enter again!\n" );
		fflush (stdin);
	}
	fflush (stdin);
	temp = atoi ( (const char *)buf );
}
/**
*@brief		This function generate array
*@param		[void] 
*@return	void
*/
void GenArr (UI *& arr , UI N)
{
	register UI i,j;
	if ( arr )
	{
		free ( arr );
	}
	arr = ( UI * ) malloc ( sizeof ( UI ) * N ) ;
	if ( !arr )
	{
		printf ( "Error in allocated memory" );
		return;
	}
	for ( i = 0; i < N ; ++i )
	{
		arr [ i ] = rand() % 1000;
	}
	//sorting array
	UI temp ;
	for ( i = 0; i < N; ++i)
	{
		for ( j = i; j < N; ++j)
		{
			if ( arr [i] > arr[j] )
			{
				temp = arr [i];
				arr [i] = arr [j];
				arr [j] = temp;
			}
		}
	}
}

/**
*@brief		This function displays array
*@param		[void] 
*@return	void
*/
void PrintArr (UI *arr, UI N)
{
	printf ( "\nArray : \n" );
	for ( register UI i = 0; i < N; ++i)
	{
		printf ( "%u  " , arr[i] );
	}
}

/**
*@brief		This function insert element to array
*@param		[UI *& , UI&, UI] 
*@return	void
*/
void Insert (UI *& arr , UI& n, UI elm)
{
	if ( !arr )
	{
		printf ( "\nArray is empty!\n" );
		return;
	}
	arr = ( UI* ) realloc (arr , (n+1) * sizeof (UI) );
	if ( !arr )
	{
		printf ( "\nError!\n" );
		return;
	}
	register UI i;
	for ( i = 0; i < n; ++i )
	{

		if ( elm < arr [i] )
		{
			break;
		}
	}
	memmove ( (arr + i + 1 ), (arr + i ) , (n-i) * sizeof(UI));
	*(arr + i) = elm;
	n += 1;

}