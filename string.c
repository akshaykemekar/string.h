#include<stdio.h>
#include<stdlib.h>
#include"string1.h"
#include<errno.h>
#include<ctype.h>
#include<time.h>
#include<sys/types.h>
#include<unistd.h>
/*function declartion*/

/*The stringlength calculate the string length*/
int strlen1(char *string) {
	int length_count = 0;
	char *link;
	link = string;
	while(*link != '\0') {
		length_count++;
		link++;
	}
	return length_count;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function is used for comparing both the string*/
int strcmp1(char *str1, char *str2) {
	int comp_value = 0;
	char *first, *second;
	first = str1;
	second = str2;
	while(*first != '\0' || *second != '\0') {
		comp_value = *first - *second;
		if(comp_value != 0)
			break;
		first++;
		second++;
	}
	return comp_value;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*It compare the n string of the two string*/
int strncmp1(char *str1, char *str2, int number) {
	int i = 0, compare_value = 0, len1 = 0, len2 = 0;
	char *first, *second;
	first = str1;
	second = str2;
	len1 = strlen1(str1);
	len2 = strlen1(str2);
	if(number > len1 && number > len2) {
		return -1;
	}
	while(i < number) {
		compare_value = *first - *second;
		if(compare_value != 0)
			break;
		first++;
		second++;
		i++;
	}
	return compare_value;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function comapre the string without considering any cases*/
int strcasecmp1(char *str1 , char *str2) {
	char *p, *q;
	int compare = 0;
	p = str1;
	q = str2;
	while(*p != '\0' || *q != '\0') {
		if(isalpha(*p) && isalpha(*q)) {
			compare = tolower(*p) - tolower(*q);
			if(compare != 0) {
				compare = *p - *q;
				return compare;
			}
		}
		else {
			compare = *p - *q;
			return compare;
		}
		p++;
		q++;
	}
	return compare;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function compare n string without considering any cases*/
int nstrcasecmp1(char *str1, char *str2, int number) {
	char *p, *q;
	int i = 0, compare = 0;
	p = str1;
	q = str2;
	while(i < number) {
		if(isalpha(*p) && isalpha(*q)) {
			compare = tolower(*p) - tolower(*q);
			if(compare != 0) {
				compare = *p - *q;
				return compare;
			}
		}
		else {
			compare = *p - *q;
			return compare;
		}
		p++;
		q++;
		i++;
	}
	return compare;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*It copy second string into first string*/
char *strcpy1(char *str1, char *str2) {
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
char *strncpy1(char *str1, char *str2, int number) {
	int len1, len2, i = 0;
	char *first, *second;
	first = str1;
	second = str2;
	len1 = strlen1(str1);
	len2 = strlen1(str2);
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
char *strcat1(char *str1, char  *str2) {
	int i = 0;
	char *p, *q;
	i = strlen1(str1);
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*This function concanate n character of the str2 with str1*/
char *strncat1(char *str1, char *str2, int number) {
	int i = 0;
	char *p, *q;
	i = strlen1(str1);
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
char *index1(char *str, char c) {
	while(*str != '\0') {
		if(*str == c) 
			return str;
		str++;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**/
char *rindex1(char *str, char c) {
	char *p = 0;
	while(*str != '\0') {
		if(*str == c)
			p = str;
		str++;
	}
	return p;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char *strchr1(char *str, char c) {
	while(*str != '\0') {
		if(*str == c)
			return str;
		str++;
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char *strrchr1(char *str, char c) {
	char *p = 0;
	while(*str != '\0') {
		if(*str == c)
			p = str;
		str++;
	}
	return p;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char *stpcpy1(char *str1, char *str2) {
	while(*str2 != '\0') {
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return str1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char *int_converter(int digit) {
	char *p, *q, ch;
	int d = digit, i = 0, j = 0, reminder;
	p = malloc(20);
	if(p == NULL) {
		perror("allocation failed\n");
		return 0;
	}
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
	i = strlen1(p);
	p = reverse(p);
	p = q;
	return p;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char *reverse(char *str) {
	int length, i = 0;
	char ch;
	length = strlen1(str);
	while(i < length / 2) {
		ch = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = ch;
		i++;
	}
	return str;
}

char *strpbrk1(char *str1, char *str2) {
	char *ts, *tr;
	ts = str1;
	tr = str2;
	while(*ts != '\0') {
		for(tr = str2; *ts != '\0'; tr++) {
			if(*ts == *tr) {
				return ts;
			}
		}
		ts++;
	}
	return NULL;
}

int strspn1(char *str, char *accept) {
	char *p, *q;
	int count = 0;
	p = str;
	q = accept;
	while(*p != '\0') {
		if(*p == *q)
			count++;
		else
			break;
		p++;
		q++;
	}
	return count;
}
int strcasespn1(char *str, char *accept) {
	char *p, *q;
	int count = 0;
	p = str;
	q = accept;
	while(*p != '\0') {
		if(*p == *q || toupper(*p) == *q || tolower(*p) == *q)
			count++;
		else
			break;
		p++;
		q++;
	}
	return count;
}

int strcspn1(char *str, char *reject) {
	char *p, *q;
	p = str;
	q = reject;
	int count = 0;
	while(*p != '\0') {
		for(q = reject; *q != '\0'; q++) {
			if(*p == *q)
				return count;
		}
		count++;
		p++;
	}
	return count;
}

int strcasecspn1(char *str, char *reject) {
	char *p, *q;
	p = str;
	q = reject;
	int count = 0;
	while(*p != '\0') {
		for(q = reject; *q != '\0'; q++) {
			if(*p == *q || toupper(*p) == *q || tolower(*p) == *q)
				return count;
		}
		count++;
		p++;
	}
	return count;
}

char *strdup1(char *str) {
	char *new;
	new = (char*) malloc(strlen1(str) + 1);
	if(new == NULL){
		perror("allocation failed\n");
		return 0;
	}
	strcpy1(new, str);
	return new;
}

char *strndup1(char *str, int n) {
	char *new;
	new = (char*) malloc(n + 1);
	if(new == NULL) {
		perror("allocation failed\n");
		return 0;
	}
	strncpy1(new, str, n);
	return new;
}


char *strstr1(char *str, char *check) {
	char *p, *q, *r;
	p = r = str;
	while(*p != '\0') {
		q = check;
		if(*p == *q) {
			p++;
			q++;
			while(*q != '\0') {
				if(*p == *q) {
					p++;
					q++;
				}
				else
					break;
			}
			if(*q == '\0')
				return r;
		}
		p = ++r;
	}
	return NULL;
}

char *strcasestr1(char *str1, char *str2) {
	char *p, *q, *r;
	p = r = str1;
	while(p != '\0') {
		q = str2;
		if(*p == *q || (tolower(*p) == tolower(*q) && (isalpha(*p) && isalpha(*q)))) {
			p++;
			q++;
			while(*q != '\0') {
				if(*p == *q || tolower(*p) == tolower(*q)) {
					p++;
					q++;
				}
				else
					break;
			}
			if(*q == '\0')
				return r;
		}
		p = ++r;
	}
	return NULL;
}

char *strtok1(char *string, char *token){
	char *p, *q, *new, *r;
	int n, i = 0;
	p = r = string;
	n = strlen1(string);
	new = (char*) malloc(n + 1);
	if(new == NULL) {
		perror("allocation failed\n");
		return 0;	
	}
	while(*p != '\0') {
		q = token;
		if(*p == *q) {
			p++;
			q++;
			while(q != '\0') {
				if(*p == *q) {
					p++;
					q++;
				}
				else
					break;
			}
			if(*q == '\0') {
				new[i] = '\0';
				return new;
			}
		}
		p = r;
		new[i++] = *p;
		p++;
		r++;
	}
	new[i] = '\0';
	return new;
}

int strtok_r1(char *string, char *token, char **store) {
	char *p, *r, *w, **q;
	int len, i = 0;
	p = string;
	q = store;
	while(*p != '\0') {
		store[i] = strtok1(p, token);
		len = strlen1(store[i]);
		p = p + len + 1;
		i++;
		if(i > 80) {
			store = realloc(store, 160);
			if(store == NULL) {
				perror("allocation failed\n");
				return 0;
			}
		}
	}
	return i;
}

char *strfry1(char *str) {
	static int init;
	static struct random_data rdata;
	size_t len, i;
	if(!init) {
		static char state[32];
		rdata.state = NULL;
		initstate_r (time((time_t *) NULL) ^ getpid (), state, sizeof(state), &rdata);
		init = 1;
	}
	len = strlen1(str) - 1;
	for(i = 0; i < len; i++) {
		int32_t j;
		random_r(&rdata, &j);
		j = j % len + 1;
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
	return str;
}

char* getword() {
	char ch, *str;
	int i = 0;
	str = (char*) malloc(80);
	if(str == NULL) {
		perror("allocation failed\n");
		return 0;
	}
	while(scanf("%c", &ch) != -1) {
		str[i++] = ch;
		if(i > 80) {
			str = realloc(str, 160);
			if(str == NULL) {
				perror("reallocation failed\n");
				return 0;
			}
		}
	}
	str[i] = '\0';
	return str;
}

void *memset1(void *s, int c, int count) {
	char *p = s;
	int i = 0;
	while(i < count) {
		*p = c;
		p++;
		i++;
	}
	return s;
}

void *memcpy1(void *mem1, void *mem2, int count) {
	char *p, *q;
	int i = 0;
	p = mem1;
	q = mem2;
	while(i < count) {
		*p = *q;
		p++;
		q++;
		i++;
	}
	return mem1;
}

void *memmove1(void *dest,void *src, int count) {
	char *temp;
	char *s;
	if(dest <= src) {
		temp = dest;
		s = src;
		while(count--)
			*temp++ = *s++;
	}
	else {
		temp = dest;
		temp = temp + count;
		s = src;
		s = s + count;
		while(count--)
			*--temp = *--s;
	}
	return dest;
}

int memcmp1(void *cs, void *ct, int count) {
	char *s1, *s2;
	int race = 0;
	for(s1 = cs, s2 = ct; count > 0; s1++, s2++) {
		if((race = *s1 - *s2) != 0)
			break;
	}
	return race;
}

void *memchr1(void *s, int c, int n) {
	unsigned char *p = s;
	while(n--) {
		if((unsigned char)c == *p++) {
			return (void *) (p - 1);
		}
	}
	return NULL;
}

int countword(char *string) {
	int count = 0;
	char *p;
	while(*p != '\0') {
		if(*p == ' ') {
			count++;
		}
		p++;
	}
	count++;
	return count;
}
