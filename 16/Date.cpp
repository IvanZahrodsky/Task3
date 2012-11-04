/**
*@file		Date.cpp
*@brief		This file contains implementations of function according to task 16
*			
*
*
*	Copyrights 2012 by IvanZahrodsky.
*/

#include "stdafx.h"

/**
*@brief		This function allocates memory
*@param		[uiPtr,cCnt] 
*@return	bool 
*/
bool Init ( UI* &uiPtr , UC &cCnt )
{
	char buf [ 3 ] ;
	printf ( "(Note: \"If you entered more characters, not need will be removed\")\n");
	printf ( "\nEnter please count of dates:\n" ) ;
	while ( !scanf ( "%2[0-9]s", buf ) )
	{
		fflush ( stdin ) ;
		printf ( "Error in scaning count!!\n" );
		printf ( "Enter again:  " ) ;
	}
	fflush ( stdin ) ;
	cCnt = atoi ( buf );
	printf ( "\nYou enter the number %d !\n" , cCnt ) ;
	if ( cCnt == 0)
	{
		printf ( "\nGoodbye! =) \n");
		return false;
	}
	try
	{
		uiPtr = ( UI* ) malloc ( sizeof ( UI ) * 4 ) ;
	}
	catch (...)
	{
		printf ( "\nMemory allocation failed!!\n" );
		return false;
	}

	return true;
}
/**
*@brief		This function scaning date from keyboard
*@param		[uiPtr , cCNt] 
*@return	void
*/
void ScanDate ( UI *uiPtr , UI cCnt)
{
	char buf[5];
	MyDate mdTmp;
	UI tmp = -1;
	UC mnth[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
	for ( UI i = 0 ; i < cCnt ; i++ )
	{
		printf ("\nEnter date No. %u :\n" , i + 1 ) ;
		printf ("\nEnter please day [1-31]:  ");
		do
		{
			if ( !scanf ("%2[0-9]s" , buf ) )
			{
				fflush(stdin);
				printf("Error enter again:  ");
				continue;
			}
			fflush(stdin);
			tmp = atoi ( buf ) ;
			if ( ! (( tmp + 1 ) > 32 ) )
			{
				break;
			}
			printf("Error enter again:  ");
		}
		while( true );
		mdTmp.d.day = tmp ;
		printf ("\nEnter please month [1-12]:\n");
		do
		{
			if ( !scanf ("%2[0-9]s" , buf ) )
			{
				fflush(stdin);
				printf("Error enter again:  ");
				continue;
			}
			fflush(stdin);
			tmp = atoi ( buf ) ;
			if ( mnth[ tmp -1 ] < mdTmp.d.day && ( tmp + 1) < 13)
			{
				printf ("\nError! The month No. %d can not have %d days!!", tmp, mdTmp.d.day ) ;
				printf ("\nEnter month again:  ");
				continue;
			}
			if ( ! (( tmp + 1 ) > 13 ) )
			{
				break;
			}
			printf("Error enter again:  ");
		}
		while( true ) ;
		mdTmp.d.month = tmp ;
		printf ("\nEnter please year [1-9999]:\n");
		do
		{
			if ( !scanf ("%4[0-9]s" , buf ) )
			{
				fflush(stdin);
				printf("Error enter again:  ");
				continue;
			}
			fflush(stdin);
			tmp = atoi ( buf ) ;
			if ( mdTmp.d.day == 29 && mdTmp.d.month == 2  
				 && ( tmp % 4 != 0 ) )
			{
				printf ("\nError! Must be leap year!!" ) ;
				printf ("\nEnter year again:  ");
				continue;
			}
			if ( tmp  > 0 )
			{
				break;
			}
			printf("Error enter again:  ");
		}
		while( true ) ;
		mdTmp.d.year = tmp;
		uiPtr[i] = mdTmp.uiDate ;
	}
	return ;
}

/**
*@brief		This function calculates res
*@param		[uiPtr , cCNt] 
*@return	void
*/
void CalcRes ( UI *uiPtr , UI cCnt ) 
{
	UC mnth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ;
	MyDate temp;
	for ( UI i = 0 ; i < cCnt ; i++ )
	{
		temp.uiDate = uiPtr [ i ] ;
		temp.d.dnum = 0;
		for ( UI j = 0 ; j < temp.d.month - 1 ; j++ )
		{
			temp.d.dnum += mnth [ j ] ;
		}
		temp.d.dnum += temp.d.day ;
		if ( temp.d.month > 2 && IsLeap (temp.d.year) )
		{
			temp.d.dnum++;
		}
		uiPtr [ i ] = temp.uiDate ;
	}
	return ;
}
/**
*@brief		This function print res
*@param		[uiPtr , cCNt] 
*@return	void
*/
void PrintRes ( UI *uiPtr , UI cCnt ) 
{
	MyDate tmp;
	printf ("Result:\n\tDay:\tMonth:\tYear:\tNumber of days:\n");
	for ( UI i = 0; i< cCnt ; i++)
	{
		tmp.uiDate = uiPtr [i];
		printf ("\n\t%4d\t%6d\t%5d\t\t%7d\n" ,tmp.d.day , tmp.d.month , tmp.d.year , tmp.d.dnum);
	}
	return ;
}

/**
*@brief		This function check is the year leap
*@param		[UI] 
*@return	bool
*/
bool IsLeap ( UI temp )
{
	if (temp % 400 == 0 )
	{
		return true;
	}
	else if ( temp % 100 == 0 )
	{
		return false;
	}
	else if ( temp % 4 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
