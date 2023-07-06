#include <stdio.h>
#include "Matrizes.h"
#include <time.h>
#include "Pds_telecom.h"
#include <stdlib.h>
///@file Main.c

#define number_bits 4
int main()
{
    int index = 1;
    int *bits = random_vector_int(number_bits, 4);

    for (int i = 0; i < number_bits; i++)
    {

        printf("%d.| %d |\n",index,bits[i]);
        index++;
    }

    printf("\n================QAM_MAPPER================\n\n");

    bfgs_vector vetor_complexo = tx_qam_mapper(bits,number_bits);

    vector_print(vetor_complexo);

    printf("\n================LAYER_MAPPER================\n\n");

    int Nr = 2;
    int Nt = 2;
    int Ntstreams = 2;

    verify_nstreams(Nr,Nt,Ntstreams);

    bfgs_matrix matrix_complexo = tx_layer_mapper(vetor_complexo,Nt,Ntstreams);

    matrix_print(matrix_complexo);

    printf("\n================CHANNEL_GEN================\n\n");

    bfgs_matrix canal = channel_gen(Nr,Nt);

    matrix_print(canal);
    
    printf("\n================CHANNEL_NOISE================\n\n");


    printf("\n================CHANNEL_TRANSMISSION================\n\n");


    bfgs_matrix canal_trans = matrix_alloc(Nr,Ntstreams);

    canal_trans = channel_transmission(matrix_complexo,canal,0);

    matrix_print(canal_trans);   

    free(bits);
    vector_free(vetor_complexo);
    matrix_free(matrix_complexo);
    matrix_free(canal);
    matrix_free(canal_trans);
}