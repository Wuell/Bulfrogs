#ifndef PDS_TELECOM_H
#define PDS_TELECOM_H

bfgs_vector tx_qam_mapper(bfgs_int_vector bits);

bfgs_int_vector rx_qam_demapper (bfgs_vector complex_vector);

void verify_nstreams(int Nr, int Nt, int Nstreams);

bfgs_matrix tx_layer_mapper(bfgs_vector Vector_QAM, int Nstreams, int NTransmissions);

bfgs_vector random_vector_com(int len, int intervalMod);

int *random_vector_int(int len, int number_bits);

bfgs_matrix channel_gen(int Nr, int Nt);

bfgs_matrix noise(int Nr,int Nt, double intervalR);

bfgs_matrix channel_transmission(bfgs_matrix symbols, bfgs_matrix channel, double intervalR);

void svd_channel(bfgs_matrix channel,bfgs_matrix u,bfgs_matrix v,bfgs_vector s);

bfgs_matrix tx_precoder(bfgs_matrix signal,bfgs_matrix v);

bfgs_vector rx_layer_demapper(bfgs_matrix complex_matrix);

void testa_a_porra_toda(int number_bits,int Nr,int Nt, int Ntstreams);

bfgs_int_vector tx_data_read(char* name);

void rx_data_write(char* name, bfgs_int_vector objct);

bfgs_vector rx_feq(bfgs_vector s, bfgs_matrix data);

bfgs_matrix rx_combiner(bfgs_matrix signal, bfgs_matrix u);

#endif