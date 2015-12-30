all:plane

plane:runner.o lib.o
	gcc -g runner.o lib.o -o plane
runner.o: runner.c lib.h
	gcc -g runner.c -c
lib.o: lib.c lib.h
	gcc -g lib.c -c
clean:
	re*.o plane
