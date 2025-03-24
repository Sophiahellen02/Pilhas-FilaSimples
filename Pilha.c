#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// tamanho máximo da pilha
#define MAX 5

// estrutura da pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Função para verificar se a pilha está cheia
int estaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Função para empilhar um valor
int empilhar(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Pilha cheia! Não é possível empilhar o valor %d.\n", valor);
        return 0;
    }
    p->itens[++(p->topo)] = valor;
    printf("Valor %d empilhado com sucesso!\n", valor);
    return 1;
}

// Função para desempilhar um valor
int desempilhar(Pilha *p, int *valor) {
    if (estaVazia(p)) {
        printf("Pilha vazia! Não há elementos para desempilhar.\n");
        return 0;
    }
    *valor = p->itens[(p->topo)--];
    printf("Valor %d desempilhado com sucesso!\n", *valor);
    return 1;
}

// Função para visualizar o valor do topo da pilha
int verTopo(Pilha *p, int *valor) {
    if (estaVazia(p)) {
        printf("Pilha vazia! Não há elemento no topo.\n");
        return 0;
    }
    *valor = p->itens[p->topo];
    printf("Valor no topo da pilha: %d\n", *valor);
    return 1;
}

// Função principal
int main() {
    setlocale(LC_ALL,"Portuguese");

    Pilha p;
    int valor;

    // Inicializando a pilha
    inicializar(&p);

    // Operações de exemplo
    printf("\n=== Operações de Pilha ===\n");

    // Operação de PUSH (empilhar)
    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);
    empilhar(&p, 40);
    empilhar(&p, 50);  // aqui a pilha fica cheia
    empilhar(&p, 60);  // tentativa de empilhar com a pilha cheia

    // Operação de PEEK (ver o topo)
    verTopo(&p, &valor);

    // Operação de POP (desempilhar)
    desempilhar(&p, &valor);
    desempilhar(&p, &valor);

    // Verificando o topo novamente
    verTopo(&p, &valor);

    // Desempilhando todos os elementos restantes
    while (desempilhar(&p, &valor)) {}


    return 0;
}