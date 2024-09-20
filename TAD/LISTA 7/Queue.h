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
c
}

char *head(Queue *q) {
    if (isEmpty(q)) {
        printf("Fila vazia. Nenhum elemento.\n");
        exit(1);
    }
    return q->inicio->info;
}

void cancel(Queue *f, char valor[100]){
    QueueNode *atual, *anterior;
    if(isEmpty(&f)==1){
        printf("FILA VAZIA. \n");
    }
    else if(f->inicio = f->fim){//tem um nó
        if(strcmp(f->inicio->info, valor)==0){
            free(f->inicio);
            f->inicio = NULL;
            f->fim = NULL;
        }else{
            printf("Valor não encontrado! \n");
        }
    }else{//mais de um nó
        if(strcmp(f->inicio->info, valor)==0){ //remoção do inicio
            atual = f->inicio;
            f->inicio = f->inicio->prox; //ou f->inicio = aux->prox
            free(atual);
            printf("Cancelamento efetuado!");
        }else{
            atual = f->inicio->prox;
            anterior = f->inicio;
            while(atual != NULL){
                if(strcmp(atual->info, valor)==0){//achei
                    anterior->prox = atual->prox;
                    if(atual->prox == NULL){
                        f->fim = anterior;
                    }
                    free(atual);
                    pritnf("Cancelamento efetuado! \n");
                    return;
                }else{
                    anterior = atual;
                    atual = atual->prox;
                }
            }
            printf("Arquivo não encontrado! \n");
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
            //aux pega o endereço do aux->prox, ou seja, ele não vai mudar o valor, ele vai ver o que está naquele endereço meu lindo.
        }
    }
}