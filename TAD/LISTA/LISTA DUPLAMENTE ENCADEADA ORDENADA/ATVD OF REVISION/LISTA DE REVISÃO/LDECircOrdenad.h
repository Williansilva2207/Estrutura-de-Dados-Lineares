#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct ldenode
{
    struct ldenode *ant;
    int valor;
    struct ldenode *prox;
}LDENode; 

typedef struct ldecirc{
    LDENode *inicio;
    LDENode *fim;
    int qtd;
}LDECirc;

void start(LDECirc *list){
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

LDENode *makeNo(int valor){
    LDENode* novo = (LDENode*) malloc(sizeof(LDENode));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->valor = valor;
    return novo; 
}

void insertion(LDECirc *list, int valor){
    LDENode *novo;
    
    if(isEmpty(*list) == TRUE){
        novo = makeNo(valor);
        list->inicio = novo;
        list->fim = novo;
        list->qtd = 1;
        novo->prox = novo;
        novo->ant = novo;
    }
    else if(valor == list->inicio->valor){
        printf("Valor repetido\n");
    }else if(valor < list->inicio->valor){
        novo = makeNo(valor);
        novo->prox = list->inicio;
        list->inicio->ant = novo;
        list->inicio = novo;
        list->inicio->ant = list->fim;
        list->fim->prox = list->inicio;
        list->qtd ++; 
    }else if(valor == list->fim->valor){
        printf("Valor repetido\n");

    }else if(valor > list->fim->valor){
        novo= makeNo(valor);
        list->fim->prox = novo;
        novo->ant = list->fim;
        list->fim = novo;
        list->fim->prox = list->inicio;
        list->inicio->ant = list->fim;
        list->qtd ++;
    }else{
        while(TRUE){
            LDENode *aux;
            LDENode *bef;
            aux = list->inicio->prox;
            if(valor == aux->valor){
                printf("Valor repetido.");
                return; 
            }else if(valor< aux->valor){
                novo = makeNo(valor);
                bef = aux->ant;
                bef->prox = novo;
                novo->ant = bef;
                novo->prox = aux;
                aux->ant = novo;
                list->qtd ++;
                return;
            }else{
                aux = aux->prox;
            }
        }
    }
}
