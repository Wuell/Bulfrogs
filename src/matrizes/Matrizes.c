#include <stdio.h>
#include <stdlib.h>
#include "Matrizes.h"
#include <time.h>
#include <gsl/gsl_linalg.h>

/// @file Matrizes.c

// matrix handle
bfgs_matrix matrix_alloc(int M, int N)
{

    bfgs_matrix data = {.data = (complexo *)malloc(M * N * sizeof(complexo))};
    data.M = M;
    data.N = N;
    data.is_alloc = 1;

    return data;
}

void matrix_free(bfgs_matrix m)
{

    if (m.is_alloc != 1)
    {
        printf("\nERROR//A matriz não foi alocada\n");
        exit(1);
    }

    free(m.data);
}

complexo matrix_get(bfgs_matrix m, int M, int N)
{

    int Pn = ((M + 1) * m.N) - m.N + N + 1;

    // printf("Pn = %d ", Pn);
    return m.data[Pn - 1];
}

void matrix_change(bfgs_matrix m, int M, int N, complexo v)
{

    int Pn = ((M + 1) * m.N) - m.N + N + 1;
    m.data[Pn - 1] = v;
}

void matrix_print(bfgs_matrix ma)
{

    int index = 1;

    for (int i = 0; i < ma.M; i++)
    {
        for (int j = 0; j < ma.N; j++)
        {
            printf("%*.*d%d| %.2f %+0.2fj |", 5, 0, i + 1, j + 1, matrix_get(ma, i, j).re, matrix_get(ma, i, j).im);
            index++;
        }
        printf("\n\n");
    }
}

// vector handle
bfgs_vector vector_alloc(int len)
{

    bfgs_vector data = {.data = (complexo *)malloc(len * sizeof(complexo))};
    data.len = len;
    data.is_alloc = 1;

    return data;
}

void vector_free(bfgs_vector v)
{
    free(v.data);
}

complexo vector_get(bfgs_vector v, int M)
{
    return v.data[M];
}

void vector_change(bfgs_vector v, int M, complexo a)
{

    v.data[M] = a;
}

void vector_print(bfgs_vector v)
{

    int index = 1;

    for (int i = 0; i < v.len; i++)
    {
        printf("%2d.| %.2f %.2fj |\n", index, v.data[i].re, v.data[i].im);
        index++;
    }
    printf("\n");
}

// PRINT_MATRIZ
void matrix_op_print(bfgs_matrix ma, bfgs_matrix mb, bfgs_matrix ans) // Função de printar mudanças em uma matriz
{
    printf("\n\nOperando: A=...\n\n");

    matrix_print(ma);

    printf("Operando: B=...\n\n");
    matrix_print(mb);

    printf("Operando: R=...\n\n");
    matrix_print(ans);
}

void matrix_mod_print(bfgs_matrix m, bfgs_matrix ans) // Função de printar para operação de duas matrizes
{
    printf("\n\nOperando: A=...\n\n");
    matrix_print(m);

    printf("Operando: R=...\n\n");
    matrix_print(ans);
}

// MATRIZ TRANSPOSTA

bfgs_matrix Transposta(bfgs_matrix m)
{
    bfgs_matrix M_Trans = matrix_alloc(m.M, m.N);
    for (int i = 0; i < m.M; i++)
    {
        for (int j = 0; j < m.N; j++)
        {

            matrix_change(M_Trans, i, j, matrix_get(m, j, i));
        }
    }
    return M_Trans;
}

void teste_transposta()
{
    printf("======Teste da operacao Transposta======");

    int tamanho = 3;

    bfgs_matrix m = matrix_alloc(tamanho, tamanho);
    matrix_change(m, 0, 0, (complexo){1, 710});
    matrix_change(m, 0, 1, (complexo){2, 520});
    matrix_change(m, 0, 2, (complexo){3, 330});
    matrix_change(m, 1, 0, (complexo){4, 240});
    matrix_change(m, 1, 1, (complexo){5, 450});
    matrix_change(m, 1, 2, (complexo){6, -60});
    matrix_change(m, 2, 0, (complexo){7, -70});
    matrix_change(m, 2, 1, (complexo){8, -80});
    matrix_change(m, 2, 2, (complexo){9, -90});

    bfgs_matrix mt;

    mt = Transposta(m);
    matrix_mod_print(m, mt);

    matrix_free(m);
    matrix_free(mt);
}

// MATRIZ CONJUGADA

void Conjugada(bfgs_matrix m, bfgs_matrix mc)
{
    for (int i = 0; i < m.M; i++)
    {
        for (int j = 0; j < m.N; j++)
        {
            matrix_change(mc, i, j, (complexo){matrix_get(m, i, j).re, matrix_get(m, i, j).im * -1});
        }
    }
}

void teste_conjugada()
{
    printf("======Teste da operacao Conjugada======");

    int tamanho = 3;

    bfgs_matrix m = matrix_alloc(tamanho, tamanho);
    matrix_change(m, 0, 0, (complexo){1, -1});
    matrix_change(m, 0, 1, (complexo){2, -2});
    matrix_change(m, 0, 2, (complexo){3, -3});
    matrix_change(m, 1, 0, (complexo){4, -4});
    matrix_change(m, 1, 1, (complexo){5, -5});
    matrix_change(m, 1, 2, (complexo){6, -6});
    matrix_change(m, 2, 0, (complexo){7, -7});
    matrix_change(m, 2, 1, (complexo){8, -8});
    matrix_change(m, 2, 2, (complexo){9, -9});

    bfgs_matrix mc = matrix_alloc(tamanho, tamanho);

    Conjugada(m, mc);
    matrix_mod_print(m, mc);

    matrix_free(m);
    matrix_free(mc);
}

// MATRIZ HERMITIANA

bfgs_matrix Hermitiana(bfgs_matrix m)
{
    bfgs_matrix h = matrix_alloc(m.M, m.N);
    bfgs_matrix aux = matrix_alloc(m.M, m.N);
    Conjugada(m, aux);
    h = Transposta(aux);

    return h;
}

void teste_hermitiana()
{
    printf("======Teste da operacao Hermitiana======");

    int tamanho = 3;

    bfgs_matrix m = matrix_alloc(tamanho, tamanho);
    matrix_change(m, 0, 0, (complexo){1, -12});
    matrix_change(m, 0, 1, (complexo){2, -62});
    matrix_change(m, 0, 2, (complexo){3, -30});
    matrix_change(m, 1, 0, (complexo){4, -80});
    matrix_change(m, 1, 1, (complexo){5, -55});
    matrix_change(m, 1, 2, (complexo){6, -45});
    matrix_change(m, 2, 0, (complexo){7, -10});
    matrix_change(m, 2, 1, (complexo){8, -60});
    matrix_change(m, 2, 2, (complexo){9, -54});

    bfgs_matrix h;

    h = Hermitiana(m);
    matrix_mod_print(m, h);

    matrix_free(m);
    matrix_free(h);
}

/// SOMA

bfgs_matrix Soma(bfgs_matrix ma, bfgs_matrix mb)
{
    if (ma.M != mb.M || ma.N != mb.N)
    {

        printf("\n---ERROR---Matrizes de tamanhos incompativeis");
        printf("\n---Program interrupted.");
        exit(EXIT_SUCCESS);
    }

    bfgs_matrix ans = matrix_alloc(ma.M, ma.N);

    for (int i = 0; i < ma.M; i++)
        for (int j = 0; j < ma.N; j++)
        {
            matrix_change(ans, i, j, (complexo){matrix_get(ma, i, j).re + matrix_get(mb, i, j).re, matrix_get(ma, i, j).im + matrix_get(mb, i, j).im});
        }
    return ans;
}

void teste_soma()
{
    printf("======Teste da operacao Soma======\n\n");

    int tamanho = 3;

    bfgs_matrix ans;
    bfgs_matrix ma = matrix_alloc(tamanho, tamanho);
    ma.data[0] = (complexo){2, 7};
    ma.data[1] = (complexo){1, -5};
    ma.data[2] = (complexo){4, 33};
    ma.data[3] = (complexo){0.3, 24};
    ma.data[4] = (complexo){0.5, 45};
    ma.data[5] = (complexo){1, -6};
    ma.data[6] = (complexo){2, -7};
    ma.data[7] = (complexo){3, -8};
    ma.data[8] = (complexo){9, -9};

    bfgs_matrix mb = matrix_alloc(tamanho, tamanho);
    mb.data[0] = (complexo){-2, 2};
    mb.data[1] = (complexo){-2, -6};
    mb.data[2] = (complexo){2, -3};
    mb.data[3] = (complexo){0.4, -8};
    mb.data[4] = (complexo){0.3, -5};
    mb.data[5] = (complexo){-5, -45};
    mb.data[6] = (complexo){-15, 10};
    mb.data[7] = (complexo){45, -6};
    mb.data[8] = (complexo){-1, 99};

    ans = Soma(ma, mb);
    // matrix_op_print(ma, mb, ans);

    matrix_print(ans);

    matrix_free(ma);
    matrix_free(mb);
    matrix_free(ans);
}

// SUBTRAÇÃO

void Subtracao(bfgs_matrix ma, bfgs_matrix mb, bfgs_matrix ans)
{
    if (ma.M != mb.M || ma.N != mb.N)
    {

        printf("\n---ERROR---Matrizes de tamanhos incompativeis");
        printf("\n---Program interrupted.");
        exit(EXIT_SUCCESS);
    }

    for (int i = 0; i < ma.M; i++)
        for (int j = 0; j < ma.N; j++)
        {
            complexo a = {matrix_get(ma, i, j).re - matrix_get(mb, i, j).re, matrix_get(ma, i, j).im - matrix_get(mb, i, j).im};
            matrix_change(ans, i, j, a);
        }
}

void teste_subtracao()
{
    printf("======Teste da operacao Subtracao======");
    int tamanho = 3;

    bfgs_matrix ma = matrix_alloc(tamanho, tamanho); // MATRIZ mA É O MINUENDO
    matrix_change(ma, 0, 0, (complexo){1, -5});
    matrix_change(ma, 0, 1, (complexo){4, 33});
    matrix_change(ma, 0, 2, (complexo){0.3, 4});
    matrix_change(ma, 1, 0, (complexo){0.5, 5});
    matrix_change(ma, 1, 1, (complexo){1, -6});
    matrix_change(ma, 1, 2, (complexo){2, -7});
    matrix_change(ma, 2, 0, (complexo){3, -8});
    matrix_change(ma, 2, 1, (complexo){9, -9});
    matrix_change(ma, 2, 2, (complexo){2, 7});

    bfgs_matrix mb = matrix_alloc(tamanho, tamanho); // MATRIZ mB É O SUBTRAENDO
    matrix_change(mb, 0, 0, (complexo){1, -5});
    matrix_change(mb, 0, 1, (complexo){4, 33});
    matrix_change(mb, 0, 2, (complexo){0.3, 4});
    matrix_change(mb, 1, 0, (complexo){0.5, 5});
    matrix_change(mb, 1, 1, (complexo){1, -6});
    matrix_change(mb, 1, 2, (complexo){2, -7});
    matrix_change(mb, 2, 0, (complexo){3, -8});
    matrix_change(mb, 2, 1, (complexo){9, -9});
    matrix_change(mb, 2, 2, (complexo){2, 7});

    bfgs_matrix ans = matrix_alloc(tamanho, tamanho);

    Subtracao(ma, mb, ans);
    matrix_op_print(ma, mb, ans);

    matrix_free(ma);
    matrix_free(mb);
    matrix_free(ans);
}

// PRODUTO ESCALAR

void teste_produto_escalar()
{
    int tamanho = 2;
    bfgs_vector va = vector_alloc(tamanho);
    vector_change(va, 0, (complexo){5, -3});
    vector_change(va, 1, (complexo){2, 9});

    bfgs_vector vb = vector_alloc(tamanho);
    vector_change(vb, 0, (complexo){6, 4});
    vector_change(vb, 1, (complexo){10, 5});

    complexo ans = Produto_escalar(va, vb);

    printf("======Teste da Produto Escalar======");

    printf("\n\nOperando: A=...\n\n");
    vector_print(va);

    printf("\n\n");

    printf("Operando: B=...\n\n");
    vector_print(vb);

    printf("\n\n");

    printf("Operando: R=...\n\n");
    printf("| %.2lf + (%.2lf)j | \n\n", ans.re, ans.im);

    vector_free(va);
    vector_free(vb);
}

complexo Produto_escalar(bfgs_vector va, bfgs_vector vb)
{

    bfgs_vector aux = vector_alloc(va.len);
    complexo ans;

    for (int i = 0; i < va.len; i++)
    {
        vector_change(aux, i, produto_complexo(vector_get(va, i), vector_get(vb, i)));
    }

    ans.re = 0;
    ans.im = 0;

    for (int i = 0; i < va.len; i++)
    {
        ans.re += vector_get(aux, i).re;
        ans.im += vector_get(aux, i).im;
    }

    vector_free(aux);

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

/*
void teste_produto_complexo()
{

    complexo ma = {1, 1};
    complexo na = {1, -15};
    complexo ans;

    ans = produto_complexo(ma, na);
    printf("%.2lf + (%.2lf)j\n", ans.re, ans.im);
}
*/

// PRODUTO MATRICIAL
void teste_produto_matricial()
{
    printf("======Teste do produto matricial======");

    int tamanho = 3;
    bfgs_matrix ma = matrix_alloc(tamanho, tamanho);
    matrix_change(ma, 0, 0, (complexo){1, -1});
    matrix_change(ma, 0, 1, (complexo){2, -2}),
        matrix_change(ma, 0, 2, (complexo){3, -3}),
        matrix_change(ma, 1, 0, (complexo){4, -4});
    matrix_change(ma, 1, 1, (complexo){5, -5});
    matrix_change(ma, 1, 2, (complexo){6, -6});
    matrix_change(ma, 2, 0, (complexo){7, -7});
    matrix_change(ma, 2, 1, (complexo){8, -8});
    matrix_change(ma, 2, 2, (complexo){9, -9});

    bfgs_matrix mb = matrix_alloc(tamanho, tamanho);
    matrix_change(mb, 0, 0, (complexo){-2, 2});
    matrix_change(mb, 0, 1, (complexo){-2, -6});
    matrix_change(mb, 0, 2, (complexo){2, -3});
    matrix_change(mb, 1, 0, (complexo){0.4, -8});
    matrix_change(mb, 1, 1, (complexo){0.3, -5});
    matrix_change(mb, 1, 2, (complexo){-5, -45});
    matrix_change(mb, 2, 0, (complexo){-15, 10});
    matrix_change(mb, 2, 1, (complexo){45, -6});
    matrix_change(mb, 2, 2, (complexo){-1, 99});

    bfgs_matrix ans = matrix_alloc(tamanho, tamanho);

    ans = Produto_matricial(ma, mb);
    matrix_op_print(ma, mb, ans);

    matrix_free(ma);
    matrix_free(mb);
    matrix_free(ans);
}

bfgs_matrix Produto_matricial(bfgs_matrix ma, bfgs_matrix mb)
{
    // vericando se ma pode fazer a operacao com mb
    if (ma.N != mb.M)
    {

        printf("\n---ERROR---Matrizes de tamanhos incompativeis, ma[N] != mb[M]");
        printf("\n---Program interrupted.");
        exit(EXIT_SUCCESS);
    }

    bfgs_matrix ans = matrix_alloc(ma.M, mb.N);

    double are, aim;
    for (int i = 0; i < ma.M; i++)
    {
        for (int j = 0; j < ma.N; j++)
        {
            matrix_change(ans, i, j, (complexo){0, 0});

            for (int j2 = 0; j2 < mb.M; j2++)
            {
                are = matrix_get(ma, i, j2).re * matrix_get(mb, j2, j).re + (matrix_get(ma, i, j2).im * matrix_get(mb, j2, j).im) * -1;
                aim = matrix_get(ma, i, j2).im * matrix_get(mb, j2, j).re + matrix_get(ma, i, j2).re * matrix_get(mb, j2, j).im;
                matrix_change(ans, i, j, (complexo){matrix_get(ans, i, j).re + are, matrix_get(ans, i, j).im + aim});
            }
        }
    }
    return ans;
}

// SVD
void Aux_teste_svd(bfgs_matrix A)
{

    printf("Matriz operando : A = ...\n\n");
    matrix_print(A);

    bfgs_matrix V = matrix_alloc(A.M, A.N);
    bfgs_vector S = vector_alloc(A.N);

    Calc_svd(A, V, S);

    printf("\n Matrix U = ...\n\n");
    matrix_print(A);

    printf("\n Matrix V = ...\n\n");
    matrix_print(V);

    printf("\n vetor S = ...\n\n");
    vector_print(S);

    matrix_free(V);
    vector_free(S);
}

void Teste_calc_svd()
{
    printf("================Teste da SVD================\n");
    srand(time(0));
    int MAX = 100;

    printf("\n______Matriz 3 X 2______\n\n");
    bfgs_matrix A0 = matrix_alloc(3, 2); // Matriz 3x2
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix_change(A0, i, j, (complexo){rand() % MAX, 0.0});
        }
    }
    Aux_teste_svd(A0);

    printf("\n______Matriz 4 X 4______\n\n");
    bfgs_matrix A1 = matrix_alloc(4, 4); // Matriz 4x4
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix_change(A1, i, j, (complexo){rand() % MAX, 0.0});
        }
    }
    Aux_teste_svd(A1);

    printf("\n______Matriz 6 X 5______\n\n");
    bfgs_matrix A2 = matrix_alloc(6, 5); // Matriz 6x5
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix_change(A2, i, j, (complexo){rand() % MAX, rand() % MAX});
        }
    }
    Aux_teste_svd(A2);

    printf("\n______Matriz 5 X 6______\n\n");
    bfgs_matrix A3 = matrix_alloc(5, 6); // Matriz 5x6
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            matrix_change(A3, i, j, (complexo){rand() % MAX, 0.0});
        }
    }
    Aux_teste_svd(A3);

    matrix_free(A0);
    matrix_free(A1);
    matrix_free(A2);
    matrix_free(A3);
    /*
     */
}

void Calc_svd(bfgs_matrix Au, bfgs_matrix V, bfgs_vector S)
{

    int M = Au.M;
    int N = Au.N;
    // Verificando se a gsl pode fazer a svd.
    if (M < N)
    {
        printf("---ERRROR---Nao e possivel realizar a operação com M (numero de linhas) sendo menor que N (numeros de colunas).---\n");
        printf("---Program interrupted.\n");
        exit(1);
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix_get(Au, i, j).im != (double)0)
            {
                printf("\n------So ha suporte a matrizes reais, entao somente sera calculada a SVD da parte real da matriz------\n");
                i = M + 1;
                break;
            }
        }
    }

    gsl_matrix *Are = gsl_matrix_alloc(M, N);
    gsl_matrix *Vre = gsl_matrix_alloc(N, N);
    gsl_vector *Sre = gsl_vector_alloc(N);
    gsl_vector *work = gsl_vector_alloc(N);

    // transfere os valores reais da matriz complexa para a matriz da gsl.
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            gsl_matrix_set(Are, i, j, matrix_get(Au, i, j).re);
        }
    }
    // Uso da GSL
    gsl_linalg_SV_decomp(Are, Vre, Sre, work);

    // Retorna os valores para matriz complexa bfgs.
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix_change(Au, i, j, (complexo){gsl_matrix_get(Are, i, j), 0});
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix_change(V, i, j, (complexo){gsl_matrix_get(Vre, i, j), 0});
        }
    }

    for (int i = 0; i < N; i++)
    {
        vector_change(S, i, (complexo){gsl_vector_get(Sre, i), 0});
    }

    gsl_matrix_free(Are);
    gsl_matrix_free(Vre);
    gsl_vector_free(Sre);
    gsl_vector_free(work);
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
    Teste_calc_svd();
}