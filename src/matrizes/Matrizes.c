#include <stdio.h>
#include <stdlib.h>
#include "Matrizes.h"
/// @file Matrizes.c

// PRINT_MATRIZ
void print_matriz(int tamanho, complexo matriz[100][100], complexo matriz_mod[100][100]) // Função de printar mudanças em uma matriz
{
    printf("Operando: A=...\n\n");

    for (int i = 0; i < tamanho; i++) // PRINT DO OPERANDO
    {
        for (int j = 0; j < tamanho; j++)
            printf("| %.2lf + (%.2lf)j | ", matriz[i][j].re, matriz[i][j].im);

        printf("\n\n");
    }

    printf("Operando: R=...\n\n");

    for (int i = 0; i < tamanho; i++) // PRINT DO RESULTADO
    {
        for (int j = 0; j < tamanho; j++)
            printf("| %.2lf + (%.2lf)j | ", matriz_mod[i][j].re, matriz_mod[i][j].im);

        printf("\n\n");
    }
}

void print_Opmatriz(int tamanho, complexo matrizA[100][100], complexo matrizB[100][100], complexo matrizR[100][100]) // Função de printar para operação de duas matrizes
{
    printf("Operando: A=...\n\n");

    for (int i = 0; i < tamanho; i++) // PRINT DO OPERANDO
    {
        for (int j = 0; j < tamanho; j++)
            printf("| %.2lf + (%.2lf)j | ", matrizA[i][j].re, matrizA[i][j].im);

        printf("\n\n");
    }

    printf("Operando: B=...\n\n");

    for (int i = 0; i < tamanho; i++) // PRINT DO OPERANDO
    {
        for (int j = 0; j < tamanho; j++)
            printf("| %.2lf + (%.2lf)j | ", matrizB[i][j].re, matrizB[i][j].im);

        printf("\n\n");
    }

    printf("Operando: R=...\n\n");

    for (int i = 0; i < tamanho; i++) // PRINT DO RESULTADO
    {
        for (int j = 0; j < tamanho; j++)
            printf("| %.2lf + (%.2lf)j | ", matrizR[i][j].re, matrizR[i][j].im);

        printf("\n\n");
    }
}

// MATRIZ CONJUGADA


complexo Conjugada(int tamanho, complexo matriz[100][100], complexo matrizConj[100][100])
{
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
        {
            matrizConj[i][j].im = (-1) * matriz[i][j].im; // INVERTE O SINAL DA PARTE IMAGINARIA
            matrizConj[i][j].re = matriz[i][j].re;
        }

    return matrizConj[100][100];
}

void teste_conjugada()
{
    int tamanho = 3;
    complexo m_teste[100][100];
    m_teste[0][0] = (complexo){1, -1};
    m_teste[0][1] = (complexo){2, -2};
    m_teste[0][2] = (complexo){3, -3};
    m_teste[1][0] = (complexo){4, -4};
    m_teste[1][1] = (complexo){5, -5};
    m_teste[1][2] = (complexo){6, -6};
    m_teste[2][0] = (complexo){7, -7};
    m_teste[2][1] = (complexo){8, -8};
    m_teste[2][2] = (complexo){9, -9};

    complexo n_teste[100][100];

    Conjugada(tamanho, m_teste, n_teste);

    printf("======Teste da operacao Conjugada======\n\n");

    print_matriz(tamanho, m_teste, n_teste);
}

// MATRIZ TRANSPOSTA

complexo Transposta(int tamanho, complexo matriz[100][100], complexo matrizT[100][100])
{
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
        {
            matrizT[j][i].re = matriz[i][j].re;
            matrizT[j][i].im = matriz[i][j].im;
        }
    return matrizT[100][100];
}

void teste_transposta()
{
    int tamanho = 3;
    complexo m[100][100];
    m[0][0] = (complexo){1, 710};
    m[0][1] = (complexo){2, 520};
    m[0][2] = (complexo){3, 330};
    m[1][0] = (complexo){4, 240};
    m[1][1] = (complexo){5, 450};
    m[1][2] = (complexo){6, -60};
    m[2][0] = (complexo){7, -70};
    m[2][1] = (complexo){8, -80};
    m[2][2] = (complexo){9, -90};

    complexo n[100][100];

    Transposta(tamanho, m, n);

    printf("======Teste da operacao Transposta======\n\n");

    print_matriz(tamanho, m, n);
}

// MATRIZ HERMITIANA

complexo Hermitiana(int tamanho, complexo matriz[100][100], complexo matrizHermt[100][100])
{
    complexo aux[100][100];
    Conjugada(tamanho, matriz, aux);
    Transposta(tamanho, aux, matrizHermt);

    return matrizHermt[100][100];
}

void teste_hermitiana()
{
    int tamanho = 3;
    complexo m_teste[100][100];
    m_teste[0][0] = (complexo){1, -12};
    m_teste[0][1] = (complexo){2, -62};
    m_teste[0][2] = (complexo){3, -30};
    m_teste[1][0] = (complexo){4, -80};
    m_teste[1][1] = (complexo){5, -55};
    m_teste[1][2] = (complexo){6, -45};
    m_teste[2][0] = (complexo){7, -10};
    m_teste[2][1] = (complexo){8, -60};
    m_teste[2][2] = (complexo){9, -54};

    complexo n_teste[100][100];

    Hermitiana(tamanho, m_teste, n_teste);

    printf("======Teste da operacao Hermitiana======\n\n");

    print_matriz(tamanho, m_teste, n_teste);
}

/// SOMA

complexo Soma(int tamanho, complexo matrizA[100][100], complexo matrizB[100][100], complexo matrizR[100][100])
{
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
        {
            matrizR[i][j].re = matrizA[i][j].re + matrizB[i][j].re;
            matrizR[i][j].im = matrizA[i][j].im + matrizB[i][j].im;
        }
    return matrizR[100][100];
}

void teste_soma()
{
    int tamanho = 3;
    complexo mA[100][100];
    mA[0][0] = (complexo){2, 7};
    mA[0][1] = (complexo){1, -5};
    mA[0][2] = (complexo){4, 33};
    mA[1][0] = (complexo){0.3, 24};
    mA[1][1] = (complexo){0.5, 45};
    mA[1][2] = (complexo){1, -6};
    mA[2][0] = (complexo){2, -7};
    mA[2][1] = (complexo){3, -8};
    mA[2][2] = (complexo){9, -9};

    complexo mB[100][100];
    mB[0][0] = (complexo){-2, 2};
    mB[0][1] = (complexo){-2, -6};
    mB[0][2] = (complexo){2, -3};
    mB[1][0] = (complexo){0.4, -8};
    mB[1][1] = (complexo){0.3, -5};
    mB[1][2] = (complexo){-5, -45};
    mB[2][0] = (complexo){-15, 10};
    mB[2][1] = (complexo){45, -6};
    mB[2][2] = (complexo){-1, 99};

    complexo mR[100][100];

    Soma(tamanho, mA, mB, mR);

    printf("======Teste da operacao Soma======\n\n");

    print_Opmatriz(tamanho, mA, mB, mR);
}

// SUBTRAÇÃO

complexo Subtracao(int tamanho, complexo matrizA[100][100], complexo matrizB[100][100], complexo matrizR[100][100])
{
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
        {
            matrizR[i][j].re = matrizA[i][j].re - matrizB[i][j].re;
            matrizR[i][j].im = matrizA[i][j].im - matrizB[i][j].im;
        }
    return matrizR[100][100];
}

void teste_subtracao()
{
    int tamanho = 3;
    complexo mA[100][100]; // MATRIZ mA É O MINUENDO
    mA[0][0] = (complexo){2, 7};
    mA[0][1] = (complexo){1, -5};
    mA[0][2] = (complexo){4, 33};
    mA[1][0] = (complexo){0.3, 24};
    mA[1][1] = (complexo){0.5, 45};
    mA[1][2] = (complexo){1, -6};
    mA[2][0] = (complexo){2, -7};
    mA[2][1] = (complexo){3, -8};
    mA[2][2] = (complexo){9, -9};

    complexo mB[100][100]; // MATRIZ mB É O SUBTRAENDO
    mB[0][0] = (complexo){-2, 2};
    mB[0][1] = (complexo){-2, -6};
    mB[0][2] = (complexo){2, -3};
    mB[1][0] = (complexo){0.4, -8};
    mB[1][1] = (complexo){0.3, -5};
    mB[1][2] = (complexo){-5, -45};
    mB[2][0] = (complexo){-15, 10};
    mB[2][1] = (complexo){45, -6};
    mB[2][2] = (complexo){-1, 99};

    complexo mR[100][100];

    Subtracao(tamanho, mA, mB, mR);

    printf("======Teste da operacao Subtracao======\n\n");

    print_Opmatriz(tamanho, mA, mB, mR);
}

// PRODUTO ESCALAR

void teste_produto_escalar()
{
    int tamanho = 2;
    complexo ma[100];
    ma[0] = (complexo){5, -3};
    ma[1] = (complexo){2, 9};

    complexo mb[100];
    mb[0] = (complexo){6, 4};
    mb[1] = (complexo){10, 5};

    complexo ans = Produto_escalar(tamanho, ma, mb);

    printf("======Teste da Produto Escalar======\n\n");
    printf("Operando: A=...\n\n");

    for (int i = 0; i < tamanho; i++) // PRINT DO OPERANDO
    {
        printf("| %.2lf + (%.2lf)j | ", ma[i].re, ma[i].im);

        printf("\n\n");
    }

    printf("Operando: B=...\n\n");

    for (int i = 0; i < tamanho; i++) // PRINT DO OPERANDO
    {
        printf("| %.2lf + (%.2lf)j | ", mb[i].re, mb[i].im);

        printf("\n\n");
    }

    printf("Operando: R=...\n\n");

    printf("| %.2lf + (%.2lf)j | \n\n", ans.re, ans.im);
}

complexo Produto_escalar(int tamanho, complexo ma[100], complexo mb[100])
{

    complexo intermed[tamanho];
    complexo ans;

    for (int j = 0; j < tamanho; j++)
    {

        intermed[j] = produto_complexo(ma[j], mb[j]);
    }

    ans.re = 0;
    ans.im = 0;

    for (int i = 0; i < tamanho; i++)
    {

        ans.re += intermed[i].re;
        ans.im += intermed[i].im;
    }
    return ans;
}

// PRODUTO COMPLEXO (adicional)
complexo produto_complexo(complexo ma, complexo na)
{

    complexo ans;
    ans.re = (ma.re * na.re) - (ma.im * na.im);
    ans.im = (ma.re * na.im) + (na.re * ma.im);

    return ans;
}

void teste_produto_complexo()
{

    complexo ma = {1, 1};
    complexo na = {1, -15};
    complexo ans;

    ans = produto_complexo(ma, na);
    printf("%.2lf + (%.2lf)j\n", ans.re, ans.im);
}

// PRODUTO MATRICIAL
void teste_produto_matricial()
{
    complexo ex1[100][100] = {{(complexo){1, -1}, (complexo){2, -2}, (complexo){3, -3}},
                              {(complexo){4, -4}, (complexo){5, -5}, (complexo){6, -6}},
                              {(complexo){7, -7}, (complexo){8, -8}, (complexo){9, -9}}};

    complexo ex2[100][100] = {{(complexo){-2, 2}, (complexo){-2, -6}, (complexo){2, -3}},
                              {(complexo){0.4, -8}, (complexo){0.3, -5}, (complexo){-5, -45}},
                              {(complexo){-15, 10}, (complexo){45, -6}, (complexo){-1, 99}}};

    complexo ans[100][100];
    Produto_matricial(3, ex1, ex2, ans);

    printf("\n======Teste do produto matricial======\n\n");
    print_Opmatriz(3, ex1, ex2, ans);
}

complexo Produto_matricial(int tamanho, complexo ma[100][100], complexo mb[100][100], complexo ans[100][100])
{

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            ans[i][j].re = 0;
            ans[i][j].im = 0;

            for (int j2 = 0; j2 < tamanho; j2++)
            {
                ans[i][j].re += ma[i][j2].re * mb[j2][j].re + (ma[i][j2].im * mb[j2][j].im) * -1;
                ans[i][j].im += ma[i][j2].im * mb[j2][j].re + ma[i][j2].re * mb[j2][j].im;
            }
        }
    }
    return ans[100][100];
}

// TESTE GERAL
void Teste_geral()
{

    teste_transposta();
    teste_conjugada();
    teste_hermitiana();
    teste_soma();
    teste_subtracao();
    teste_produto_escalar();
    teste_produto_matricial();

}