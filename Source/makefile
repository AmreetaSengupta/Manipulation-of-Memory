memfun : main.o help.o exit.o allocate.o free.o write.o invert.o ../Include/main.h ../Include/help.h ../Include/allocate.h ../Include/exit.h ../Include/free.h ../Include/write.h ../Include/invert.h
		gcc -o memfun main.o help.o allocate.o free.o exit.o write.o invert.o

main.o : main.c ../Include/main.h ../Include/help.h  ../Include/allocate.h ../Include/exit.h ../Include/free.h ../Include/write.h ../Include/invert.h
	gcc -c main.c

help.o: help.c ../Include/help.h
	gcc -c help.c 
	
allocate.o: allocate.c ../Include/allocate.h
	gcc -c allocate.c 
	
free.o: free.c ../Include/free.h ../Include/allocate.h
	gcc -c free.c

write.o: write.c ../Include/write.h ../Include/allocate.h
	gcc -c write.c
	
invert.o: invert.c ../Include/invert.h ../Include/allocate.h
	gcc -c invert.c
	
exit.o: exit.c ../Include/exit.h
	gcc -c exit.c
