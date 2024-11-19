#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
 
typedef struct ldenode{
    struct ldenode *prox;
    int info;
    
}LDENode;

typedef struct ldeenca{
    LDENode *inicio;
    LDENode *fim;
    int qtd;
}LDEEnca;

void inicializar(LDEEnca *list){
    list->inicio = NULL;
    list->fim = NULL;
    list->qtd = 0;
}

int isEmpty(LDEEnca list){
    if(list.qtd == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

void inserir(LDEEnca *list, int valor){
    LDENode *novo = (LDENode*) malloc(sizeof(LDENode));
    novo->prox = NULL;
    novo->info = valor;
    if(isEmpty(*list)==TRUE){
        list->inicio = novo;
        list->fim = novo;
        list->qtd = 1;
        list->fim->prox = list->inicio;
    }else if(valor < list->inicio->info){
        novo->prox = list->inicio;
        list->inicio = novo;
        list->fim->prox = list->inicio;
        list->qtd ++;
    }else if(valor > list->fim->info){
        list->fim->prox = novo;
        novo->prox = list->inicio;
        list->fim = novo;
        list->qtd ++;
    }else{
        LDENode *aux;
        LDENode *ant;
        aux = list->inicio->prox;
        ant = list->inicio;
        while(TRUE){
            if(valor <= aux->info){
                novo->prox = aux;
                ant->prox = novo;
                list->qtd ++;
                return;
            }else{
                ant = ant->prox;
                aux = aux->prox;
            }
        }
    }
}