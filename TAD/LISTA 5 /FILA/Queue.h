#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode {
    int info;
    struct QueueNode *prox;
} QueueNode;

typedef struct {
    QueueNode *inicio;
    QueueNode *fim;
} Queue;

void inicializar(Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int isEmpty(Queue *q) {
    return q->inicio == NULL;
}

void Enqueue(Queue *q, int valor) {
    QueueNode *novo = malloc(sizeof(QueueNode));
    novo->info = valor;
    novo->prox = NULL;
    if (isEmpty(q)) {
        q->inicio = novo;
    } else {
        q->fim->prox = novo;
    }
    q->fim = novo;
}

int Dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Nao eh possivel desenfileirar.\n");
        exit(1);
    }
    QueueNode *aux = q->inicio;
    int valor = aux->info;
    q->inicio = aux->prox;
    if (q->inicio == NULL) {
        q->fim = NULL;
    }
    free(aux);
    return valor;
}

int head(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Nenhum elemento.\n");
        exit(1);
    }
    return q->inicio->info;
}
