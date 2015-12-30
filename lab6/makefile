a.out: runner.o function.o
	gcc -g -Wall runner.o function.o -o a.out
runner.o: runner.c list.h
	gcc -g -c -Wall  runner.c 
function.o: function.c  list.h
	gcc -g -c -Wall  function.c
clean:
	 rm *.o a.out

