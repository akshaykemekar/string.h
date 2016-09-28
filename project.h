#include<stdio.h>
/*I am going to write the string.h library function*/
/*Function defination*/
int stringlength(char*);
int stringcompare(char*, char*);
int nstringcompare(char*, char*, int);
int stringcasecmp(char*, char*);
int nstringcasecmp(char*, char*, int);
void stringcopy(char*, char*);
void nstringcopy(char*, char*, int);
void stringcat(char*, char*);
void nstringcat(char*, char*, int);
char *findindex(char*, char);//this function return the pointer when occurence of charecter at position////this called  also index//
char *findrindex(char*, char);
char *strchra(char*, char);
char *strrchra(char*, char);
char *stpcopy(char*, char*);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Function declaration*/
/*The stringlength calculate the string length*/
int stringlength(char *string) {
	int len = 0;
	while(string[len] != '\0')
		len++;
	return len;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function is used for comparing both the string*/
int stringcompare(char *str1, char *str2) {
	int comp_value = 0, i = 0;
	while(str1[i] != '\0' || str2[i] != '\0') {
		comp_value = str1[i] - str2[i];
		i++;
	}
	return comp_value;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*It compare the n string of the two string*/
int nstringcompare(char *str1, char *str2, int number) {
	int i = 0, com = 0, len1 = 0, len2 = 0;
	while(str1[len1] != '\0')
		len1++;
	while(str2[len2] != '\0')
		len2++;
	if(len1 < number && len2 < number) {
		return -1;                            // i have to write here error function remind me//
	}
	while(i < number) {
		com = str1[i] - str2[i];
		i++;
	}
	return com;
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
void stringcopy(char *str1, char *str2) {
	int i = 0;
	while(str2[i] != '\0') {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function copy n character from str2 to str1*/
void nstringcopy(char *str1, char *str2, int number) {
	int i = 0;
	while(i < number && str2[i] != '\0') {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function concanate the two string*/
void stringcat(char *str1, char  *str2) {
	int i = 0, j = 0;
	while(i >= 0) {
		if(str1[i] == '\0') {
			for(j = 0; str2[j] != '\0'; j++)
				str1[j + i] = str2[j];
			str1[i + j] = '\0';
			break;
		}
		i++;
	}
	str1[i + j] = '\0';
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function concanate n character of the str2 with str1*/
void nstringcat(char *str1, char *str2, int number) {
	int i = 0, j = 0;
	while(i >= 0) {
		if(str1[i] == '\0') {
			for(j = 0; j < number && str2[j] != '\0'; j++)
				str1[i + j] = str2[j];
			str2[j] = '\0';
			break;
		}
		i++;
	}
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








