all: 1a 1b my_echo HelloWorld.c

1a: 1a.c
	gcc -m32 -g -Wall -c -o 1a.o 1a.c 
1b: 1b.c
	gcc -m32 -g -Wall -c -o 1b.o 1b.c 

HelloWorld: HelloWorld.c
	gcc -m32 -g -Wall -c -o HelloWorld.o HelloWorld.c 

my_echo: my_echo.c
	gcc -m32 -g -Wall -c -o my_echo.o my_echo.c 
	
clean: 
	rm -f *.o 

 

 

