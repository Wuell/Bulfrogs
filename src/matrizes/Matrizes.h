#ifndef MATRIZES_H
#define MATRIZES_H
///@file Matrizes.h

/// @brief Estrutura de um numero complexo, guardado em duas variaveis, real e a imaginaria, que ligadas representam um complexo.
struct complexo // Define os complexos
{
    /// @brief Parte real
    double re;
    /// @brief Parte imaginaria
    double im;
};

/// @brief Representacao usual dos numeros complexos.
typedef struct complexo complexo;

/**
 * @brief Matriz de numeros complexos que armazena os itens da matriz como vetor e o acesso como matriz e injecao de dados sera feito
 * atraves da funcao matriz_change().
 *
 */
typedef struct bfgs_matrix
{

    /// @brief Ponteiro de complexos que ira armazenar os dados da matriz como um vetor unidimensional.
    complexo *data;
    /// @brief Numero de linhas da matriz
    int M;
    /// @brief Numero de colunas da matriz
    int N;
    /// @brief Variavel para controlar a allocacao da matriz
    int is_alloc;

} bfgs_matrix;

/**
 * @brief Vetor de complexos com variaveis de auxilio para o manuseio.
 *
 */
typedef struct bfgs_vector
{

    /// @brief Ponteiro de complexos que ira armazenar os dados
    complexo *data;
    /// @brief Tamanho do vetor
    int len;
    /// @brief Variavel para controlar a alocacao do vetor
    int is_alloc;

} bfgs_vector;
/**
 * @brief Vetor de inteiros para facilitar manuseio desse vetor.
 * 
 */
typedef struct bfgs_int_vector{

    /// @brief Vetor que ira armazenar os dados
    int* data; 
    /// @brief Tamanho do vetor
    int  len;

} bfgs_int_vector;
//----------------------------------------------------------------------------------------------------------matrix handle

/**
 * @brief Cria uma matriz do tipo bgfs, inicia a array de dados do bfgs_matrix.data alocando o tamanho desejado na memoria,
 * retornando o matriz alocado, passando o pointer para o vetor bfgs originador.
 * @remark Deve ser usado da seguinte forma: bfgs_matrix nome_da_matriz = matrix_alloc(numero de linhas M, numero de colunas N);.
 * @param M Numero de linhas
 * @param N Numero de colunas
 * @return bfgs_matrix
 */
bfgs_matrix matrix_alloc(int M, int N);

/**
 * @brief Libera da memoria a matriz m, previamente alocado.
 *
 * @param v Matriz para ser liberado da memoria.
 */
void matrix_free(bfgs_matrix m);

/**
 * @brief Retorna o numero complexo localizado na posicao m[M][N] do vetor.
 *
 * @param v Matriz o qual ira ser acessada
 * @param M Numero de linhas
 * @param N Numero de colunas
 * @return complexo Numero complexo ocupante da posicao m[M][N]
 */
complexo matrix_get(bfgs_matrix m, int M, int N);

/**
 * @brief Substitui o elemento da celula mMXmN na matriz m pelo numero complexo a, em outras palavras m[M][N] = a.
 *
 * @param m Matriz que a qual sera alterada
 * @param M Linha do elemento
 * @param N Coluna do elemento
 * @param v Numero que ira assumir a posicao m[M][N]
 */
void matrix_change(bfgs_matrix m, int M, int N, complexo v);

/**
 * @brief Imprime a matriz ma no terminal.
 *
 * @param ma Matriz que sera impressa
 */
void matrix_print(bfgs_matrix ma);

//---------------------------------------------------------------------------------------------------------------vector handle
/**
 * @brief Cria um vetor do tipo bgfs, inicia a array de dados do bfgs_vector.data alocando o tamanho desejado na memoria,
 * retornando o vetor alocado, passando o pointer para o vetor bfgs originador.
 * @remark Deve ser usado da seguinte forma: bfgs_vector nome_do_vetor = vector_alloc(tamanho desejado);.
 *
 * @param len Tamanho do vetor
 * @return bfgs_vector vetor com pointer ja alocado no tamanho desejado.
 */
bfgs_vector vector_alloc(int len);

/**
 * @brief Libera da memoria o vetor V dado como argumento, previamente alocado.
 *
 * @param v Vetor para ser liberado da memoria.
 */
void vector_free(bfgs_vector v);

/**
 * @brief Retorna o numero complexo localizado na posicao V[m] do vetor.
 *
 * @param v Vetor o qual ira ser acessado
 * @param M posicao desejada.
 * @return complexo Numero complexo ocupante da posicao.
 */
complexo vector_get(bfgs_vector v, int M);

/**
 * @brief Substitui o elemento da celula M no vetor v pelo numero complexo a , em outras palavras v[m] = a.
 *
 * @param v vetor a ser alterado
 * @param M celula a ser alterada
 * @param a numero que vai ser posto na posicao v[m]
 */
void vector_change(bfgs_vector v, int M, complexo a);

/**
 * @brief Imprime o vetor v no terminal.
 *
 * @param v vetor a ser impresso no terminal.
 */
void vector_print(bfgs_vector v);

//-------------------------------------------------------------------------Miscellaneous
/**
 * @brief Aloca o vetor de tamanho (len) e retorna o ponteiro para a array.
 * 
 * @param len tamanho do vetor
 * @return ponteiro para o vetor 
 */
bfgs_int_vector int_vector_alloc(int len);

char* char_vector_alloc(int len);

bfgs_matrix vec2matsqr(bfgs_vector v);
//-------------------------------------------------------------------------PRINTERS

/// @brief Imprime a modificacao das matrizes A e B e o resultado de alguma operacao, de forma padrao.
/// @param ma matriz A
/// @param Ma matriz B
/// @param ans (matrizes A e B ja operadas)
void matrix_op_print(bfgs_matrix ma, bfgs_matrix mb, bfgs_matrix ans);

/// @brief Imprime a matriz A e o resultado MOD de alguma modificacao, de forma padrao.
/// @param[in] m matriz antes da modificacao
/// @param[in] ans matriz m apos operacao
void matrix_mod_print(bfgs_matrix m, bfgs_matrix ans);

//-------------------------TRANSPOSTA

/// @brief Testa a funcao transposta.
void teste_transposta();

/**
 *Calcula a transposta da matriz A e armazena na matriz disponibilizada.
 *
 * @param[in] Ma
 * @return Transposta de A
 */
bfgs_matrix Transposta(bfgs_matrix ma);

//-------------------------CONJUGADA

/// @brief Testa a funcao conjugada.
void teste_conjugada();

/**
 *Calcula a conjugada da matriz A e armazena na matriz disponibilizada.
 *
 * @param[in] A
 * @param[out] Conjugada de A
 */
void Conjugada(bfgs_matrix m, bfgs_matrix mc);

//-------------------------HERMITIANA

/// @brief Testa a funcao de hermitiana.
void teste_hermitiana();

/**
 *Calcula a hermitiana da matriz A.
 *
 * @param[in]  A
 * @return Hermitiana de A
 */
bfgs_matrix Hermitiana(bfgs_matrix m);

//-------------------------SOMA

/// @brief Testa a funcao de soma.
void teste_soma();

/**
 *Calcula a soma entre as matrizes A e B e armazena o resultado na matriz disponibilizada Resultado.
 *
 * @param[in] A
 * @param[in] B
 * @return O resultado de A + B
 */
bfgs_matrix Soma(bfgs_matrix ma, bfgs_matrix mb);

//-------------------------SUBTRAÇÃO

/// @brief Testa a funcao de subtracao.
void teste_subtracao();

/**
 *Calcula a subtracao entre as matrizes A e B e armazena o resultado na matriz disponibilizada Resultado.
 *
 * @param[in] A
 * @param[in] B
 * @param[out] Subtracao de B em A
 */
void Subtracao(bfgs_matrix ma, bfgs_matrix mb, bfgs_matrix ans);

//-------------------------PRODUTO Escalar

/// Testa a funcao de produto escalar.
void teste_produto_escalar();

/**
 *Calcula o produto escalar entre os vetores A e B.
 *
 * @param[in] Vetor A
 * @param[in] Vetor B
 * @return Produto entre A e B
 */
complexo Produto_escalar(bfgs_vector va, bfgs_vector vb);

//-------------------------PRODUTO MATRICIAL

/// Testa a funcao de produto matricial.
void teste_produto_matricial();

/**
 * Calcula o produto entre as matrizes A e B.
 *
 * @param[in] A
 * @param[in] B
 * @return Resultado da multiplicação
 */
bfgs_matrix Produto_matricial(bfgs_matrix ma, bfgs_matrix mb);

//-------------------------PRODUTO COMPLEXO

/// Teste da funcao Produto complexo com casos teste.
void teste_produto_complexo();

/**
 * Calcula o produto entre os numeros complexos A e B e armazena os dados na variavel que chamou.
 *
 * @param[in] Numero A
 * @param[in] Numero B
 * @return Produto entre A e B
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
 * @param[in] Au Matriz A em que esta a matrix a ser operada, e vai ser guardado a matrix U de saida.
 * @param[out] V Matriz V em que vai ser guardado o resultado dos calculos de V.
 * @param[out] S Vetor S em que vai ser guardado o valor da diagonal da matriz S.
 * @return matrizes U, V e S preenchidas com os valores correspondentes a operacao.
 */
void Calc_svd(bfgs_matrix Au, bfgs_matrix V, bfgs_vector S);

/**
 * @brief Calcula a inversa da matriz bfgs dada e retorna em mi.
 * @param m matriz que sera operada
 * @return sera retornada a inversa da matriz m e sera guardada na matriz bfgs que chamou a funcao
 */
bfgs_matrix inversa(bfgs_matrix m);

//-------------------------TESTE GERAL

/// Integra todos os testes das funcoes para serem executados de uma so vez.
void Teste_geral();
/**
 * brief Calcula a inversa da matriz bfgs dada e retorna em mi.
 * @param m matriz que sera operada
 * @return sera retornada a inversa da matriz m e sera guardada na matriz bfgs que chamou a funcao
 */
bfgs_matrix inversa(bfgs_matrix m);

//-------------------------TESTE GERAL

/// Integra todos os testes das funcoes para serem executados de uma so vez.
void Teste_geral();

#endif