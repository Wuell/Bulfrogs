#ifndef MATRIZES_H
#define MATRIZES_H

struct complexo //Define os complexos
    {
        double re;
        double im;
    };

typedef struct complexo complexo;

void print_matriz(int tamanho, complexo matriz[100][100], complexo matriz_mod[100][100]);

// TRANSPOSTA

complexo Transposta (int tamanho, complexo matriz[100][100], complexo matrizT[100][100]);

void teste_transposta();

// CONJUGADA

void teste_conjugada();

complexo Conjugada(int tamanho, complexo matriz[100][100], complexo matrizConj[100][100]);

// HERMITIANA

void teste_hermitiana();

complexo Hermitiana(int tamanho, complexo matriz[100][100],complexo matrizHermt[100][100]);

#endif