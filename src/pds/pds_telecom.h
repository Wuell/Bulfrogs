#ifndef PDS_TELECOM_H
#define PDS_TELECOM_H

bfgs_int_vector tx_data_read(char* name);

void rx_data_write(char* name, bfgs_int_vector objct);

bfgs_vector feq(bfgs_vector s, bfgs_matrix data);

bfgs_matrix rx_combiner(bfgs_matrix signal, bfgs_matrix u);

#endif