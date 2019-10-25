all: somaMaxima.c 
	gcc -g -Wall -o somaMaxima somaMaxima.c

clean: 
	$(RM) somaMaxima