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

   bfgs_int_vector tst = tx_data_read(".\\src\\pds\\Referencia");
   rx_data_write(".\\build\\sapoes.txt", tst);

}