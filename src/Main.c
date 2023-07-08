#include <stdio.h>
#include "./matrizes/Matrizes.h"
#include <time.h>
#include "Pds_telecom.h"
#include <stdlib.h>
///@file Main.c

// nr = 2, nt = 4, ruido -1 a 1

int main()
{
    int nstreams = 3;
    int nt = 5;
    int nr = 5;
    //testa_a_porra_toda(12, 4, 4, 4);

    bfgs_int_vector tst = tx_data_read(".\\src\\pds\\Referencia");

    bfgs_vector qam_mppr =  tx_qam_mapper(tst);

    verify_nstreams(5, 5, 3);

    bfgs_matrix symbols = tx_layer_mapper(qam_mppr, nt, nstreams);

    bfgs_matrix channel = channel_gen(nr, nt);

    printf("eu vim aqui1\n");
    printf("Symbol\n");
    matrix_print(symbols);
    printf("channel\n");
    matrix_print(channel);
    
    bfgs_matrix chnnl_tr = channel_transmission(symbols, channel, 1);

    bfgs_matrix u = matrix_alloc(nr, nstreams);
    bfgs_matrix v = matrix_alloc(nstreams, nstreams);
    bfgs_vector s = vector_alloc(nstreams);
    svd_channel(channel, u, v, s);


    printf("eu vim aqui2\n");
    bfgs_matrix pre_cdr = tx_precoder(chnnl_tr, v);


    bfgs_matrix cmbnr = rx_combiner(chnnl_tr, u);

    //bfgs_vector lyr_dmppr = rx_layer_demapper(cmbnr);

    bfgs_vector sym_eq = rx_feq(s, cmbnr);

    bfgs_int_vector qm_dmppr = rx_qam_demapper(sym_eq);

    rx_data_write(".\\build\\teste1.txt", qm_dmppr);

    matrix_free(symbols);
    matrix_free(channel);
    matrix_free(u);
    matrix_free(v);
    vector_free(s);
    matrix_free(pre_cdr);
    matrix_free(chnnl_tr);
    matrix_free(cmbnr);
    vector_free(sym_eq);
    free(qm_dmppr.data);
    vector_free(qam_mppr);
    free(tst.data);

    return (0);
}