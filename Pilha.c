#include <stdio.h>
#include <stdlib.h>

// Tamanho máximo da pilha
#define MAX 100

// Pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Verifica se a pilha está cheia
int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Empilha um valor
int empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Pilha cheia!\n");
        return 0;
    }
    p->itens[++(p->topo)] = valor;
    return 1;
}

// Desempilha um valor
int desempilhar(Pilha *p, int *valor) {
    if (estaVazia(p)) {
        printf("\nPilha vazia!\n");
        return 0;
    }
    *valor = p->itens[(p->topo)--];
    return 1;
}

// Retorna o valor do topo da pilha
int topo(Pilha *p, int *valor) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return 0;
    }
    *valor = p->itens[p->topo];
    return 1;
}

// Função principal
int main() {
    Pilha p;
    int valor;

    inicializar(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);
    empilhar(&p, 40);

    if (topo(&p, &valor)) {
        printf("Topo da pilha: %d\n\n", valor);
    }

    while (desempilhar(&p, &valor)) {
        printf("Desempilhado: %d\n", valor);
    }

    return 0;
}