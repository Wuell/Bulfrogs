#include <stdio.h>
#include "Matrizes.h"
#include <time.h>
#include "Pds_telecom.h"
#include <stdlib.h>
///@file Main.c

int main()
{
    int Nt, Nr, Ntstreams;

    Nt = 3;
    Nr = 10;
    Ntstreams = 10;

    verify_nstreams(Nt,Nr,Ntstreams);

    printf("Nestor dá o rabo\n");
  //=========================================================================================================================   

    /*double *random_num = malloc(sizeof(double)*10);
    srand(time(0));

    for(int a = 0; a < 10; a++){
        random_num[a] = ((double)rand())/RAND_MAX*2 - 1;
        printf("%lf\n",random_num[a]);

    }
    free(random_num);*/
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

    /*printf("=====Equipe====\n\nWellerson Nascimento, Matricula = 202206840045\n\nNestor Carmo, Matricula = 202206840052\n\n");
    printf("so pra ver se ta funfando\n\n");

    Teste_geral();
    */
    return (0);
}