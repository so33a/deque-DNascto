#include <stdio.h>
#include "fila.c"

int main () {
    FILA alunos = novaFila();
    inserirNoFinal(alunos, 9);
    inserirNoFinal(alunos, 8);
    inserirNoFinal(alunos, 3);
    inserirNoFinal(alunos, 10);

    imprimirFila(alunos);

    while(!filaVazia(alunos))
        printf ("removido: %d \n", removerDoComeco(alunos));


    inserirNoFinal(alunos, 10);
    inserirNoFinal(alunos, 32);

    imprimirFila(alunos);

    destroiFila(alunos);

    printf("Nova Fila\n\n");

    alunos = novaFila();
    inserirNoComeco(alunos, 1);
    inserirNoComeco(alunos, 5);
    inserirNoComeco(alunos, 9);
    inserirNoComeco(alunos, 7);
    inserirNoComeco(alunos, 3);

    imprimirFila(alunos);

    while(!filaVazia(alunos))
        printf ("removido: %d \n", removerDofim(alunos));

    inserirNoComeco(alunos, 12);
    inserirNoComeco(alunos, 45);
    inserirNoComeco(alunos, 78);

    imprimirFila(alunos);
    return 0;
}
