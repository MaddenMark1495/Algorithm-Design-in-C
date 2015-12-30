a.out: runner.o function.o
	gcc runner.o function.o -o a.out
runner.o: runner.c set.h
	gcc -c  runner.c 
function.o: function.c  set.h
	gcc -c  function.c
clean:
	 rm* .o a.out
