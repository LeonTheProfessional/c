calculate:main.o calculate.o
	gcc -o calculate main.o calculate.o
main.o:main.c
	gcc -o main.o -c main.c
calculate.o:calculate.c
	gcc -o calculate.o -c calculate.c
.PHONY:rebuild clean
rebuild:clean calculate
clean:
	rm -rf main.o calculate.o calculate
