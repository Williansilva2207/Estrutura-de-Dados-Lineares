#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode {
    char info[100];
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

void Enqueue(Queue *q, char valor[100]) {
    QueueNode *novo = malloc(sizeof(QueueNode));
    strcpy(novo->info, valor);
    novo->prox = NULL;
    if (isEmpty(q)) {
        q->inicio = novo;
    } else {
        q->fim->prox = novo;
    }
    q->fim = novo;
}

char *Dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Nao eh possivel desenfileirar.\n");
        exit(1);
    }
    QueueNode *aux = q->inicio;
    char *valor = (char*)malloc(sizeof(char)*100);
    q->inicio = aux->prox;
    if (q->inicio == NULL) {
        q->fim = NULL;
    }
    strcpy(valor, aux->info);
    free(aux);
    return valor;
}

char *head(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Nenhum elemento.\n");
        exit(1);
    }
    return q->inicio->info;
}

void cancel(Queue *q, char valor[100]){
    QueueNode *aux;
    if(strcmp(*aux->info, valor) == 0){
        q->inicio = q->inicio->prox;
    }
    else{
        while(aux != NULL && strcmp(aux->info, valor) != 0){
            aux = aux->prox;
        }
        if(strcmp(aux->info,valor) == 0){
            aux = &aux->info;
            q->inicio->prox = aux;
                   
        }
    }
}

void list(Queue f){
    QueueNode* aux;
    if(isEmpty(&f)==1){
        printf("Fila vazia!\n");
    }
    else{
        aux = f.inicio;
        while(aux != NULL){
            printf("%s \n", aux->info);
            aux = aux->prox;
        }
    }
}