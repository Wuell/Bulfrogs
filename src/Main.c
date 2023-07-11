#include <stdio.h>
#include "Matrizes.h"
#include <time.h>
#include "Pds_telecom.h"
#include <stdlib.h>
///@file Main.c

#define number_bits 4
int main()
{
<<<<<<< HEAD

    testa_a_porra_toda(12, 4, 4, 4);
=======
    int nstreams = 3;
    int nt = 5;
    int nr = 5;
    // testa_a_porra_toda(12, 4, 4, 4);

    bfgs_int_vector tst = tx_data_read(".\\src\\pds\\Referencia");

    bfgs_vector qam_mppr = tx_qam_mapper(tst);

    verify_nstreams(nr, nt, nstreams);

    bfgs_matrix symbols = tx_layer_mapper(qam_mppr, nt, nstreams);

    bfgs_matrix channel = channel_gen(nr, nt);

    printf("eu vim aqui1\n");
    printf("Symbol\n");
    matrix_print(symbols);
    printf("channel\n");

    bfgs_matrix chnnl_tr = channel_transmission(symbols, channel, 1);
    matrix_print(chnnl_tr);

    bfgs_matrix u = matrix_alloc(nr, nstreams);
    bfgs_matrix v = matrix_alloc(nstreams, nstreams);
    bfgs_vector s = vector_alloc(nstreams);
    svd_channel(channel, u, v, s);
>>>>>>> bed7a69 (Resolvendo produto matricial)

    bfgs_matrix pre_cdr = tx_precoder(symbols, v);

<<<<<<< HEAD
=======
    printf("eu vim aqui2\n");

    printf("Channel\n%d %d\n", chnnl_tr.M, chnnl_tr.N);
    printf("U\n%d %d\n", u.M, u.N);

    bfgs_matrix cmbnr = rx_combiner(chnnl_tr, u);

    printf("\ncombiner\n%d %d\n", cmbnr.M, cmbnr.N);
    printf("s\n%d\n", s.len);

    // bfgs_vector lyr_dmppr = rx_layer_demapper(cmbnr);

    bfgs_vector sym_eq = rx_feq(s, cmbnr);
    printf("eu vim aqui3\n");

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
>>>>>>> bed7a69 (Resolvendo produto matricial)
}