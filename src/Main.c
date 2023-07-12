#include <stdio.h>
#include "./matrizes/Matrizes.h"
#include <time.h>
#include "Pds_telecom.h"
#include <stdlib.h>
///@file Main.c

// nr = 2, nt = 4, ruido -1 a 1

/*
        Caros professores, nos comecamos o trabalho de forma muito entusiasmada, no entanto, com o passar do tempo, as coisas foram
    desandando e chegamos nesse ponto.
        Todas as funcoes pedidas no roteiro dessa fase foram feitas e, de forma isolada, funcionam com os seus devidos pares, ou
    seja, o que uma faz a outra desfaz.
        A problematica chega quando nos direcionamos a criacao do MIMO em si, que nao ficou claro como que devia ser realizado, e 
    por conseguinte, nao fomos capazes de fazer as funcoes trabalharem em conjunto para realizar a simulacao da transmissao
    e recepcao dos dados. Isso se deve a muitos fatores, no entanto, o principal foi a falta de conhecimento teorico em relacao ao
    MIMO, o que unido ao roteiro confuso e da falta de informacao apropriada e direcionada para a nossa implementacao na internet, e
    isso fez com que nos frustassemos e desistissimos, ate porque nao temos mais tempo de qualquer forma, de concluir o projeto.

    Obs1: O notebook em python foi util ate certo ponto, mas, ao chegar a parte de plotagem da informacao no canal, nao ficou claro
    como isso devia ser feito, e foi o principal motivo da nossa incapacidade de terminar o projeto. Essa dificuldade se apresentou
    com impossibilidades de multiplicacao matricial.

    Obs2: Nos estamos conscientes que deveriamos ter entrado em contato com os professores, mas nos trabalhamos nas funcoes de forma
    separada e so fomos juntar as partes agora no final, por isso, achamos que ja era tarde para tentar buscar ajuda com os professores.

*/

/*
    O seguinte codigo nao funciona, mas estao presentes todas as funcoes, faltando o loop de transmissao, divido pelo numero de 
    streams, mas para a visualizacao do nosso trabalho, foi decidido que seria melhor mostrar todas as funcoes de forma linear, a
    fim de melhorar a apresentacao do que foi feito.

*/
int main()
{
    int nstreams = 3;
    int nt = 5;
    int nr = 5;

    bfgs_int_vector tst = tx_data_read(".\\src\\pds\\Referencia");

    bfgs_vector qam_mppr = tx_qam_mapper(tst);

    verify_nstreams(nr, nt, nstreams);

    // aqui comecaria o loop pra enviar todas os dados pelas streams.

    bfgs_matrix symbols = tx_layer_mapper(qam_mppr, nt, nstreams);

    bfgs_matrix channel = channel_gen(nr, nt);

    bfgs_matrix chnnl_tr = channel_transmission(symbols, channel, 1);

    matrix_print(chnnl_tr);

    bfgs_matrix u = matrix_alloc(nr, nstreams);
    bfgs_matrix v = matrix_alloc(nstreams, nstreams);
    bfgs_vector s = vector_alloc(nstreams);
    svd_channel(channel, u, v, s);

    bfgs_matrix pre_cdr = tx_precoder(symbols, v);

    bfgs_matrix cmbnr = rx_combiner(chnnl_tr, u);

    bfgs_vector lyr_dmppr = rx_layer_demapper(cmbnr);

    bfgs_vector sym_eq = rx_feq_2(s, lyr_dmppr);

    // bfgs_vector sym_eq = rx_feq(s, lyr_dmppr);

    // Aqui acabaria o loop e seria acumulado em um vetor que iria a alimentar a funcao qam demapper.

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