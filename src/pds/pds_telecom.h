#ifndef PDS_TELECOM_H
#define PDS_TELECOM_H

bfgs_vector tx_qam_mapper(int *bits,int number_bits);

int* rx_qam_demapper(bfgs_vector complex_vector,int number_int);

void verify_nstreams(int Nt,int Nr, int Nstreams);

void tx_layer_mapper(bfgs_vector Vector_QAM,int Nstreams,int NTransmissions);

bfgs_vector random_vector_com(int len,int intervalMod);

int* random_vector_int(int len,int number_bits);

#endif