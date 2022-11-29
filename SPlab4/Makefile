all: 0 1

0:
	nasm -f elf 0.asm
	gcc -m32 -o 0.out 0.o*
1:
	nasm -f elf 1.asm
	gcc -m32 -o 1.out 1.o*

clean: 
	rm -f *.o *.out
