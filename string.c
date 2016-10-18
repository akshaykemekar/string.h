#include<stdio.h>
#include<stdlib.h>
/*I am going to write the string.h library function*/
/*Function defination*/
//this function calculate string length//

int stringlen(char*);

///

//this string compare two string//

int stringcompare(char*, char*);

//

//this function compare n string//

int nstringcompare(char*, char*, int);

//

//this function compare without considering case//

int stringcasecmp(char*, char*);

//

//this function compare n byte without considering case//

int nstringcasecmp(char*, char*, int);

//

//this function copy first string into second string//


char *stringcopy(char*, char*);

///

//this function first n byte form first string to other string//

char *nstringcopy(char*, char*, int);

//

//this function concanate two string//

char *stringcat(char*, char*);

//

//this function concante n byte from second string//

char *nstringcat(char*, char*, int);

//

//this function return the pointer when occurence of charecter at first position////this called  also index//

char *findindex(char*, char);

//

//this fuction return the pointer when occurence of charecter at last position//

char *findrindex(char*, char);

//

//

char *strchra(char*, char);

//

//

char *strrchra(char*, char);//

//

char *stpcopy(char*, char*);

//

//
int strcoll(char*, char*);

//

///this function convert digit to string//

char *int_converter(int);

///

char *reverse(char*);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*The stringlength calculate the string length*/
int stringlen(char *string) {
	int length_count = 0;
	char *link;
	link = string;
	while(*link != '\0') {
		length_count++;
		link++;
	}
	return length_count;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function is used for comparing both the string*/
int stringcompare(char *str1, char *str2) {
	int comp_value = 0;
	char *first, *second;
	first = str1;
	second = str2;
	while(*first != '\0' || *second != '\0') {
		comp_value = *first - *second;
		first++;
		second++;
	}
	return comp_value;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*It compare the n string of the two string*/
int nstringcompare(char *str1, char *str2, int number) {
	int i = 0, compare_value = 0, len1 = 0, len2 = 0;
	char *first, *second;
	first = str1;
	second = str2;
	len1 = stringlen(str1);
	len2 = stringlen(str2);
	if(number > len1 && number > len2) {
		return -1;                            // i have to write here error function remind me//
	}
	while(i < number) {
		compare_value = *first - *second;
		first++;
		second++;
		i++;
	}
	return compare_value;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function comapre the string without considering any cases*/
int stringcasecmp(char *str1 , char *str2) {
	int i = 0, com = 0, diff = 0;
	diff = 'a' - 'A';
	while(str1[i] != '\0' || str2[i] != '\0') {
		if((str1[i] < 'A' || str1[i] > 'Y') && (str1[i] < 'a' || str1[i] > 'y') && (str2[i] < 'A' || str2[i] > 'Y') && (str2[i] < 'a' || str2[i] > 'y')) {
			com = str1[i] - str2[i];
			i++;
		}
		else {
			if((str1[i] - str2[i]) == diff || (str2[i] - str1[i]) == diff) {
				com = 0;
				i++;
			}
			else {
				com = str1[i] - str2[i];
				i++;
			}
		}
	}
	return com;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function compare n string without considering any cases*/
int nstringcasecmp(char *str1, char *str2, int number) {
	int i = 0, com = 0, diff = 0;
        diff = 'a' - 'A';
        while((i < number) && (str1[i] != '\0' || str2[i] != '\0')) {
                if((str1[i] < 'A' || str1[i] > 'Y') && (str1[i] < 'a' || str1[i] > 'y') && (str2[i] < 'A' || str2[i] > 'Y') && (str2[i] < 'a' || str2[i] > 'y')) {
                        com = str1[i] - str2[i];
                        i++;
                }
                else {
                        if((str1[i] - str2[i]) == diff || (str2[i] - str1[i]) == diff) {
                                com = 0;
                                i++;
                        }
                        else {
                                com = str1[i] - str2[i];
                                i++;
                        }
                }
        }
        return com;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*It copy second string into first string*/
char *stringcopy(char *str1, char *str2) {
	char *first, *second;
	first = str1;
	second = str2;
	while(*second != '\0') {
		*first = *second;
		first++;
		second++;
	}
	*first = '\0';
	return str1;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function copy n character from str2 to str1*/
char *nstringcopy(char *str1, char *str2, int number) {
	int len1, len2, i = 0;
	char *first, *second;
	first = str1;
	second = str2;
	len1 = stringlen(str1);
	len2 = stringlen(str2);
	if(number > len2)
		return str2;
	while(i < number) {
		*first = *second;
		first++;
		second++;
		i++;
	}
	*first = '\0';
	return str1;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function concanate the two string*/
char *stringcat(char *str1, char  *str2) {
	int i = 0;
	char *p, *q;
	i = stringlen(str1);
	p = &str1[i];
	q = str2;
	while(*q != '\0') {
		*p = *q;
		p++;
		q++;
	}
	*p = '\0';
	return str1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function concanate n character of the str2 with str1*/
char *nstringcat(char *str1, char *str2, int number) {
	int i = 0;
	char *p, *q;
	i = stringlen(str1);
	p = &str1[i];
	q = str2;
	i = 0;
	while(i < number){
		*p = *q;
		p++;
		q++;
		i++;
	}
	*p = '\0';
	return str1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function return the string pointer when find c charecter in string*///this index function
char *findindex(char *str, char c) {
	while(*str != '\0') {
		if(*str == c) 
			return str;
		str++;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**/
char *findrindex(char *str, char c) {
	char *p = 0;
	while(*str != '\0') {
		if(*str == c)
			p = str;
		str++;
	}
	return p;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char *strchra(char *str, char c) {
	while(*str != '\0') {
		if(*str == c)
			return str;
		str++;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char *strrchra(char *str, char c) {
	char *p = 0;
	while(*str != '\0') {
		if(*str == c)
			p = str;
		str++;
	}
	return p;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char *stpcopy(char *str1, char *str2) {
	while(*str2 != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str1;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int strcoll(char *str1, char *str2) {

}

char *int_converter(int digit) {
	char *p, *q, ch;
	int d = digit, i = 0, j = 0, reminder;
	p = malloc(20);
	q = p;
	if(digit < 0) {
		q[0] = '-';
		d = -d;
		p++;
	}
	for(i = 10; d != 0; j++) {
		reminder = d % i;
		d = d / i;
		switch(reminder) {
			case 1:
				p[j] = '1';
				break;
			case 2:
				p[j] = '2';
				break;
			case 3:
				p[j] = '3';
				break;
			case 4:
				p[j] = '4';
				break;
			case 5:
				p[j] = '5';
				break;
			case 6:
				p[j] = '6';
				break;
			case 7:
				p[j] = '7';
				break;
			case 8:
				p[j] = '8';
				break;
			case 9:
				p[j] = '9';
				break;
			default:
				p[j] = '0';
		}
	}
	p[j] = '\0';
	i = stringlen(p);
	p = reverse(p);
	p = q;
	return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char *reverse(char *str) {
	int length, i = 0;
	char ch;
	length = stringlen(str);
	while(i < length / 2) {
		ch = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = ch;
		i++;
	}
	return str;
}



