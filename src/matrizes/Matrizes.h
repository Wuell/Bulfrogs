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


typedef struct bfgs_matrix{

    complexo *data;
    int M;
    int N;
    int is_alloc;

} bfgs_matrix;

typedef struct bfgs_vector{

    complexo *data;
    int len;
    int is_alloc;

} bfgs_vector;

//--------------------------matrix handle
bfgs_matrix matrix_alloc(int M, int N);

void matrix_free(bfgs_matrix m);

complexo matrix_get(bfgs_matrix m, int M, int N);

void matrix_change(bfgs_matrix m, int M, int N, complexo v);

void matrix_print(bfgs_matrix ma);

//--------------------------vector handle
bfgs_vector vector_alloc(int len);

void vector_free(bfgs_vector v);

complexo vector_get(bfgs_vector v, int M);

void vector_change(bfgs_vector v, int M, complexo a);

void vector_print(bfgs_vector v);


//-------------------------Miscellaneous

//-------------------------PRINTERS

/// @brief Imprime a modificacao das matrizes A e B e o resultado MOD de alguma operacao.
/// @param tamanho das matrizes
/// @param A matriz A
/// @param B matriz B
/// @param MOD (matrizes A e B ja operadas)
void matrix_op_print(bfgs_matrix ma, bfgs_matrix mb, bfgs_matrix ans); //Função de printar para operação de duas matrizes

/// @brief Imprime a matriz A e o resultado MOD de alguma modificacao.
/// @param Tamanho da matriz
/// @param A matriz A
/// @param MOD (matriz A ja operada)
void matrix_mod_print(bfgs_matrix m, bfgs_matrix ans);


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

void Transposta(bfgs_matrix ma, bfgs_matrix ans);




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
void Conjugada(bfgs_matrix m, bfgs_matrix mc);




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
void Hermitiana(bfgs_matrix m, bfgs_matrix h);





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
void Soma(bfgs_matrix ma, bfgs_matrix mb, bfgs_matrix ans);




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
void Subtracao(bfgs_matrix ma, bfgs_matrix mb, bfgs_matrix ans);




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

complexo Produto_escalar(bfgs_vector va, bfgs_vector vb);





//-------------------------PRODUTO MATRICIAL

///Testa a funcao de produto matricial.
void Teste_produto_matricial(bfgs_matrix ma , bfgs_matrix mb , bfgs_matrix ans);

/**
* Calcula o produto entre as matrizes A e B e armazena o resultado na matriz disponibilizada Resultado.
* 
* @param[in] tamanho das matrizes
* @param[in] A
* @param[in] B
* @param[in] Resultado Matriz pre alocada na memoria para receber o resultado.
* @param[out] Produto entre A e B
*/
void Produto_matricial(bfgs_matrix ma , bfgs_matrix mb , bfgs_matrix ans);




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
/**
 * Se trata de uma funcao que conta com uma serie de exemplos de matrizes a serem testadas, sendo dependencia da funcao auxiliar
 * (Aux_teste_svd), dessa forma e uma funcao apenas de armazenamentos de casos teste, ou seja, ela nao realiza nem uma operacao diretamente, sendo
 * necessario outras funcoes.
*/
void Teste_calc_svd();

/**
 * Funcao auxiliar para testes da funcao Calc_svd, esta funcao recebe os parametros necessarios para realizar a operacao de SVD. 
 * Uma vez tendo os parametros, os parametros restantes sao criados e ocorre a chamada da funcao principal de calculo. Logo apos isso 
 * as saidas sao guardadas e sao impressas.
 * @param M Numero de linhas da matriz A.
 * @param N Numero de colunas da matriz A.
 * @param A Matriz A.
 */

void Aux_teste_svd(bfgs_matrix A);

/**
 * Calcula a decomposicao do valor singular (SVD) da matriz dada A[M][N]. Que em sintese e transformar uma matriz A em 3 outras, de 
 * acordo com a formula A = U V S de acordo com o algoritmo de  Golub Reinsch.
 * @remark Nao ha suporte a matrizes com parte imaginaria, apenas reais.
 * @remark Sendo que necessariamente M >= N.
 * @remark Ultilizando a funcao gsl_linalg_SV_decomp da Gnu Scientific Library.
 * @param[in] M Numero de linhas da matriz A.
 * @param[in] N Numero de colunas da matriz A.
 * @param[in] Au Matriz A em que vai ser guardado a matrix U de saida.
 * @param[out] V Matriz V em que vai ser guardado o resultado dos calculos de V.
 * @param[out] S Vetor S em que vai ser guardado o valor da diagonal da matriz S.
 * @return matrizes U, V e S preenchidas com os valores correspondentes a operacao.
 */
void Calc_svd(bfgs_matrix Au, bfgs_matrix V, bfgs_vector S);


//-------------------------TESTE GERAL

///Integra todos os testes das funcoes para serem executados de uma so vez.
void Teste_geral();

#endif