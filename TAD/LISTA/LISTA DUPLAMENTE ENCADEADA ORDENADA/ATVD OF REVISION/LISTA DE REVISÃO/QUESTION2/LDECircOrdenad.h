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
    LDENode *incio;
    LDENode *fim;
    int qtd;
}LDECirc;

void inicializar(LDECirc *list){
    list->incio = NULL;
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

LDENode *criarNo( int valor){
    LDENode *novo = (LDENode*) malloc(sizeof(LDENode));
    novo->ant = NULL;
    novo->prox = NULL;
    novo->info = valor;
    return novo;
}

void inserir(LDECirc *list, int valor){
    LDENode *novo;
    if(isEmpty(*list) == TRUE){
        novo = criarNo(valor);
        list->incio = novo;
        list->fim = novo;
        novo->ant = novo;
        novo->prox = novo;
        list->qtd = 1;

    }else if(valor == list->incio->info){
        printf("Valor repetido no entra, oh right! \n");
    }else if(valor < list->incio->info){
        novo = criarNo(valor);
        novo->prox = list->incio;
        list->incio->ant = novo;
        list->incio = novo;
        list->incio->ant = list->fim;
        list->fim->prox = list->incio;
        list->qtd ++;
    }else if(valor == list->fim->info){
        printf("Valor repetido no entra, oh right! \n");
    
    }else if(valor > list->fim->info){
        novo = criarNo(valor);
        novo->ant = list->fim;
        list->fim->prox = novo;
        list->fim = novo;
        list->fim->prox = list->incio;
        list->incio->ant = list->fim;
        list->qtd ++;
    }else{
        LDENode *aux;
        LDENode *bef;
        aux = list->incio->prox;
        while(TRUE){
            if(valor == aux->info){
                printf("Valor repetido no entra, oh right! \n");
                return;
            }else if(valor < aux->info){
                novo = criarNo(valor);
                bef= aux->ant;
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