#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

int empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Pilha cheia!\n");
        return 0;
    }
    p->itens[++(p->topo)] = valor;
    return 1;
}

int desempilhar(Pilha *p, int *valor) {
    if (estaVazia(p)) {
        printf("\nPilha vazia!\n");
        return 0;
    }
    *valor = p->itens[(p->topo)--];
    return 1;
}

int topo(Pilha *p, int *valor) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return 0;
    }
    *valor = p->itens[p->topo];
    return 1;
}

int main() {
    Pilha p;
    int valor;

    inicializar(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    if (topo(&p, &valor)) {
        printf("Topo da pilha: %d\n\n", valor);
    }

    while (desempilhar(&p, &valor)) {
        printf("Desempilhado: %d\n", valor);
    }

    return 0;
}