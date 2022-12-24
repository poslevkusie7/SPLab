CFLAGS=-O2 -ftrapv -fsanitize=undefined -Wall -std=gnu11 -lm -g
all: task0 task2 solution myshell.o LineParser.o 
task0:
	gcc -g -Wall -o task0.o task0.c 

task2:
	gcc -g -Wall -o task2.o task2.c 

solution: myshell.o LineParser.o 
	gcc myshell.o LineParser.o -o solution $(CFLAGS)

myshell.o: myshell.c LineParser.h
	gcc myshell.c -c $(CFLAGS)

LineParser.o: LineParser.c LineParser.h
	gcc LineParser.c -c $(CFLAGS)

clean:
	rm -f *.o solution
