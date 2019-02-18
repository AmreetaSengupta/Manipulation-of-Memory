memfun : main.o help.o exit.o ../Include/main.h ../Include/help.h ../Include/exit.h
		gcc -o memfun main.o help.o exit.o

main.o : main.c ../Include/main.h ../Include/help.h ../Include/exit.h
	gcc -c main.c

help.o: help.c ../Include/help.h
	gcc -c help.c 

ext.o: exit.c ../Include/exit.h
	gcc -c exit.c
