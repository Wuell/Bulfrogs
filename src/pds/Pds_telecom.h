#ifndef PDS_TELECOM_H
#define PDS_TELECOM_H

void rx_qam_demapper(bfgs_vector complex_vector);

void verify_nstreams(int Nt,int Nr, int Nstreams);

void tx_layer_mapper(bfgs_vector Vector_QAM,int Nstreams,int NTransmissions);

bfgs_vector random_vector_com(int len,int intervalMod);

#endif