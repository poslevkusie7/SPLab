FLAGS= -g
all: my_echo
my_echo: my_echo.c
	gcc $(FLAGS) my_echo.c -o echo.o 
clean:
	rm -f *.o