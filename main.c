#include<stdio.h>
#include"string1.h"
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct strings {
	char name[15][16];
	int n;
}strings;

void info(char *str) {
	int fd;
	char ch;
	fd = open(str, O_RDONLY);
	if(fd == -1) {
		perror("usage:- ./string -h\n");
		return;
	}
	while(read(fd, &ch, 1))
		printf("%c", ch);
	close(fd);
}

int *token(strings *a, char *str, int *p) {
	char *temp;
	int i, j;

	for(i = 0; i < 15; i++) {
		for(j = 0; j < a[i].n; j++) {
			temp = a[i].name[j];
			if(!strcmp1(str, temp)) {
				p[0] = i;
				p[1] = j;
				return p;
			}
		}
	}
}
int main(int argc, char *argv[]) {
	if(argc > 1) {
		if(!strcmp1(argv[1], "-h"))
			argv[1] = "usage";
		info(argv[1]);
		return 0;
	}
	FILE *fp;
	fp = fopen("input.txt", "r");
	char function[80], getone[80], gettwo[80], ch, *char_output, **store, *m, *n;
	int *gettoken, p[2], int_output, get1, get2, i = 0;
	void *one, *two, *three;
	strings a[15] = {{{"strlen1", "countword"}, 2},
                        {{"int_converter"}, 1},
                        {{"strcmp1", "strcasecmp1", "strspn1", "strcspn1", "strcasespn1", "strcasecspn1"}, 6},
                        {{"strncmp1", "nstrcasecmp1"}, 2},
                        {{"reverse", "strdup1", "strfry1"}, 3},
                        {{"strndup1"}, 1},
                        {{"strcpy1", "strcat1", "stpcpy1", "strpbrk1", "strstr1", "strcasestr1", "strtok1"}, 7},
                        {{"strncpy1", "strncat1"}, 2},
                        {{"index1", "rindex1", "strchr1", "strrchr1"}, 4},
                        {{"strtok_r1"}, 1},
                        {{"memset1", "memchr1"}, 3},
                        {{"memcpy1", "memmove1"}, 2},
                        {{"memcmp1"} , 1}};


	int (*fp1[])(char*) = {strlen1, countword};
	char* (*fp2[])(int) = {int_converter};
	int (*fp3[])(char*, char*) = {strcmp1, strcasecmp1, strspn1, strcspn1, strcasespn1, strcasecspn1};
	int (*fp4[])(char*, char*, int) = {strncmp1, nstrcasecmp1};
	char*(*fp5[])(char*) = {reverse, strdup1, strfry1};
	char*(*fp6[])(char*, int) = {strndup1};
	char*(*fp7[])(char*, char*) = {strcpy1, strcat1, stpcpy1, strpbrk1, strstr1, strcasestr1, strtok1};
	char*(*fp8[])(char*, char*, int) = {strncpy1, strncat1};
	char*(*fp9[])(char*, char) = {index1, rindex1, strchr1, strrchr1};
	int(*fp10[])(char*, char*, char**) = {strtok_r1};
	void*(*fp11[])(void*, int, int) = {memset1, memchr1};
	void*(*fp12[])(void*, void*, int) = {memcpy1, memmove1};
	int (*fp13[])(void*, void*, int) = {memcmp1};

	while((fscanf(fp, "%s", function)) != EOF) {
		printf("%s\n", function);
		gettoken = token(a, function, p);
		switch(gettoken[0] + 1) {
			case 1:
				fscanf(fp, "%s", getone);
				printf("%s\n", getone);
				int_output = fp1[gettoken[1]](getone);
				printf("%d\n", int_output);
				break;
			case 2:
				fscanf(fp, "%d", &get1);
				printf("%d\n", get1);
				char_output = fp2[gettoken[1]](get1);
				printf("%s\n", char_output);
				break;
			case 3:
				fscanf(fp, "%s%s", getone, gettwo);
				printf("%s %s\n", getone, gettwo);
				int_output = fp3[gettoken[1]](getone, gettwo);
				printf("%d\n", int_output);
				break;
			case 4:
				fscanf(fp, "%s%s%d", getone, gettwo, &get1);
				printf("%s %s %d\n", getone, gettwo, get1);
				int_output = fp4[gettoken[1]](getone, gettwo, get1);
				printf("%d\n", int_output);
				break;
			case 5:
				fscanf(fp, "%s", getone);
				printf("%s\n", getone);
				char_output = fp5[gettoken[1]](getone);
				printf("%s\n", char_output);
				break;
			case 6:
				fscanf(fp, "%s%d", getone, &get1);
				printf("%s\n", getone);
				char_output = fp6[gettoken[1]](getone, get1);
				printf("%s\n", char_output);
				break;
			case 7:
				fscanf(fp, "%s%s", getone, gettwo);
				printf("%s %s\n", getone, gettwo);
				char_output = fp7[gettoken[1]](getone, gettwo);
				printf("%s\n", char_output);
				break;
			case 8:
				fscanf(fp, "%s%s%d", getone, gettwo, &get1);
				printf("%s %s %d\n", getone, gettwo, get1);
				char_output = fp8[gettoken[1]](getone, gettwo, get1);
				printf("%s\n", char_output);
				break;
			case 9:
				fscanf(fp, "%s%s", getone, gettwo);
				printf("%s %s\n", getone, gettwo);
				char_output = fp9[gettoken[1]](getone, *gettwo);
				printf("%s\n", char_output);
				break;
			case 10:
				fscanf(fp, "%s%s", getone, gettwo);
				printf("%s %s\n", getone, gettwo);
				store = (char**) malloc(80);
				int_output = fp10[gettoken[1]](getone, gettwo, store);
				printf("%d\n", int_output);
				i = 0;
				while(i < int_output) {
					printf("%s\n", store[i]);
					i++;
				}
				break;
			case 11:
				fscanf(fp, "%s%d%d", getone, &get1, &get2);
				printf("%s %d %d\n", getone, get1, get2);
				two = getone;
				one = fp11[gettoken[1]](two, get1, get2);
				m = (char*)one;
				printf("%s\n", m);
				break;
			case 12:
				if(!strcmp1(function, "memcpy1")) {
					fscanf(fp, "%s%d", gettwo, &get1);
					m = malloc(get1 + 1);
					two = gettwo;
					printf("%s %s\n",m, gettwo);
					one = fp12[gettoken[1]](m, two, get1);
					m = (char*)one;
					n = (char*)two;
					printf("%s %s\n", m, n);
					break;
				}
				fscanf(fp, "%s%s%d", getone, gettwo, &get1);
				printf("%s %s\n", getone, gettwo);
				two = getone;
				three = gettwo;
				one = fp12[gettoken[1]](two, three, get1);
				m = (char*) one;
				n = (char*) three;
				printf("%s %s\n", m, n);
				break;
			case 13:
				fscanf(fp, "%s%s%d", getone, gettwo, &get1);
				printf("%s %s %d\n", getone, gettwo, get1);
				two = getone;
				three = gettwo;
				int_output = fp13[(gettoken[1])](two, three, get1);
				printf("%d\n", int_output);
				break;
		}
	}

	fclose(fp);
	return 0;
}
