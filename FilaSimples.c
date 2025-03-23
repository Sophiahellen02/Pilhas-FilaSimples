#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int frente, tras;
} Fila;

void inicializar(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

int estaVazia(Fila *f) {
    return f->frente > f->tras;
}

int estaCheia(Fila *f) {
    return f->tras == MAX - 1;
}

int enfileirar(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia!\n");
        return 0;
    }
    f->itens[++(f->tras)] = valor;
    return 1;
}

int desenfileirar(Fila *f, int *valor) {
    if (estaVazia(f)) {
        printf("\nFila vazia!\n");
        return 0;
    }
    *valor = f->itens[(f->frente)++];
    return 1;
}

int frente(Fila *f, int *valor) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return 0;
    }
    *valor = f->itens[f->frente];
    return 1;
}

int main() {
    Fila f;
    int valor;

    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    if (frente(&f, &valor)) {
        printf("Frente da fila: %d\n\n", valor);
    }

    while (desenfileirar(&f, &valor)) {
        printf("Desenfileirado: %d\n", valor);
    }

    return 0;
}