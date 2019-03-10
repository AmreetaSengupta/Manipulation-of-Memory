memfun : main.o help.o exit.o allocate.o free.o write.o write_pattern.o verify_pattern.o invert.o display.o random_generator.o ../Include/main.h ../Include/help.h ../Include/allocate.h ../Include/exit.h ../Include/free.h ../Include/write.h ../Include/write_pattern.h ../Include/invert.h  ../Include/display.h ../Include/random_generator.h ../Include/verify_pattern.h
		gcc -o memfun main.o help.o allocate.o free.o exit.o write.o write_pattern.o invert.o display.o random_generator.o verify_pattern.o

main.o : main.c ../Include/main.h ../Include/help.h  ../Include/allocate.h ../Include/exit.h ../Include/free.h ../Include/write.h ../Include/write_pattern.h ../Include/invert.h  ../Include/display.h ../Include/random_generator.h ../Include/verify_pattern.h
	gcc -c main.c

help.o: help.c ../Include/help.h
	gcc -c help.c 
	
allocate.o: allocate.c ../Include/allocate.h
	gcc -c allocate.c 
	
free.o: free.c ../Include/free.h ../Include/allocate.h
	gcc -c free.c
	
random_generator.o: random_generator.c ../Include/random_generator.h
	gcc -c random_generator.c

write.o: write.c ../Include/write.h ../Include/allocate.h
	gcc -c write.c
	
write_pattern.o: write_pattern.c ../Include/write_pattern.h ../Include/allocate.h ../Include/random_generator.h
	gcc -c write_pattern.c
	
verify_pattern.o: verify_pattern.c ../Include/verify_pattern.h ../Include/write_pattern.h ../Include/allocate.h ../Include/random_generator.h
	gcc -c verify_pattern.c
	
invert.o: invert.c ../Include/invert.h ../Include/allocate.h
	gcc -c invert.c
	
display.o: display.c ../Include/display.h ../Include/allocate.h
	gcc -c display.c
	
exit.o: exit.c ../Include/exit.h
	gcc -c exit.c

test: memfun test.txt
		./memfun <test.txt

clean : 	
	rm -f memfun main.o help.o exit.o allocate.o free.o write.o write_pattern.o invert.o display.o random_generator.o verify_pattern.o
