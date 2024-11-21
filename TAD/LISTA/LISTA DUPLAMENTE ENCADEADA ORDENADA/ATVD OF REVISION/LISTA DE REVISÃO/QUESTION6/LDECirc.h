#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct ldenode{
    struct ldenode *ant;
    struct ldenode *prox;
    int info;
}LDENode;

typedef struct ldecirc{
    LDENode *inicio;
    LDENode *fim;
    int qtd;
}LDECirc;

void incializar(LDECirc *list){
    list->inicio = NULL;
    list->fim = NULL;
    list->qtd = 0;
}

int isEmpty(LDECirc list){
    if(list.qtd == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

LDENode *criarNo(int valor){
    LDENode *novo = (LDENode*) malloc(sizeof(LDENode));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->info = valor;
    return novo;
}

void inserirOrdenado(LDECirc *list, int valor){
    
    LDENode *novo;
    if(isEmpty(*list)==TRUE){
        novo = criarNo(valor);
        list->inicio = novo;
        list->fim = novo;
        novo->prox = novo;
        novo->ant = novo;
        list->qtd = 1;
    }else if(valor == list->inicio->info){
        printf("O numero ja existe.\n");
    }else if(valor < list->inicio->info){
        novo = criarNo(valor);
        novo->prox = list->inicio;
        list->inicio->ant = novo;
        list->inicio = novo;
        list->inicio->ant = list->fim;
        list->fim->prox = list->inicio;
        list->qtd++;
    }else if(valor == list->fim->info){
        printf("O numero ja existe.\n");
    }else if(valor > list->fim->info){
        novo = criarNo(valor);
        list->fim->prox = novo;
        novo->ant = list->fim;
        list->fim = novo;
        list->fim->prox = list->inicio;
        list->inicio->ant = list->fim;
        list->qtd++;
    }else{
        LDENode *before;
        LDENode *aux;
        aux = list->inicio->prox;
        while(TRUE){
            if(valor == aux->info){
                printf("O valor ja existe.\n");
                return;
            }else if(valor < aux->info){
                novo = criarNo(valor);
                before = aux->ant;
                novo->prox = aux;
                novo->ant = before;
                before->prox = novo;
                aux->ant = novo;
                list->qtd++;
                return;
            }else{
                aux = aux->prox;
            }
        }
    }
}