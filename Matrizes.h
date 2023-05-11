#ifndef MATRIZES_H
#define MATRIZES_H

struct complexo //Define os complexos
    {
        double re;
        double im;
    };

typedef struct complexo complexo;

void print_Opmatriz(int tamanho, complexo matrizB[100][100], complexo matrizA[100][100], complexo matrizR[100][100]); //Função de printar para operação de duas matrizes

void print_matriz(int tamanho, complexo matriz[100][100], complexo matriz_mod[100][100]);

/// TRANSPOSTA

complexo Transposta (int tamanho, complexo matriz[100][100], complexo matrizT[100][100]);

void teste_transposta();

/// CONJUGADA

void teste_conjugada();

complexo Conjugada(int tamanho, complexo matriz[100][100], complexo matrizConj[100][100]);

/// HERMITIANA

void teste_hermitiana();

complexo Hermitiana(int tamanho, complexo matriz[100][100],complexo matrizHermt[100][100]);

#endif

/// SOMA

void teste_soma();

complexo Soma(int tamanho, complexo MatrizA[100][100], complexo MatrizB[100][100], complexo MatrizR[100][100]);


/// SUBTRAÇÃO

void teste_subtracao();

complexo Subtracao(int tamanho, complexo matrizA[100][100], complexo matrizB[100][100], complexo matrizR[100][100]);

/// PRODUTO Escalar

void teste_produto_escalar();

complexo Produto_escalar(int tamanho,complexo ma[100], complexo mb[100]);

/// PRODUTO MATRICIAL

void teste_produto_matricial();

complexo Produto_matricial(int tamanho, complexo ma[100][100], complexo mb[100][100], complexo ans[100][100]);

/// TESTE GERAL

void Teste_geral();

/// PRODUTO COMPLEXO

void teste_produto_complexo();

complexo produto_complexo(complexo ma, complexo na);