#include <stdio.h>
#include "Matrizes.h"
#include <time.h>
#include "Pds_telecom.h"
#include <stdlib.h>
///@file Main.c

#define number_bits 20
int main()
{

    int Nt, Nr, Ntstreams, trans, index;

    Nt = 4;

    Nr = 4;

    Ntstreams = 3;

    trans = 20;

    index = 1;

    bfgs_matrix canal;

    bfgs_matrix layer;

    bfgs_vector teste;

    int *bits;

    int *teste_reverso;

    //bits = random_vector_int(number_bits, 4);

    //for (int i = 0; i < number_bits; i++)
   // {

   //     printf("%d.|%d|\n", index, bits[i]);
   //     index++;
   // }

    printf("========== QAM_MAPPER =========\n");

    teste = tx_qam_mapper(bits, number_bits);

    vector_print(teste);

    printf("========== LAYER_MAPPER =========\n");

    verify_nstreams(Nt, Nr, Ntstreams);

    layer = tx_layer_mapper(teste, Ntstreams, trans);

    matrix_print(layer);

    printf("========== CHANNEL =========\n");

  

    //matrix_print(canal);

    /*    printf("========== QAM_DEMAPPER =========\n");

        teste_reverso = rx_qam_demapper(teste,number_bits);

        for(int j = 0; j < number_bits; j++){
            printf("%d.|%d|\n",indexj, teste_reverso[j]);
            indexj++;

        }*/

    vector_free(teste);

    free(bits);

    free(teste_reverso);

    matrix_free(layer);

    matrix_free(canal);   

    return (0);
}
//=========================================================================================================================

/*
    double *random_num = malloc(sizeof(double)*10);
    srand(time(0));

    for(int a = 0; a < 10; a++){
    random_num[a] = ((double)rand())/RAND_MAX*2 - 1;
    printf("%lf\n",random_num[a]);

    }
    free(random_num);
*/
//=========================================================================================================================

/*
    bfgs_vector vector = vector_alloc(4);
    vector.data[0] = (complexo){-1,1};
    vector.data[1] = (complexo){-1,-1};
    vector.data[2] = (complexo){1,1};
    vector.data[3] = (complexo){1,-1};

    rx_qam_demapper(vector);

    vector_free(vector);
*/

//=========================================================================================================================

/*
    printf("=====Equipe====\n\nWellerson Nascimento, Matricula = 202206840045\n\nNestor Carmo, Matricula = 202206840052\n\n");
    printf("so pra ver se ta funfando\n\n");

    Teste_geral();

    return (0);
*/