#ifndef MATRIZES_H
#define MATRIZES_H
///@file Matrizes.h

/// @brief Estrutura de um numero complexo, guardado em duas variaveis, real e a imaginaria, que ligadas representam um complexo.
struct complexo //Define os complexos
    {
        /// @brief Parte real
        double re; 
        /// @brief Parte imaginaria
        double im; 
    };

/// @brief Representacao usual dos numeros complexos.
typedef struct complexo complexo;

//-------------------------PRINTERS

/// @brief Imprime a modificacao das matrizes A e B e o resultado MOD de alguma operacao.
/// @param tamanho das matrizes
/// @param A matriz A
/// @param B matriz B
/// @param MOD (matrizes A e B ja operadas)
void print_Opmatriz(int tamanho, complexo matrizB[100][100], complexo matrizA[100][100], complexo matrizR[100][100]); //Função de printar para operação de duas matrizes

/// @brief Imprime a matriz A e o resultado MOD de alguma modificacao.
/// @param Tamanho da matriz
/// @param A matriz A
/// @param MOD (matriz A ja operada)
void print_matriz(int tamanho, complexo matriz[100][100], complexo matriz_mod[100][100]);


//-------------------------TRANSPOSTA

/// @brief Testa a funcao transposta.
void teste_transposta();

/**
*Calcula a transposta da matriz A e armazena na matriz disponibilizada.
* 
* @param[in] tamanho da matriz
* @param[in] A
* @param[in] Resultado Matriz pre alocada na memoria para receber o resultado
* @param[out] Transposta de A
*/

complexo Transposta (int tamanho, complexo matriz[100][100], complexo matrizT[100][100]);




//-------------------------CONJUGADA

/// @brief Testa a funcao conjugada.
void teste_conjugada();

/**
*Calcula a conjugada da matriz A e armazena na matriz disponibilizada.
* 
* @param[in] tamanho da matriz
* @param[in] A
* @param[in] Resultado Matriz pre alocada na memoria para receber o resultado
* @param[out] Conjugada de A
*/
complexo Conjugada(int tamanho, complexo matriz[100][100], complexo matrizConj[100][100]);




//-------------------------HERMITIANA

/// @brief Testa a funcao de hermitiana.
void teste_hermitiana();

/**
*Calcula a hermitiana da matriz A e armazena na matriz disponibilizada Resultado.
* 
* @param[in] tamanho da matriz
* @param[in] A
* @param[in] Resultado Matriz pre alocada na memoria para receber o resultado.
* @param[out] Hermitiana de A
*/
complexo Hermitiana(int tamanho, complexo matriz[100][100],complexo matrizHermt[100][100]);

#endif




//-------------------------SOMA

/// @brief Testa a funcao de soma.
void teste_soma();

/**
*Calcula a soma entre as matrizes A e B e armazena o resultado na matriz disponibilizada Resultado.
* 
* @param[in] tamanho das matrizes
* @param[in] A
* @param[in] B
* @param[in] Resultado matriz pre alocada na memoria para receber o resultado.
* @param[out] A somada de B
*/
complexo Soma(int tamanho, complexo MatrizA[100][100], complexo MatrizB[100][100], complexo MatrizR[100][100]);




//-------------------------SUBTRAÇÃO

/// @brief Testa a funcao de subtracao.
void teste_subtracao();

/**
*Calcula a subtracao entre as matrizes A e B e armazena o resultado na matriz disponibilizada Resultado.
* 
* @param[in] tamanho das matrizes
* @param[in] A
* @param[in] B
* @param[in] Resultado Matriz pre alocada na memoria para receber o resultado.
* @param[out] Subtracao de B em A
*/
complexo Subtracao(int tamanho, complexo matrizA[100][100], complexo matrizB[100][100], complexo matrizR[100][100]);




//-------------------------PRODUTO Escalar

///Testa a funcao de produto escalar.
void teste_produto_escalar();

/**
*Calcula o produto escalar entre os vetores A e B e armazena o resultado no vetor disponibilizado Resultado.
* 
* @param[in] tamanho dos vetores
* @param[in] Vetor A
* @param[in] Vetor B
* @param[in] Resultado Vetor pre alocado na memoria para receber o resultado
* @param[out] Produto entre A e B
*/

complexo Produto_escalar(int tamanho,complexo ma[100], complexo mb[100]);





//-------------------------PRODUTO MATRICIAL

///Testa a funcao de produto matricial.
void teste_produto_matricial();

/**
* Calcula o produto entre as matrizes A e B e armazena o resultado na matriz disponibilizada Resultado.
* 
* @param[in] tamanho das matrizes
* @param[in] A
* @param[in] B
* @param[in] Resultado Matriz pre alocada na memoria para receber o resultado.
* @param[out] Produto entre A e B
*/
complexo Produto_matricial(int tamanho, complexo ma[100][100], complexo mb[100][100], complexo ans[100][100]);




//-------------------------PRODUTO COMPLEXO

///Teste da funcao Produto complexo
void teste_produto_complexo();

/**
* Calcula o produto entre os numeros complexos A e B.
* 
* @param[in] Numero A
* @param[in] Numero B
* @param[out] Produto entre A e B
*/
complexo produto_complexo(complexo ma, complexo na);





//-------------------------SVD
///Teste da funcao svd usando a biblioteca gsl
void Teste_calc_svd();

void Aux_teste_svd(int M, int N, complexo A[100][100]);
/**
 * @brief calcula a decomposicao do valor singular (svd) da matriz dada a[M][N], sendo que M = N.
 * @param[in] tamanho 
 * @param[in] a 
 * @param[in]
 * @param[in]
 * @return matrizes u, v e s
 */
void Calc_svd(int M, int N, complexo Au[100][100], complexo V[100][100], complexo S[100]);





//-------------------------TESTE GERAL

///Integra todos os testes das funcoes para serem executados de uma so vez.
void Teste_geral();
