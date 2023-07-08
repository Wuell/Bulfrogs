#include <stdio.h>
#include "Matrizes.h"
#include <time.h>
#include "Pds_telecom.h"
#include <stdlib.h>
///@file Main.c

#define number_bits 4
int main()
{

    testa_a_porra_toda(12, 4, 4, 4);

    free(bits);
    vector_free(vetor_complexo);
    matrix_free(matrix_complexo);
    matrix_free(canal);
    matrix_free(canal_trans);
}