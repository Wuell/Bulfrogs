#ifndef PDS_TELECOM_H
#define PDS_TELECOM_H

///@file pds_telecom.h

/**
 * @brief Transforma bits em números complexos [0] = -1+j ; [1] = -1-j ; [2] = 1+j ; [3] = 1-j.
 *
 * @param bits
 */
bfgs_vector tx_qam_mapper(bfgs_int_vector bits);

/**
 * @brief Transforma números complexos em bits, seguindo a mesma tabela do TX_QAM_MAPPER.
 *
 * @param complex_vector Vetor de Complexos.
 * @return bfgs_int_vector
 */

bfgs_int_vector rx_qam_demapper(bfgs_vector complex_vector);

/**
 * @brief Verifica se o número de Streams(Fluxos) é compativel com o número de antenas receptoras e transmissoras.
 *
 * @param Nr N de antenas receptoras
 * @param Nt N de antenas transmissoras
 * @param Nstreams  N de fluxos
 */

void verify_nstreams(int Nr, int Nt, int Nstreams);

/**
 * @brief Agrupa os numeros complexos em uma matrix de simbolos (Numeros de antenas receptoras por Numeros de fluxos).
 *
 * @param Vector_QAM
 * @param Nr N de antenas receptoras
 * @param Nstreams N de fluxos
 * @return bfgs_matrix
 */

bfgs_matrix tx_layer_mapper(bfgs_vector Vector_QAM, int Nr, int Nstreams);

/**
 * @brief Cria numeros inteiros aleatorios de tamanho definido pelo intervalMod
 *
 * @param len Quantidade de numeros que quer criar
 * @param intervalMod
 * @return bfgs_vector
 */

bfgs_vector random_vector_com(int len, int intervalMod);

/**
 * @brief  Gera um canal Nr x Nt
 *
 * @param Nr N de antenas receptoras
 * @param Nt N de antenas transmissoras
 * @return bfgs_matrix
 */

bfgs_matrix channel_gen(int Nr, int Nt);

/**
 * @brief Gera um ruido de tamanho intervalR que vai ser somado no canal transmitido
 *
 * @param Nr N de antenas receptoras
 * @param Nt N de antenas transmissoras
 * @param intervalR
 * @return bfgs_matrix
 */

bfgs_matrix noise(int Nr, int Nt, double intervalR);

/**
 * @brief Gera o canal transmitido multiplicando os simbolos gerados no TX_LAYER_MAPPER
 *
 * @param symbols
 * @param channel
 * @param intervalR Intervalo do ruido
 * @return bfgs_matrix
 */

bfgs_matrix channel_transmission(bfgs_matrix symbols, bfgs_matrix channel, double intervalR);

/**
 * @brief Faz o calculo do svd
 *
 * @param channel
 * @param u
 * @param v
 * @param s
 */

void svd_channel(bfgs_matrix channel, bfgs_matrix u, bfgs_matrix v, bfgs_vector s);

/**
 * @brief Multiplica a matriz de simbolos pela Hermitiana de V
 *
 *
 * @param signal
 * @param v
 * @return bfgs_matrix
 */

bfgs_matrix tx_precoder(bfgs_matrix signal, bfgs_matrix v);

/**
 * @brief Desfaz a matriz de simbolos em um vetor de numeros complexos
 * @param complex_matrix
 * @return bfgs_vector
 */

bfgs_vector rx_layer_demapper(bfgs_matrix complex_matrix);

/**
 * @brief Le um arquivo e converte em grupos de numeros decimais
 *
 * @param name Nome do arquivo
 * @return bfgs_int_vector
 */

bfgs_int_vector tx_data_read(char *name);

/**
 * @brief Converte um grupo de numeros decimais em digitos num arquivo txt
 *
 * @param name
 * @param objct
 */

void rx_data_write(char *name, bfgs_int_vector objct);

/**
 * @brief Equaliza o sinal recebido multiplicando pela matriz s invertida
 *
 * @param s
 * @param data
 * @return bfgs_vector
 */

bfgs_vector rx_feq(bfgs_vector s, bfgs_matrix data);

/**
 * @brief Multiplica o sinal pelo W (Hermitiana de U)
 *
 * @param signal
 * @param u
 * @return bfgs_matrix
 */

bfgs_matrix rx_combiner(bfgs_matrix signal, bfgs_matrix u);

#endif
