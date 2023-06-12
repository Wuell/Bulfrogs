BUILD = ./build
SRC = ./src
SRCMt = ./src/matrizes

aplicacao: teste doc

cria_pasta:

	mkdir -p build

teste: cria_pasta $(BUILD)/matrizes.o $(BUILD)/main.o
	
	@echo "Compilando executavel programa.exe..."
	gcc -o $(BUILD)/aplicacao $(BUILD)/matrizes.o -lgsl $(BUILD)/main.o 

$(BUILD)/matrizes.o: $(SRCMt)/Matrizes.c $(SRCMt)/Matrizes.h

	@echo "Compilando a biblioteca matrizes..."
	gcc -o $(BUILD)/matrizes.o -lgsl -c $(SRCMt)/Matrizes.c -W -Wall -pedantic

$(BUILD)/main.o: $(SRC)/main.c

	@echo "Compilando main.c..."
	gcc -o $(BUILD)/main.o -c $(SRC)/main.c -I$(SRCMt) -W -Wall -pedantic

clean:

	rm -rf aplicacao
	rm -rf doc
	rm -rf build

make doc:
	
	doxygen Doxyfile
	