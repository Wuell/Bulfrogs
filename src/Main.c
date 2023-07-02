#include <stdio.h>
#include "Matrizes.h"
#include <time.h>
#include "Pds_telecom.h"
#include <stdlib.h>
///@file Main.c

int main()
{

    bfgs_vector vector = vector_alloc(4);
    vector.data[0] = (complexo){-1,1};
    vector.data[1] = (complexo){-1,-1};
    vector.data[2] = (complexo){1,1};
    vector.data[3] = (complexo){1,-1};

    rx_qam_demapper(vector);

    vector_free(vector);
//=========================================================================================================================

    /*printf("=====Equipe====\n\nWellerson Nascimento, Matricula = 202206840045\n\nNestor Carmo, Matricula = 202206840052\n\n");
    printf("so pra ver se ta funfando\n\n");

    Teste_geral();
    */
    return (0);
}