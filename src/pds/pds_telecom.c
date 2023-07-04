#include <stdio.h>
#include <stdlib.h>
#include "../matrizes/Matrizes.h"
#include "Pds_telecom.h"
#include <time.h>

void main(){

}

bfgs_int_vector rx_data_read(char* name){

    char v;
    int len = 0;

    FILE* eye = fopen(name, "rb");
    if (eye == NULL){
        printf("ERROR--O arquivo não foi aberto.");
        exit(0);
    }

    //figure out the lenght
    while(1){
        if (feof(eye)){
            break;
        }
        v = fgetc(eye);
        len++;
    }
    rewind(eye);

    //transfer the data to an array
    char* data = char_vector_alloc(len-1);
    fgets(data, len, eye);
    fclose(eye);
    printf("foi transmitido a.txt = %s\n", data);

    bfgs_int_vector frmtd = int_vector_alloc(4*(len-1));
    int b = 0;
    int a;
    int bin[8];
    int ref[8] = {128, 64, 32, 16, 8, 4, 2, 1}; 

    // transforma cada char em binario e volta pra decimal de 0 a 3.
    for (int i = 0; i < len-1; i++){
    
        a = data[i];
 
        //char to bin
        for (int j =  0; j < 8; j++){
            bin[j] = a / ref[j];
            a = a - (bin[j] * ref[j]);
        }

        //bin to [0,3] dec
        b = 0;
        for (int l = i * 4; l < (i * 4) + 4; l++){
            frmtd.data[l] = 0;
    
            if (bin[b*2 + 1] == 1){
                frmtd.data[l] += 1;
            }

            if (bin[b*2] == 1){
                frmtd.data[l] += 2;
            }       
            b += 1;
        }  
    }

    free(data);
    return frmtd;
}

void rx_data_write(char* fname, bfgs_int_vector objct){

    bfgs_int_vector refrmtd = int_vector_alloc(objct.len*2);
    char* asc = char_vector_alloc(refrmtd.len/8);
    
    // dec[0,3] to bin
    for (int i = 0; i < objct.len; i++){
        refrmtd.data[2 * i]  = objct.data[i] / 2;
        refrmtd.data[2 * i +1] = objct.data[i] % 2;
    }

    int casa;
    // bin to char
    for (int i = 0; i < refrmtd.len/8; i++){
        
        casa = 0;
        for (int j = i * 8, aux = 7; j < i * 8 + 8; j++, aux--){

            casa += refrmtd.data[j ] << aux;
        }

        asc[i] = casa;

    }

    printf("foi recebido = ");
    for (int i = 0; i < refrmtd.len/8; i++){
        printf("%d ", asc[i]);
    }
        printf("\n");
    for (int i = 0; i < refrmtd.len/8; i++){
        printf("%c ", asc[i]);
    }
        printf("\n%s ", asc);

    free(asc);
    free(refrmtd.data);
}
