#include <stdio.h>
#include <stdlib.h>
#include "../matrizes/Matrizes.h"
#include "Pds_telecom.h"
#include <time.h>


bfgs_vector tx_qam_mapper(int *bits,int number_bits)
{

    bfgs_vector complex_vector = vector_alloc(number_bits);

    for (int i = 0; i < number_bits; i ++)
    {
        if (bits[i] == 0)
            vector_change(complex_vector, i ,(complexo){-1,1});

        else if (bits[i] == 1)
            vector_change(complex_vector, i ,(complexo){-1,-1});

        else if (bits[i] == 2)
            vector_change(complex_vector, i ,(complexo){1,1});

        else//bits[i] == 3)
            vector_change(complex_vector, i ,(complexo){1,-1});
    
    }
    return complex_vector;
}


