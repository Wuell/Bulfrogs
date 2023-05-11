all: programa

programa: matrizes.o main.o

	@echo "Compilando executavel programa.exe..."
	gcc -o programa matrizes.o main.o

matrizes.o: matrizes.c matrizes.h

	@echo "Compilando a biblioteca matrizes..."
	gcc -o matrizes.o -c matrizes.c -W -Wall -pedantic

main.o: main.c

	@echo "Compilando main.c..."
	gcc -o main.o -c main.c -W -Wall -pedantic

clean:

	rm -rf *.o

mrproper: clean

	rm -rf programa