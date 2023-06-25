BUILD = ./build
SRC = ./src
SRCMt = ./src/matrizes

aplicacao: teste doc

cria_pasta:

	mkdir -p build

teste: cria_pasta $(BUILD)/Matrizes.o $(BUILD)/Main.o
	
	@echo "Compilando executavel programa.exe..."
	gcc -o $(BUILD)/aplicacao $(BUILD)/Matrizes.o -lgsl $(BUILD)/Main.o 

$(BUILD)/Matrizes.o: $(SRCMt)/Matrizes.c $(SRCMt)/Matrizes.h

	@echo "Compilando a biblioteca matrizes..."
	gcc -o $(BUILD)/Matrizes.o -lgsl -c $(SRCMt)/Matrizes.c -W -Wall -pedantic

$(BUILD)/Main.o: $(SRC)/Main.c

	@echo "Compilando Main.c..."
	gcc -o $(BUILD)/Main.o -c $(SRC)/Main.c -I $(SRCMt) -W -Wall -pedantic

clean:

	rm -rf aplicacao
	rm -rf doc
	rm -rf build

make doc:
	
	doxygen Doxyfile
	
