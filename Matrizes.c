#include <stdio.h>
#include <stdlib.h>
#include "Matrizes.h"




//PRINT_MATRIZ

void print_matriz(int tamanho, complexo matriz[100][100], complexo matriz_mod[100][100])
{
    printf("Operando: A=...\n");

    for (int i = 0 ; i < tamanho; i++) // PRINT DO OPERANDO
    {
        for (int j = 0 ; j < tamanho; j++)
            printf ("| %.2lf + (%.2lf)i | ", matriz[i][j].re, matriz[i][j].im);

    printf ("\n");
    }

    printf("Operando: R=...\n");

    for (int i = 0 ; i < tamanho; i++) // PRINT DO RESULTADO
    {
        for (int j = 0 ; j < tamanho; j++)   
            printf ("| %.2lf + (%.2lf)i | ", matriz_mod[i][j].re, matriz_mod[i][j].im); 

    printf ("\n");
    }
}





//MATRIZ CONJUGADA

complexo Conjugada(int tamanho, complexo matriz[100][100], complexo matrizConj[100][100])
{
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < tamanho; j++)
        {
            matrizConj[i][j].im=(-1)*matriz[i][j].im; //INVERTE O SINAL DA PARTE IMAGINARIA
            matrizConj[i][j].re=matriz[i][j].re; 
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

    Conjugada(tamanho,m_teste,n_teste);

    printf("======Teste da operacao Conjugada======\n");

    print_matriz(tamanho,m_teste,n_teste);
}





// TRANSPOSTA 

complexo Transposta (int tamanho, complexo matriz[100][100], complexo matrizT[100][100])
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

    Transposta(tamanho,m,n);

    printf("======Teste da operacao Transposta======\n");

    print_matriz(tamanho,m,n);     
}





//MATRIZ HERMITIANA

complexo Hermitiana(int tamanho, complexo matriz[100][100],complexo matrizHermt[100][100])
{   
    complexo aux[100][100];
    Conjugada(tamanho, matriz, aux);
    Transposta(tamanho,aux,matrizHermt);  

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

    Hermitiana(tamanho,m_teste,n_teste);

    printf("======Teste da operacao Hermitiana======\n");

    print_matriz(tamanho,m_teste,n_teste);

}