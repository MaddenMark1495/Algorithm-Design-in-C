all: hw

HW4: runner.o traverse.o
	gcc -g runner.o traverse.o -o hw
runner.o: runner.c traverse.h
	gcc-g runner.c -c
traverse.o: traverse.c traverse.h
	gcc -g traverse.c -c
clean:
	re *.o hw
