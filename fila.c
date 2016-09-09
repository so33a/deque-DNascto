#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

link novoNo(int item, link next) {
    link t = malloc(sizeof *t);
    if (t == NULL) {
        printf ("Erro no malloc \n");
        exit(-1);
    }
    t->item = item;
    t->next = next;
    return t;
}

FILA novaFila() {
    FILA f = malloc(sizeof *f);
    f->ultimo = f->primeiro = NULL;
    return f;
}

void inserirNoFinal(FILA f, int valor) {
    if(f->primeiro == NULL) {
        f->primeiro = f->ultimo = novoNo(valor, NULL);
    } else {
        f->ultimo->next = novoNo(valor, NULL);
        f->ultimo = f->ultimo->next;
    }
}

void inserirNoComeco(FILA fila, int valor){
    if(fila->ultimo == NULL){
        fila->ultimo = fila->primeiro = novoNo(valor, NULL);
    }else{
        fila->primeiro = novoNo(valor, fila->primeiro);
    }
}

int removerDofim(FILA fila){
    link aux = fila->primeiro;
    int item = fila->ultimo->item;
    if(filaVazia(fila)) {
        printf ("Erro, a fila esta vazia\n");
        return 0;
    }
    while(aux->next != fila->ultimo){
        aux = aux->next;
    }

    fila->ultimo = aux;
    free(aux->next);
    aux->next = NULL;
    if(aux == fila->primeiro){
        fila->primeiro = NULL;
    }

    return item;
}

int removerDoComeco(FILA f) {
    int x;
    link t;
    if(filaVazia(f)) {
        printf ("Erro, a fila esta vazia\n");
        return 0;
    }

    x = f->primeiro->item;
    t = f->primeiro;
    f->primeiro = f->primeiro->next;

    if(f->primeiro == NULL)
        f->ultimo = NULL;

    free(t);
    return x;
}
int filaVazia(FILA f) {
    return ((f->ultimo == NULL) || (f->primeiro == NULL));
}
void imprimirFila(FILA f) {
    link t;
    for(t = f->primeiro; t != NULL; t = t->next)
        printf ("%d ", t->item);
    printf ("\n");
}
void destroiFila(FILA f) {
    while (!filaVazia(f))
        removerDoComeco(f);
    free(f);
}

