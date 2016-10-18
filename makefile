string: string.c main.c
	cc -c string.c main.c
	cc string.o main.o -o string
	./string
