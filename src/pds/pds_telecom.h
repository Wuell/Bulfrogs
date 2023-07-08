#ifndef PDS_TELECOM_H
#define PDS_TELECOM_H

void tx_data_read(char* name);

void tx_data_write(char* name, bfgs_int_vector objct);

bfgs_vector feq(bfgs_vector s, bfgs_matrix data);

#endif