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
 *	ISO C99 Standard: 7.21 String handling	<string1.h>
 */


#ifndef	_STRING_H
#define	_STRING_H	1

__BEGIN_DECLS


/*
@ strlen1 - calculate the length of a string
@ The strlen1() function calculates the length of the string str, excluding the terminating null byte ('\0')
*/
int strlen1(char *str);


/*
@ strcmp1, strncmp1 - compare two strings
@ strcmp1() function compare the two strings str1 and str2.
@ it return an integer less than, equal to, or greater than zero
@ strncmp1 - compare n byte of two strings
*/
int strcmp1(char *str1, char *str2);
int strncmp1(char *str1, char *str2, int n);


/*
@ strcasecmp1 - compare two strings ignoring case
@ nstrcasecmp1 - compare n byte of two strings ignoring case
*/
int strcasecmp1(char *str1, char *str2);
int nstrcasecmp1(char *str1, char *str2, int n);


/*
@ strcpy1, strncpy1 - copy a string
@ The strcpy1() function copies the string pointed to by str2,
including the terminating null byte ('\0'), to the buffer pointed by str1.
@ strncpy1 - copy n bytes of str2 to str1.
*/
char *strcpy1(char *str1, char *str2);
char *strncpy1(char *str1, char *str2, int n);


/*
@ strcat1, strncat1 - cancatenate two strings
@ The strcat1() function appends the str2 string to the str1 string,
overwriting the terminating null byte ('\0') at the end of str1,
and then adds a terminating null byte.
@strncat1 - concatenate n byte of str2 to the str1.
*/
char *strcat1(char *str1, char *str2);
char *strncat1(char *str1, char *str2, int n);



/*
@ index1, rindex - locate character in string
@ The index1() function returns a pointer to the
first occurrence of the character ch in the string str.
@ The rindex1() function returns a pointer to the last
occurrence of the character ch in the string str.
*/
char *index1(char *str, char ch);
char *rindex1(char *str, char ch);


/*
@ strchr1, strrchr1 - locate character in string
@ The strchr() function returns a pointer to the
first occurrence of the character ch in the string str.
@strrchr() function return a pointer to the last occurrence ch in the string str. 
*/
char *strchr1(char *str, char ch);
char *strrchr1(char *str, char ch);


/*
@ stpcpy1 - copy a string returning a pointer to its end
@ The strcpy() function copies the string to by str2 
(including the terminating null byte('\0')) to the array pointed to by str1.
The strings may not overlap, and the destination string str1 must be large enough
to receive the copy.
*/
char *stpcpy1(char *str1, char *str2);


/**/
int strcoll1(char*, char*);


/*
@ int_converter - This function convert int number into string
@ int_converter function convert int number into string
which you treat like string
*/
char *int_converter(int);

/*
@ reverse - reverse the string
@ This function reverse the string
*/
char *reverse(char*);


/*
@ strpbrk1 - search a string for any of a set of bytes.
@ The strpbrk1() function locates the first occurrence in the string str
of any of the bytes in the string accept.
*/
char *strpbrk1(char *str, char *accept);


/*
@ strspn1, strcspn1 - get length of a prefix substring.
@ The strspn1() function calculate the length(in bytes) of the
intial segment of str which consists entirely of bytes in accept.
@ The strcspn1() function calculate the length(in bytes) of the
initial segment of str which consits entirely of bytes not in reject.
@ strcasespn1, strcasecspn1 - its do same as strspn1, strcspn1 with ignoring case.
*/
int strspn1(char *str, char *accept);
int strcasespn1(char *str, char *accept);
int strcspn1(char *str, char *reject);
int strcasecspn1(char *str, char *reject);


/*
@ strdup1, strndup1 - duplicating a string
@ The strdup1() function return a pointer to a
new string which is a duplicate of the string str.
Memory for the new string is obtained with malloc(), 
and can be freed with  free().
@ The strndup1() function is similar, but copies at most n bytes.
*/
char *strdup1(char *str);
char *strndup1(char *str, int n);


/*
@ strstr1, strcasestr1 - locate a substring
@ The strstr1() function finds the first occurrence
of the substring str2 in the string str1. The terminating
null byte('\0') are not compared.
@ The strcasestr1() function is like strstr(), but ignores the caseof both arguments.
*/
char *strstr1(char *str1, char *str2);
char *strcasestr1(char *str1, char *str2);

/*
@ strtok, strtok_r - extract tokens from strings
@ The strtok() function breaks a string into a sequence of zero or
more nonempty tokens. On the first call to strtok() the string to
be parsed should be specified in str.
In each subsequent call that should parse the same string, str must be NULL.
@ The strtok_r1 function do same string as strtok, but it return string store in subsequent addresses.
*/
char *strtok1(char *str, char *token);
int strtok_r1(char *str, char *token, char **store);

/*
@ strfry1 - randomize the string
@ The  strfry() function randomizes the contents of string by using random_r(3) 
to randomly swap characters in the string.  The result is an anagram of string
*/
char *strfry1(char *str);

/*
@ memset - fill memory with a constant byte
@  The  memset()  function  fills  the  first  n  bytes of the memory area
   pointed to by s with the constant byte c.
*/
void *memset1(void *s, int c, int n);

/*
@ memcpy - copy memory area
@ The  memcpy()  function  copies  n bytes from memory area mem2 to memory
  area mem1.  The memory areas must not overlap.  Use memmove()  if  the
  memory areas do overlap.
*/
void *memcpy1(void *mem1, void *mem2, int n);

/*
@ memmove - copy memory area
@ The  memmove()  function  copies n bytes from memory area src to memory
  area dest.  The memory areas may overlap: copying takes place as though
  the  bytes in src are first copied into a temporary array that does not
  overlap src or dest, and the bytes are then copied from  the  temporary
  array to dest.
*/
void *memmove1(void *dest, void *src, int n);

/*
@ memcmp - compare memory areas
@ The  memcmp()  function compares the first n bytes of the memory areas s1 and s2.
*/
int memcmp1(void *cs, void *ct, int n);

/*
@ memchr - scan memory for a character
@ The  memchr()  function  scans  the  initial n bytes of the memory area
 pointed to by s for the first instance of c.  Both c and the  bytes  of
 the memory area pointed to by s are interpreted as unsigned char.

*/
void *memchr1(void *s, int c, int n);

/*
@ getword - get the line
@ This function get the line and convert into the string of line
*/
char *getword();

/*
@ countword - count the number of words
@ this function count the total number of words in the line of string
seperated by space
*/
int countword(char *string);

#endif
