#ifndef FILA_H
#define FILA_H

typedef struct node * link;
struct node {
  int item;
  link next;
};

typedef struct {
  link primeiro;
  link ultimo;
} * FILA;

link novoNo(int item, link next);
FILA novaFila();
void inserirNoComeco(FILA fila, int valor);
void inserirNoFinal(FILA f, int valor);
int removerDoComeco(FILA f);
int removerDofim(FILA fila);
void imprimirFila(FILA f);
void destroiFila(FILA f);
int filaVazia(FILA f);

#endif
