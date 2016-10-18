#include<stdio.h>
#include"string1.h"

void call(){
	printf("1->stringlen\n");
	printf("2->stringcopy\n");
	printf("3->nstringcopy\n");
	printf("4->stringcompare\n");
	printf("5->nstringcompare\n");
	printf("6->stringcasecmp\n");
	printf("7->nstringcasecmp\n");
	printf("8->stringcat\n");
	printf("9->nstringcat\n");
}
int main() {
	char A[20], B[20], c;
	int length, option, n, d;
	call();
	while(scanf("%d", &option) != -1) {
		switch(option) {
			case 1:
				while(scanf("%s", A) != -1) {
					length = stringlen(A);
					printf("%d\n", length);
				}
				break;
			case 2:
				while(scanf("%s%s", A, B) != -1) {
					stringcopy(A, B);
					printf("%s\n", A);
				}
				break;
			case 3:
				while(scanf("%s%s%d", A, B, &n) != -1) {
                                        nstringcopy(A, B, n);
                                        printf("%s\n", A);
                                }
                                break;
			case 4:
				while(scanf("%s%s", A, B) != -1) {
                                       n = stringcompare(A, B);
                                        if(n > 0)
						printf("A is bigger than B\n");
					else {
						if(n < 0)
							printf("A is smaller than B\n");
						else
							printf("both are equal\n");
					}
                                }
                                break;
			case 5:
				 while(scanf("%s%s%d", A, B, &d) != -1) {
                                       n = nstringcompare(A, B, d);
                                        if(n > 0)
                                                printf("A is bigger than B\n");
                                        else {
                                                if(n < 0)
                                                        printf("A is smaller than B\n");
                                                else
                                                        printf("both are equal\n");
                                        }
                                }
                                break;
			case 6:
				 while(scanf("%s%s", A, B) != -1) {
                                       n = stringcasecmp(A, B);
                                        if(n > 0)
                                                printf("A is bigger than B\n");
                                        else {
                                                if(n < 0)
                                                        printf("A is smaller than B\n");
                                                else
                                                        printf("both are equal\n");
                                        }
                                }
                                break;
			case 7:
				 while(scanf("%s%s%d", A, B, &d) != -1) {
                                       n = nstringcasecmp(A, B, d);
                                        if(n > 0)
                                                printf("A is bigger than B\n");
                                        else {
                                                if(n < 0)
                                                        printf("A is smaller than B\n");
                                                else
                                                        printf("both are equal\n");
                                        }
                                }
                                break;
			case 8:
				while(scanf("%s%s", A, B) != -1) {
                                        stringcat(A, B);
                                        printf("%s\n", A);
                                }
                                break;
			case 9:
				while(scanf("%s%s%d", A, B, &d) != -1) {
                                        nstringcat(A, B, d);
                                        printf("%s\n", A);
                                }
                                break;
		}
		call();
	}
}
