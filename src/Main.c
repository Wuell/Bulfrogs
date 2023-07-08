#include <stdio.h>
#include <stdlib.h>
#include "matrizes/Matrizes.h"
#include "Pds_telecom.h"
///@file Main.c

int main()
{
    printf("=====Equipe====\n\nWellerson Nascimento, Matricula = 202206840045\n\nNestor Carmo, Matricula = 202206840052\n\n");
    printf("so pra ver se ta funfando\n\n");

   bfgs_int_vector tst = tx_data_read(".\\src\\pds\\Referencia");
   rx_data_write(".\\build\\sapoes.txt", tst);

   

    return (0);
}