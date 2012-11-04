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
void ScanStr ( char *cStr ) 
{
	printf ( "Enter string:\n" ) ;
	while ( !scanf ( "%255[^\n]s" , cStr ) )
	{
		fflush(stdin);
	}
	fflush(stdin);
	return ;
}
/**
*@brief		This function is remove word from string
*@param		[cStr] 
*@return	void
*/
void Run ( char *cStr )
{
	UC Nmb ;
	UC offset;
	char *temp;
	Nmb = ScanNum ( ) ;
	if ( Nmb == 0 )
	{
		printf ( "\nThe number must be > 0" ) ;
		return ;
	}
	temp = FindWord (cStr,Nmb,offset);
	if ( temp == NULL )
	{
		printf ( "Error! No words No. %d \n" , Nmb );
	}
	else
	{
		memmove ( temp , cStr + offset , strlen ( cStr ) - offset + 1 ) ;
		printf ( "\nResult:\n%s\n" , cStr ) ;
	}
	return ;
}

/**
*@brief		This function scaning number from keyboard
*@param		[void] 
*@return	UC   scaning number
*/
UC ScanNum ( void )
{
	UC num;
	char buf[3];
	printf ( "\nEnter the number of word that you want to remove:  " );
	while ( !scanf ( "%2[0-9]s" , buf ) )
	{
		fflush ( stdin ) ;
		printf ( "\nError enter again please! -  " ) ;
	}
	fflush ( stdin ) ;
	num = atoi ( buf ) ;
	return num;
}
/**
*@brief		This function find the word in string
*@param		[cStr , num , offset] 
*@return	char*
*/
char* FindWord ( char *cStr , UC num , UC &offset ) 
{
	int i ;
	UC CnWrd ;
	UC tmp ;
	i = 0 ;
	CnWrd = tmp = 0;
	do
	{
		if (cStr [i] == 32 || cStr [ i ] == '\0' )
		{
			if ( tmp > 0 )
			{
				CnWrd++ ;
			}
			tmp = 0 ;
			continue ;
		}
		tmp++ ;
	}
	while ( cStr [ i++ ] != '\0' && CnWrd != num ) ;
	if ( CnWrd != num )
	{
		return NULL ;
	}
	else
	{	
		offset = --i ;
		do
		{
			;
		}
		while ( cStr [--i] != 32 && i != 0 ) ;
		return ( cStr + i ) ;
	}
}

/**
*@brief		This is additional function
*@param		[void] 
*@return	bool
*/
bool Check ( void )
{
	char buf [2] ;
	printf ( "\nWant to delete another? [Y/N] - " ) ;
	while ( !scanf ( "%1[Y,N]s" , buf ) )
	{
			fflush(stdin);
			printf ( "\nError! Enter again  - " ) ;
	}
	fflush(stdin);
	return (*buf == 'Y' ) ? true : false ;
}

/**
*@brief		This is implements interface
*@param		[void] 
*@return	void 
*/
void Running ( void ) 
{
	char* cStr = (char*) malloc (256) ;
	if ( !cStr )
	{
		printf ( "Error in allocate memory!" );
		return;
	}
	ScanStr ( cStr ) ;
	do
	{
		Run ( cStr ) ;
	}
	while ( Check ( ) ) ;
	free ( cStr );
}