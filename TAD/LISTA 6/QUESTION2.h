#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct queue {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Queue;

void inicializar(Queue *q) {
    q->inicio = 0;
    q->fim = -1;
    q->tamanho = 0;
}

int isEmpty(Queue *q) {
    return q->tamanho == 0;
}

int isFull(Queue *q) {
    return q->tamanho == MAX;
}

void Enqueue(Queue *q, int valor) {
    if (isFull(q)) {
        printf("Fila cheia. Não é possível enfileirar.\n");
        return;
    }
    q->fim = (q->fim + 1) % MAX;
    q->dados[q->fim] = valor;
    q->tamanho++;
}

int Dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Não é possível desenfileirar.\n");
        exit(1);
    }
    int valor = q->dados[q->inicio];
    q->inicio = (q->inicio + 1) % MAX;
    q->tamanho--;
    return valor;
}

int head(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Nenhum elemento no início.\n");
        exit(1);
    }
    return q->dados[q->inicio];
}
