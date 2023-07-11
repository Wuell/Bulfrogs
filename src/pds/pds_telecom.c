#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../matrizes/Matrizes.h"
#include "Pds_telecom.h"
#include <time.h>

///@file pds_telecom.c

bfgs_vector tx_qam_mapper(bfgs_int_vector bits)
{

    bfgs_vector complex_vector = vector_alloc(bits.len);

    for (int i = 0; i < bits.len; i++)
    {

        if (bits.data[i] == 0)
            vector_change(complex_vector, i, (complexo){-1, 1});

        else if (bits.data[i] == 1)
            vector_change(complex_vector, i, (complexo){-1, -1});

        else if (bits.data[i] == 2)
            vector_change(complex_vector, i, (complexo){1, 1});

        else
            vector_change(complex_vector, i, (complexo){1, -1});
    }
    return complex_vector;
}

bfgs_int_vector rx_qam_demapper(bfgs_vector complex_vector)
{
    bfgs_int_vector transforma_complex = int_vector_alloc(complex_vector.len);

    for (int i = 0; i < complex_vector.len; i++)
    {
        if (vector_get(complex_vector, i).re != 0 && vector_get(complex_vector, i).im != 0)
        {

            if (vector_get(complex_vector, i).re == -1 && vector_get(complex_vector, i).im == 1)
                transforma_complex.data[i] = 0;

            else if (vector_get(complex_vector, i).re == -1 && vector_get(complex_vector, i).im == -1)
                transforma_complex.data[i] = 1;

            else if (vector_get(complex_vector, i).re == 1 && vector_get(complex_vector, i).im == 1)
                transforma_complex.data[i] = 2;

            else if (vector_get(complex_vector, i).re == 1 && vector_get(complex_vector, i).im == -1)
                transforma_complex.data[i] = 3;
        }
        else
        {
            printf("A função QAM_MAPPER não conseguiu rodar devido a falta de dados\n");
            break;
        }
    }
    return transforma_complex;
}

bfgs_int_vector tx_data_read(char *name)
{

    int len = 0;

    FILE *eye = fopen(name, "rb");
    if (eye == NULL)
    {
        printf("ERROR--O arquivo não foi aberto.\n");
        printf("Error: %d ()\n", errno);
        fclose(eye);
        exit(1);
    }
    // figure out the lenght
    while (1)
    {
        if (feof(eye))
        {
            break;
        }
        fgetc(eye);
        len++;
    }
    rewind(eye);

    // transfer the data to an array
    char *data = char_vector_alloc(len - 1);
    fgets(data, len, eye);
    fclose(eye);
    printf("Lendo o arquivo...\n");

    bfgs_int_vector frmtd = int_vector_alloc(4 * (len - 1));
    int b = 0;
    int a;
    int bin[8];
    int ref[8] = {128, 64, 32, 16, 8, 4, 2, 1};

    printf("Convertendo em binario...\n");
    // transforma cada char em binario e volta pra decimal de 0 a 3.
    for (int i = 0; i < len - 1; i++)
    {

        a = data[i];

        // char to bin
        for (int j = 0; j < 8; j++)
        {
            bin[j] = a / ref[j];
            a = a - (bin[j] * ref[j]);
        }

        // bin to [0,3] dec
        b = 0;
        for (int l = i * 4; l < (i * 4) + 4; l++)
        {
            frmtd.data[l] = 0;

            if (bin[b * 2 + 1] == 1)
            {
                frmtd.data[l] += 1;
            }

            if (bin[b * 2] == 1)
            {
                frmtd.data[l] += 2;
            }
            b += 1;
        }
    }

    return frmtd;
}

void verify_nstreams(int Nr, int Nt, int Nstreams)
{

    int aux;

    aux = Nt;

    if (Nr <= Nt)
        aux = Nr;

    if (aux < Nstreams)
    {
        printf("O Numero de stream nao pode ser maior que o valor minimo entre Nt e Nr. Altere o valor de Nstreams.\n");
        exit(0);
    }
}

bfgs_matrix tx_layer_mapper(bfgs_vector Vector_QAM, int Nt, int Nstreams)
{

    bfgs_matrix matrix_layer = matrix_alloc(Nt, Nstreams);
    int index = 0;

    for (int i = 0; i < Nt; i++)
    {
        for (int j = 0; j < Nstreams; j++)
        {

            matrix_change(matrix_layer, i, j, Vector_QAM.data[index]);
            index++;
        }
    }

    return matrix_layer;
}

bfgs_vector random_vector_com(int len, int intervalMod)
{

    bfgs_vector vector;
    srand(time(0));
    int range = intervalMod * 2 + 1;

    vector = vector_alloc(len);

    for (int i = 0; i < len; i++)
    {
        vector_change(vector, i, (complexo){rand() % range - intervalMod, rand() % range - intervalMod});
    }
    return vector;
}

bfgs_matrix channel_gen(int Nr, int Nt)
{

    bfgs_matrix channel = matrix_alloc(Nr, Nt);

    srand(time(0));

    for (int i = 0; i < Nr; i++)
    {
        for (int j = 0; j < Nt; j++)
        {
            matrix_change(channel, i, j, (complexo){(((double)rand() / RAND_MAX) * 2 - 1), 0});
        }
    }

    return channel;
}

bfgs_matrix noise(int Nr, int Nt, double intervalR)
{
    bfgs_matrix noise = matrix_alloc(Nr, Nt);

    for (int i = 0; i < Nr; i++)
    {
        for (int j = 0; j < Nt; j++)
        {

            matrix_change(noise, i, j, (complexo){((double)rand() / RAND_MAX) * (2 * intervalR) - intervalR, 0});
        }
    }
    return noise;
}

bfgs_matrix channel_transmission(bfgs_matrix symbols, bfgs_matrix channel, double intervalR)
{
    bfgs_matrix ruido = noise(channel.M, symbols.N, intervalR);

    bfgs_matrix prod_aux = matrix_alloc(channel.M, symbols.N);

    prod_aux = Produto_matricial(channel, symbols);

    bfgs_matrix channel_trans = matrix_alloc(channel.M, symbols.N);

    channel_trans = Soma(ruido, prod_aux);

    matrix_free(prod_aux);
    matrix_free(ruido);

    return channel_trans;
}

/*void svd_channel(bfgs_matrix channel, bfgs_matrix u, bfgs_matrix v, bfgs_vector s)
{

    bfgs_matrix channel_im = matrix_alloc(channel.M, channel.N);
    bfgs_matrix channel_re = matrix_alloc(channel.M, channel.N);

    bfgs_matrix v_im = matrix_alloc(channel_im.N, channel_im.N);
    bfgs_vector s_im = vector_alloc(channel_im.N);

    bfgs_matrix v_real = matrix_alloc(channel_re.N, channel_re.N);
    bfgs_vector s_real = vector_alloc(channel_re.N);

    for (int i = 0; i < channel_re.M; i++)
    {
        for (int j = 0; j < channel_re.N; j++)
        {

            matrix_change(channel_im, i, j, (complexo){matrix_get(channel, i, j).im, 0});
            matrix_change(channel_re, i, j, (complexo){matrix_get(channel, i, j).re, 0});
        }
    }

    Calc_svd(channel_im, v_im, s_im);

    Calc_svd(channel_re, v_real, s_real);

    for (int i = 0; i < channel.N; i++)
    {
        vector_change(s, i, (complexo){vector_get(s_real, i).re, vector_get(s_im, i).re});
        for (int j = 0; j < channel.N; j++)
        {
            matrix_change(u, i, j, (complexo){matrix_get(channel_re, i, j).re, matrix_get(channel_im, i, j).re});
            matrix_change(v, i, j, (complexo){matrix_get(v_real, i, j).re, matrix_get(v_im, i, j).re});
        }
    }

    matrix_free(channel_im);
    matrix_free(channel_re);
    matrix_free(v_real);
    matrix_free(v_im);
    vector_free(s_real);
    vector_free(s_im);
}*/

void svd_channel(bfgs_matrix channel, bfgs_matrix u, bfgs_matrix v, bfgs_vector s)
{

    for (int i = 0; i < channel.M; i++)
    {
        for (int j = 0; j < channel.N; j++)
        {
            matrix_change(u, i, j, (complexo){matrix_get(channel, i, j).re, matrix_get(channel, i, j).im});
        }
    }

    Calc_svd(u, v, s);

    for (int i = 0; i < channel.M; i++)
    {
        for (int j = 0; j < channel.N; j++)
        {
            matrix_change(u, i, j, (complexo){matrix_get(u, i, j).re, matrix_get(channel, i, j).im});
        }
    }

    v = Transposta(v);
}

bfgs_matrix tx_precoder(bfgs_matrix signal, bfgs_matrix v)
{

    bfgs_matrix precoder;

    precoder = Produto_matricial(signal, v);

    return precoder;
}

bfgs_vector rx_layer_demapper(bfgs_matrix complex_matrix)
{

    int index = 0;
    bfgs_vector layer_demapper = vector_alloc(complex_matrix.M * complex_matrix.N);

    for (int i = 0; i < complex_matrix.M; i++)
    {
        for (int j = 0; j < complex_matrix.N; j++)
        {

            vector_change(layer_demapper, index, (complexo){matrix_get(complex_matrix, i, j).re, matrix_get(complex_matrix, i, j).im});
            index++;
        }
    }

    return layer_demapper;
}
void rx_data_write(char *fname, bfgs_int_vector objct)
{

    bfgs_int_vector refrmtd = int_vector_alloc(objct.len * 2);
    char *asc = char_vector_alloc(refrmtd.len / 8);

    printf("Convertendo os dados para binario...\n");
    // dec[0,3] to bin
    for (int i = 0; i < objct.len; i++)
    {
        refrmtd.data[2 * i] = objct.data[i] / 2;
        refrmtd.data[2 * i + 1] = objct.data[i] % 2;
    }

    int casa;
    // bin to char
    for (int i = 0; i < refrmtd.len / 8; i++)
    {

        casa = 0;
        for (int j = i * 8, aux = 7; j < i * 8 + 8; j++, aux--)
        {

            casa += refrmtd.data[j] << aux;
        }

        asc[i] = casa;
    }
    printf("Criando e escrevendo o novo arquivo...\n");
    FILE *hand = fopen(fname, "w");

    fputs(asc, hand);

    fclose(hand);

    free(asc);
    free(refrmtd.data);
}

bfgs_vector rx_feq(bfgs_vector s, bfgs_matrix data)
{
    bfgs_matrix ms = vec2matsqr(s);
    bfgs_matrix s_inv_sqr = inversa(ms);

    bfgs_matrix meq = Produto_matricial(data, s_inv_sqr);
    matrix_print(meq);
    bfgs_vector veq = vector_alloc(data.M * data.N);
    for (int i = 0; i < data.N; i++)
    {
        for (int j = 0; j < data.M; j++)
        {
            vector_change(veq, (i * data.M) + j, matrix_get(meq, i, j));
        }
    }
    matrix_free(ms);
    matrix_free(s_inv_sqr);
    matrix_free(meq);
    return veq;
}
bfgs_matrix rx_combiner(bfgs_matrix signal, bfgs_matrix u)
{
    u = Transposta(u);
    bfgs_matrix comb = Produto_matricial(signal, u);
    return comb;
}
