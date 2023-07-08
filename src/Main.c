#include <stdio.h>
#include "Matrizes.h"
#include "./pds/Pds_telecom.h"
///@file Main.c

int main()
{
    printf("=====Equipe====\n\nWellerson Nascimento, Matricula = 202206840045\n\nNestor Carmo, Matricula = 202206840052\n\n");
    printf("so pra ver se ta funfando\n\n");

    //Teste_geral();
    /*
    int cu[3] = {7,8,9};
    int cu2[3] = {1,2,3};
    bfgs_matrix a = matrix_alloc(3,3);
    for (int i = 0; i < a.M; i++){
        for (int j = 0; j < a.N; j++){
            matrix_change(a, i, j, (complexo) {cu[j] + i, cu2[i] + j});
        }
    }
    matrix_print(a);
    */
    bfgs_vector a = vector_alloc(2);
    vector_change(a, 0, (complexo) { 3, 5});
    vector_change(a, 1, (complexo) { 2, 3});
    //vector_change(a, 2, (complexo) { 4, 6});
    //vector_change(a, 3, (complexo) { 7, 8});

    bfgs_matrix mtst = matrix_alloc(2, 2);
    matrix_change(mtst, 0, 0, (complexo){-3,4});
    matrix_change(mtst, 0, 1, (complexo){5,-6});
    //matrix_change(mtst, 0, 2, (complexo){3,7});
    //matrix_change(mtst, 0, 3, (complexo){9,2});
    matrix_change(mtst, 1, 0, (complexo){4,7});
    matrix_change(mtst, 1, 1, (complexo){2,9});
    //matrix_change(mtst, 1, 2, (complexo){1,8});
    //matrix_change(mtst, 1, 3, (complexo){1,9});
    //matrix_change(mtst, 2, 2, (complexo){11,4});
    //matrix_change(mtst, 3, 0, (complexo){3,4});
    //matrix_change(mtst, 3, 1, (complexo){6,7});
    //matrix_change(mtst, 3, 2, (complexo){5,8});
    printf("mtst\n");
    matrix_print(mtst);

    bfgs_matrix a_m = vec2matsqr(a);

    bfgs_matrix cu = Produto_matricial(mtst, a_m);
    bfgs_vector casa = feq(a, cu);

    vector_print(casa);

    vector_free(a);
    vector_free(casa);
    matrix_free(a_m);
    matrix_free(mtst);
    matrix_free(cu);

    return (0);
}