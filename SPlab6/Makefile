CFLAGS=-O2 -ftrapv -fsanitize=undefined -Wall -std=gnu11 -lm -g

solution: myshell.o LineParser.o 
	gcc myshell.o LineParser.o -o solution $(CFLAGS)

myshell.o: myshell.c LineParser.h
	gcc myshell.c -c $(CFLAGS)

LineParser.o: LineParser.c LineParser.h
	gcc LineParser.c -c $(CFLAGS)

clean:
	rm -f *.o solution
