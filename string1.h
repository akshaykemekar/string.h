/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/*
 *	ISO C99 Standard: 7.21 String handling	<string.h>
 */


#ifndef	_STRING_H
#define	_STRING_H	1

#include <features.h>

__BEGIN_DECLS


//this function calculate string length//
int stringlen(char*);

//this string compare two string//
int stringcompare(char*, char*);

//this function compare n string//
int nstringcompare(char*, char*, int);

//this function compare without considering case//
int stringcasecmp(char*, char*);

//this function compare n byte without considering case//
int nstringcasecmp(char*, char*, int);

//this function copy first string into second string//
char *stringcopy(char*, char*);

//this function first n byte form first string to other string//
char *nstringcopy(char*, char*, int);

//this function concanate two string//
char *stringcat(char*, char*);

//this function concante n byte from second string//
char *nstringcat(char*, char*, int);

//this function return the pointer when occurence of charecter at first position////this called  also index//
char *findindex(char*, char);

//this fuction return the pointer when occurence of charecter at last position//
char *findrindex(char*, char);

//
char *strchra(char*, char);

//
char *strrchra(char*, char);//

//
char *stpcopy(char*, char*);


int strcoll(char*, char*);

char *int_converter(int);

char *reverse(char*);
#endif
