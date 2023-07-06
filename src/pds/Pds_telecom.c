#include <stdio.h>
#include <stdlib.h>
#include "../matrizes/Matrizes.h"
#include "Pds_telecom.h"
#include <time.h>

bfgs_vector tx_qam_mapper(int *bits, int number_bits)
{

    bfgs_vector complex_vector = vector_alloc(number_bits);

    for (int i = 0; i < number_bits; i++)
    {

        if (bits[i] == 0)
            vector_change(complex_vector, i, (complexo){-1, 1});

        else if (bits[i] == 1)
            vector_change(complex_vector, i, (complexo){-1, -1});

        else if (bits[i] == 2)
            vector_change(complex_vector, i, (complexo){1, 1});

        else
            vector_change(complex_vector, i, (complexo){1, -1});
    }
    return complex_vector;
}

int *rx_qam_demapper(bfgs_vector complex_vector, int number_int)
{
    int *int_vector = malloc(sizeof(int) * 4);

    for (int i = 0; i < number_int; i++)
    {
        if (vector_get(complex_vector, i).re != 0 && vector_get(complex_vector, i).im != 0)
        {

            if (vector_get(complex_vector, i).re == -1 && vector_get(complex_vector, i).im == 1)
                int_vector[i] = 0;

            else if (vector_get(complex_vector, i).re == -1 && vector_get(complex_vector, i).im == -1)
                int_vector[i] = 1;

            else if (vector_get(complex_vector, i).re == 1 && vector_get(complex_vector, i).im == 1)
                int_vector[i] = 2;

            else if (vector_get(complex_vector, i).re == 1 && vector_get(complex_vector, i).im == -1)
                int_vector[i] = 3;
        }
        else
        {
            printf("A função QAM_MAPPER não conseguiu rodar devido a falta de dados\n");
            break;
        }
    }

    return int_vector;
}

void verify_nstreams(int Nr, int Nt, int Nstreams)
{

    int aux;

    aux = Nt;

    if (Nr <= Nt)
        aux = Nr;

    if (aux < Nstreams)
    {
        printf("O Numero de stream nao pode ser maior que o valor minimo entre Nt e Nr. Altere o valor de Nstreams.\n");
        exit(0);
    }
}

bfgs_matrix tx_layer_mapper(bfgs_vector Vector_QAM, int Nstreams, int NTransmissions)
{

    bfgs_matrix Matrix_Layer = matrix_alloc(Nstreams, NTransmissions);
    int index = 0;

    for (int i = 0; i < Nstreams; i++)
    {
        for (int j = 0; j < NTransmissions; j++)
        {

            matrix_change(Matrix_Layer, i, j, Vector_QAM.data[index]);
            index++;
        }
    }

    return Matrix_Layer;
}

bfgs_vector random_vector_com(int len, int intervalMod)
{

    bfgs_vector vector;
    srand(time(0));
    int range = intervalMod * 2 + 1;

    vector = vector_alloc(len);

    for (int i = 0; i < len; i++)
    {
        vector_change(vector, i, (complexo){rand() % range - intervalMod, rand() % range - intervalMod});
    }
    return vector;
}

int *random_vector_int(int len, int number_bits)
{

    int *vector = malloc(sizeof(int) * len);
    srand(time(0));

    for (int i = 0; i < len; i++)
        vector[i] = rand() % number_bits;

    return vector;
}

bfgs_matrix channel_gen(int Nr, int Nt)
{

    bfgs_matrix channel = matrix_alloc(Nr,Nt);

    srand(time(0));
     
    for (int i = 0; i < Nt; i++) {
        for (int j = 0; j < Nr; j++) {
            channel.data[i]=(complexo){0,0};
        }
    }
    
    return channel;
}