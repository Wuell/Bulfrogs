BUILD = ./build
SRC = ./src
SRCMt = ./src/matrizes
SRCPds = ./src/pds

aplicacao: teste doc

cria_pasta:

	mkdir -p build

teste: cria_pasta $(BUILD)/Matrizes.o $(BUILD)/Main.o $(BUILD)/Pds_telecom.o
	
	@echo "Compilando executavel programa.exe..."
	gcc -o $(BUILD)/aplicacao $(BUILD)/Matrizes.o -lgsl $(BUILD)/Main.o 

$(BUILD)/Matrizes.o: $(SRCMt)/Matrizes.c $(SRCMt)/Matrizes.h

	@echo "Compilando a biblioteca matrizes..."
	gcc -o $(BUILD)/Matrizes.o -lgsl -c $(SRCMt)/Matrizes.c -W -Wall -pedantic

$(BUILD)/Main.o: $(SRC)/Main.c

	@echo "Compilando Main.c..."
	gcc -o $(BUILD)/Main.o -c $(SRC)/Main.c -I $(SRCMt) -I $(SRCPds) -W -Wall -pedantic

$(BUILD)/Pds_telecom.o: $(SRCPds)/Pds_telecom.c $(SRCPds)/Pds_telecom.h

	@echo "Compilando a biblioteca PDS"
	gcc -o $(BUILD)/Pds_telecom.o -lgsl -c $(SRCPds)/Pds_telecom.c -W -Wall -pedantic

clean:

	rm -rf aplicacao
	rm -rf doc
	rm -rf build

make doc:
	
	doxygen Doxyfile
	
