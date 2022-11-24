all: 0c 0s 1c 1s 2c 2s

0c:
	gcc -m32 -g -Wall -c -o 0c.o 0.c 
0s:
	nasm -felf64 -o 0s.o 0.s 

1c:
	gcc -m32 -g -Wall -c -o 1c.o 1.c 

1s:
	nasm -felf64 -o 1s.o 1.s 

2c:
	gcc -m32 -g -Wall -c -o 2c.o 2.c 

2s:
	nasm -felf64 -o 2s.o 2.s 

clean: 
	rm -f *.o 
