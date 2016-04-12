all:programa limpa

programa:main.o logica.o entrada.o lista.o
	gcc main.o logica.o entrada.o lista.o -o elevador

main.o:main.c logica.c logica.h entrada.c entrada.h lista.c lista.h
	gcc -c main.c 

logica.o:logica.c logica.h
	gcc -c logica.c

entrada.o:entrada.c entrada.h
	gcc -c entrada.c

lista.o:lista.c lista.h
	gcc -c lista.c

limpa:
	rm *.o